#include "TokenService.h"
#include <cstring>

TokenService::TokenService(const string &line) {
    this->line = line;
    FindAllWords();
}

bool TokenService::getNextWord(string *word) {
    if (words_count) {
        *word = words[word_number++];
        if (word_number == words_count)
            words_count = 0;
        return true;
    }
    return false;
}

void TokenService::FindAllWords() {
    char* l = const_cast<char *>(line.c_str());
    char *pch = strtok(l," ,.-/^*;:()!?\t\n");
    while (pch != nullptr)
    {
        words.emplace_back(pch);
        pch = strtok (nullptr, " ,.-");
    }
    words_count = words.size();
}

void TokenService::setNewLine(const string &line_new) {
    this->line = line_new;
    words.clear();
    words_count = word_number = 0;
    FindAllWords();
}
