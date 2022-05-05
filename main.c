#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);

int main()
{
    int fd = open("./main.c", O_RDONLY);
    int i = 0;
    while (i++ < 25)
        printf("%s", get_next_line(fd));
    printf("========================================== \n \n");
    close(fd);
    fd = open("./get_next_line_utils.c", O_RDONLY);
    i = 1;
    while (get_next_line(fd))
    {
        printf("Linha - %d = %s", i, get_next_line(fd));
        i++;
    }
    close(fd);
    return (0);
}