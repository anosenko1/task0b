#include <string>
#include <iostream>
#include "FileReader.h"
using namespace std;

FileReader::FileReader(string file_name) {
    this->file_name = std::move(file_name);
    FileOpen();
}
FileReader::~FileReader() {
    FileClose();
}
bool FileReader::GetNextline(string *line) {
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
void FileReader::FileOpen() {
    file.open(file_name);
    if (!file.is_open()) {
        cerr << "file opening error\n";
        exit(23);
    }
}
void FileReader::FileClose() {
    if (file.is_open())
        file.close();
}

void FileReader::setNewFile(string new_file_name) {
    FileClose();
    this->file_name = std::move(new_file_name);
    FileOpen();
}


