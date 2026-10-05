#include<iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>  
#include <vector>

int main(int argc, char **argv){

    int fileDescriptor = open(argv[1], O_RDONLY);

    if (fileDescriptor < 0) { //file cannot open
        std::cerr << "cannot open file" << std::endl;
        exit(1);
    }

    char buffer[1024];
  
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1) {
        std::cerr << ("Error reading file") << std::endl;
    }

    else if (bytesRead == 0) {
        std::cerr << ("File was empty. Reached EOF immediately.\n") << std::endl;
    }

    else {
        std::cout << buffer << " bytes from the file";
    }
    
    close(fileDescriptor);
    return 0;
}


/*
read command line argument (the file name)

open the file

read contents in a buffer line my line
print out the buffer
*/

