#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd;
	char *line;
	int ret;

	fd = open("/Users/jihoh/Documents/42cursus/gnl/gnl_auto_test/gnl-war-machine/tests/n.txt", O_RDONLY);
	while ((ret = get_next_line(fd,&line)) >= 0)
	{
		printf("%s, %d\n", line, ret);
		if (ret == 0)
			break ;
	}
}		
