#ifndef TASK0B_WORDSTATSERVICE_H
#define TASK0B_WORDSTATSERVICE_H
#include <regex>
#include <map>

using namespace std;

class WordStatService {

public:
    explicit WordStatService();
    ~WordStatService();
    void AddWord(const string &word);
    vector<pair<string, pair<int, double>> > GetDict();

private:
    map<string, pair<int, double>>* dict;
    int count_words = 0;

    static bool pred(const pair<string, pair<int, double>> &a, const pair<string, pair<int, double>> &b);
    vector<pair<string, pair<int, double>> > sort();
};


#endif //TASK0B_WORDSTATSERVICE_H
