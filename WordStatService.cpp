#include "WordStatService.h"

WordStatService::WordStatService(){
    dict = new map<string, pair<int, double>>;
}

WordStatService::~WordStatService() {
    delete dict;
}

void WordStatService::AddWord(const string &word) {
    (*dict)[word].first += 1;
    count_words++;
}

vector<pair<string, pair<int, double>> > WordStatService::GetDict(){
    return sort();
}

bool WordStatService::pred(const pair<string, pair<int, double>> &a, const pair<string, pair<int, double>> &b) {
    if (a.second.first > b.second.first)
        return true;
    else if (a.second.first == b.second.first)
        return b.first > a.first;
    return false;
}


vector<pair<string, pair<int, double>> > WordStatService::sort() {
    vector<pair<string, pair<int, double>> > vec((*dict).begin(), (*dict).end());
    ::sort(vec.begin(), vec.end(), pred);
    for (int i = 0; i < count_words; ++i) {
        vec[i].second.second = (double)vec[i].second.first*100/count_words;
    }
    return vec;
}
