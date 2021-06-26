#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *line;
	int ret;

	fd = open("./test", O_RDONLY);
	while ((ret = get_next_line(fd,&line)) > 0)
		printf("%s, %d\n", line, ret);
}		
