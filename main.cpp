#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;
//перечитывать файл
//перименовать
class FileReader {
public:

    explicit FileReader(string file_name) {
        this->file_name = std::move(file_name);
        FileOpen();
    }

    ~FileReader(){
        FileClose();
    }

    //true если есть новая строка, запишет ее по адресу
    bool GetNextline(string *line) {
        if (file.is_open()) {
            if (getline(file, *line)) {
                return true;
            } else {
                FileClose();
                return false;
            }
        }
        cout << "file opening error" << endl;
        exit(0);
       // return false;
    }

private:
    string file_name;
    ifstream file;

    void FileOpen() {
        file.open(file_name);
        if (!file.is_open()) {
            cout << "file opening error" << endl;
            exit(0);
        }
    }

    void FileClose() {
        if (file.is_open())
            file.close();
    }
};

class TokenService {
public:
    explicit TokenService(const string &line) {
        this->line = line;
        FindAllWords();
    }

    bool GetNextWord(string *word) {
        if (words_count) {
            *word = words[word_number++];
            if (word_number == words_count)
                words_count = 0;
            return true;
        }
        return false;
    }

private:
    string line;
    vector<string> words;
    int words_count = 0;
    int word_number = 0;

    void FindAllWords() {
        char* l = const_cast<char *>(line.c_str());
        char *pch = strtok(l," ,.-");
        while (pch != nullptr)
        {
            words.emplace_back(pch);
            pch = strtok (nullptr, " ,.-");
        }
        words_count = words.size();
    }
};

class WordStatService {
public:

    explicit WordStatService(){
        dict = new map<string, pair<int, double>>;
    };

    ~WordStatService() {
        delete dict;
    }

    void AddWord(const string &word) {
        (*dict)[word].first += 1;
        count_words++;
    }

    vector<pair<string, pair<int, double>> > GetDict(){
        return sort();
    }

private:
    map<string, pair<int, double>>* dict;
    int count_words = 0;

    static bool pred(const pair<string, pair<int, double>> &a, const pair<string, pair<int, double>> &b) {
        if (a.second.first > b.second.first)
            return true;
        else if (a.second.first == b.second.first)
            return b.first > a.first;
        return false;
    }

    vector<pair<string, pair<int, double>> > sort() {
        vector<pair<string, pair<int, double>> > vec((*dict).begin(), (*dict).end());
        ::sort(vec.begin(), vec.end(), pred);
        for (int i = 0; i < count_words; ++i) {
            vec[i].second.second = (double)vec[i].second.first*100/count_words;
        }
        return vec;
    }
};

class ReportService {
public:
    explicit ReportService(string file_name, vector<pair<string, pair<int, double>> > dict) {
        this->file_name = move(file_name);
        this->dict = move(dict);
        FileOpen();
    }

    ~ReportService(){
        FileClose();
    }

    void Write(){
        file << "word,count,frequency" << endl;
        for (const auto& p : dict)
            file << p.first << ',' << p.second.first << ',' << p.second.second << '%' << endl;
    }

private:
    string file_name;
    ofstream file;
    vector<pair<string, pair<int, double>> > dict;

    void FileOpen() {
        file.open(file_name);
        if (!file.is_open()) {
            cout << "file opening error" << endl;
            exit(0);
        }
    }

    void FileClose() {
        if (file.is_open())
            file.close();
    }
};


int main(int argc, char* argv[]) {
    if (argc != 3){
        cout << "incorrect number of argumets" << endl;
        return 0;
    }
    FileReader file(argv[1]);
    WordStatService library;
    string next_line;
    while (file.GetNextline(&next_line)) {
        TokenService new_line(next_line);
        string next_word;
        while (new_line.GetNextWord(&next_word)) {
            library.AddWord(next_word);
        }
    }
    ReportService report(argv[2], library.GetDict());
    report.Write();
}
