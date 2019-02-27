#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char a[40];
	int i = 40;
	int f;
	read(f = open("c",O_RDONLY),a,40);
	printf("%d\n",f);
	while (i--)
		printf("%d, ", (int)*a);
	return(0);
}
