#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("./get_next_line_utils_bonus.c", O_RDONLY);
	char *p = get_next_line(fd);
    while (p)
    {
		printf("%s", p);
		free(p);
		p = get_next_line(fd);
    }
	free(p);
    close(fd);
    return (0);
}