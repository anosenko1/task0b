#include <gtest/gtest.h>
#include "FileReader.h"
#include "TokenService.h"
#include "WordStatService.h"
#include <iostream>

// несуществующий файл
TEST(FileReaderTests, ConstructorTests){
    ASSERT_EXIT(FileReader file("bad_name.txt"), ::testing::ExitedWithCode(23), "");
}
// разбиение на строки
TEST(FileReaderTests, GetNextlineTests){
    FileReader file("input_test.txt");
    string next_line;
    ASSERT_TRUE(file.GetNextline(&next_line));
    ASSERT_EQ(next_line, "the first string");
    ASSERT_TRUE(file.GetNextline(&next_line));
    ASSERT_EQ(next_line, "the second string");
    ASSERT_TRUE(file.GetNextline(&next_line));
    ASSERT_EQ(next_line, "end");
    ASSERT_FALSE(file.GetNextline(&next_line));
}
// открыть другой файл
TEST(FileReaderTests, setNewFileTests){
    FileReader file("input_test.txt");
    file.setNewFile("input_test2.txt");
    string next_line;
    ASSERT_TRUE(file.GetNextline(&next_line));
    ASSERT_EQ(next_line, "the first string file 2");
    ASSERT_TRUE(file.GetNextline(&next_line));
    ASSERT_EQ(next_line, "the second string file 2");
    ASSERT_TRUE(file.GetNextline(&next_line));
    ASSERT_EQ(next_line, "end file 2");
    ASSERT_FALSE(file.GetNextline(&next_line));
}
// разбиение на слова
TEST(TokenServiceTests, getNextWordTests){
    TokenService tokenServiceTest("it's a simple line");
    string bufer_word;
    ASSERT_TRUE(tokenServiceTest.getNextWord(&bufer_word));
    ASSERT_EQ(bufer_word, "it's");
    ASSERT_TRUE(tokenServiceTest.getNextWord(&bufer_word));
    ASSERT_EQ(bufer_word, "a");
    ASSERT_TRUE(tokenServiceTest.getNextWord(&bufer_word));
    ASSERT_EQ(bufer_word, "simple");
    ASSERT_TRUE(tokenServiceTest.getNextWord(&bufer_word));
    ASSERT_EQ(bufer_word, "line");
    ASSERT_FALSE(tokenServiceTest.getNextWord(&bufer_word));
    tokenServiceTest.setNewLine(" ,.-/^*;:()!?\t\n");
    ASSERT_FALSE(tokenServiceTest.getNextWord(&bufer_word));
}
// обработать другую строку
TEST(TokenServiceTests, setNewLineTests){
    TokenService tokenServiceTest("it's a simple line");
    tokenServiceTest.setNewLine("new line");
    string bufer_word;
    ASSERT_TRUE(tokenServiceTest.getNextWord(&bufer_word));
    ASSERT_EQ(bufer_word, "new");
    ASSERT_TRUE(tokenServiceTest.getNextWord(&bufer_word));
    ASSERT_EQ(bufer_word, "line");
}
// правильное составление словаря
TEST(WordStatServiceTests, addWordTests){
    WordStatService statTest;
    statTest.AddWord("word");
    statTest.AddWord("one");
    statTest.AddWord("word");
    auto dict = statTest.GetDict();
    ASSERT_EQ(2, statTest.GetDict().size());
    ASSERT_EQ(dict[0].first, "word");
    ASSERT_EQ(dict[0].second.first, 2);
    ASSERT_EQ(dict[1].first, "one");
    ASSERT_EQ(dict[1].second.first, 1);
}
int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}