#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <vector>

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    {
        wcat(argv[i]);
    }
    return 0;
}

void wcat(char *file)
{
    int fileDescriptor = open(file, O_RDONLY);

    if (fileDescriptor < 0)
    { // file cannot open
        std::cerr << "cannot open file" << std::endl;
        exit(1);
    }

    char buffer[1024];

    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1)
    {
        std::cerr << ("Error reading file") << std::endl;
    }

    else if (bytesRead == 0)
    {
        std::cerr << ("File was empty. Reached EOF immediately.\n") << std::endl;
    }

    else
    {
        std::cout << buffer << " bytes from the file";
    }

    close(fileDescriptor);
}
