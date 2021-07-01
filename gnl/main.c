#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *line;
	int ret;

	fd = open("/Users/jihoh/Documents/42cursus/gnl/gnl_auto_test/gnl-war-machine/tests/void.txt", O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s, %d\n", line, ret);
		free(line);
	}
	get_next_line(fd, &line);
	printf("%s, %d\n", line, ret);
	free(line);
	close(fd);
}		
