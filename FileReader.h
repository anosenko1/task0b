#ifndef TASK0B_FILEREADER_H
#define TASK0B_FILEREADER_H
#include <string>
#include <fstream>
using namespace std;
#endif

class FileReader {
public:

    explicit FileReader(string file_name);
    ~FileReader();
    bool GetNextline(string *line);
    void setNewFile(string new_file_name);
private:
    string file_name;
    ifstream file;

    void FileOpen();
    void FileClose();
};

