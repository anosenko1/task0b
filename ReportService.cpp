#include "ReportService.h"
#include <iostream>

ReportService::ReportService(string file_name, vector<pair<string, pair<int, double>> > dict) {
    this->file_name = move(file_name);
    this->dict = move(dict);
    FileOpen();
}

ReportService::~ReportService(){
    FileClose();
}

void ReportService::Write(){
    file << "word,count,frequency" << endl;
    for (const auto& p : dict)
        file << p.first << ',' << p.second.first << ',' << p.second.second << '%' << endl;
}

void ReportService::FileOpen() {
    file.open(file_name);
    if (!file.is_open()) {
        cout << "file opening error" << endl;
        exit(0);
    }
}

void ReportService::FileClose() {
    if (file.is_open())
        file.close();
}