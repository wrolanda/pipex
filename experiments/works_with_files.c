#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "../includes/pipex.h"
/* open read from file and write in another file*/
int main(int argc, char **argv)
{
    (void)argc;

    int infile;
    int outfile;
    int read_bytes;
    char buffer[20];

    infile = open(argv[1], O_RDONLY, 0);
    if (infile < 0) 
        return (printf("-bash: %s: No such file or directory\n", argv[1]));
    else 
        (printf("ok\n"));
    outfile = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, S_IWRITE);
    if (outfile < 0)
        return (printf("cant open/create outfile"));
    read_bytes = 1;
    while (read_bytes > 0)
    {
        read_bytes = read(infile, buffer, 20);
        write(outfile, buffer, read_bytes);
    }
    close(infile);
    close(outfile);
    return (0);
        
}


