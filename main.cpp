#include <iostream>
#include <string>
#include "FileReader.h"
#include "TokenService.h"
#include "ReportService.h"
#include "WordStatService.h"

using namespace std;
/*
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
        while (new_line.getNextWord(&next_word)) {
            library.AddWord(next_word);
        }
    }
    ReportService report(argv[2], library.GetDict());
    report.Write();
}
*/
