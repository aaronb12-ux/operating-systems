#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <cstring> // Required for std::strlen

void wcat(char *file)
{
    int fileDescriptor = open(file, O_RDONLY);

    if (fileDescriptor < 0)
    { // file cannot open
        std::cerr << "wcat: cannot open file\n" << std::endl;
        exit(1);
    }

    char buffer[1024];
    ssize_t bytesRead;
    bool isEmpty = true;

    while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1)) > 0)
    {
        isEmpty = false;

        if (bytesRead == -1)
        {
            std::cerr << ("Error reading file") << std::endl;
            exit(1);
        }

        buffer[bytesRead] = '\0'; // Cut off exactly where this chunk ends
        write(1, buffer, strlen(buffer));
    }

    if (bytesRead == 0 and isEmpty) {
         std::cerr << ("File was empty. Reached EOF immediately.\n") << std::endl;
         exit(1);
    }

    if (bytesRead == 1) {
         std::cerr << ("Error reading file") << std::endl;
         exit(1);
    }

    close(fileDescriptor);
}

int main(int argc, char **argv)
{

    if (argc == 1) { //no input files ->
        exit(0);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        wcat(argv[i]);
    }
    return 0;
}