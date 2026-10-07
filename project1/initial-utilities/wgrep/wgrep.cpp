#include<iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>  
#include <vector>


void wgrep(std::string word, char * file) {

    int fileDescriptor = open(file, O_RDONLY);

    if (fileDescriptor < 0)
    { // file cannot open
        std::cerr << "wgrep: cannot open file\n" << std::endl;
        exit(1);
    }

    std::string currentLine;
    char singleChar;
    ssize_t bytesRead;

    while ((bytesRead = read(fileDescriptor, &singleChar, 1)) > 0) {
        if (singleChar == '\n') {
            if (currentLine.find(word) != std::string::npos) {
                 std::cout << currentLine << "\n";
            }
            currentLine.clear();
        } else {
            currentLine.push_back(singleChar);
        }
    }

    return;
}

int main(int argc, char **argv) {

     std::string word = argv[1];

     if (argc == 1) {
        std::cout << "wgrep: searchterm [file...]\n" << std::endl;
        exit(1);
     }

     if (argc == 2) {
        
     }

    for (int i = 2; i < argc; ++i) {
        wgrep(word, argv[i]);
    }

    return 0;
    
}

