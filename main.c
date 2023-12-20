#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char *args[3] = {
        "ls",
        "-l"
    };
    execve("/bin/ls",args,NULL);
}