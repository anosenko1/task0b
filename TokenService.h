#ifndef TASK0B_TOKENSERVICE_H
#define TASK0B_TOKENSERVICE_H
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#endif

class TokenService {

public:
    explicit TokenService(const string &line);
    bool getNextWord(string *word);
    void setNewLine(const string &line_new);

private:
    string line;
    vector<string> words;
    int words_count = 0;
    int word_number = 0;

    void FindAllWords();
};
