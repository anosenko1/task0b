#ifndef TASK0B_REPORTSERVICE_H
#define TASK0B_REPORTSERVICE_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class ReportService {

public:
    explicit ReportService(string file_name, vector<pair<string, pair<int, double>> > dict);
    ~ReportService();
    void Write();

private:
    string file_name;
    ofstream file;
    vector<pair<string, pair<int, double>> > dict;

    void FileOpen();
    void FileClose();
};

#endif
