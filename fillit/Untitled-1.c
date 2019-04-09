#include <stdio.h>
#include "libft/includes/libft.h"

unsigned char	**int2tetra(unsigned int a, char c)//, tetra_t *t) //'A' == 65, '.' == 46
{
	unsigned char 	**tet;
	int		i;//, j;

	i = -1;
	if (a == 0)
		exit(221);
	tet = (unsigned char **)malloc(sizeof(unsigned char *) * 5);
	tet[4] = NULL;
	while ((a & 0xF000) != 0 && i < 4)
	{
		tet[++i] = (unsigned char *)malloc(sizeof(unsigned char) * 5);
		tet[i][0] = 46 + (char)((a & 0x8000) != 0) * (c - 46);
		tet[i][1] = 46 + (char)((a & 0x4000) != 0) * (c - 46);
		tet[i][2] = 46 + (char)((a & 0x2000) != 0) * (c - 46);
		tet[i][3] = 46 + (char)((a & 0x1000) != 0) * (c - 46);
		tet[i][4] = 0;
		a <<= 4;
	}
//	j = -1;
//	while (++j < 5)
//		if (tet[i][j] != '.')
//			t->x = (size_t)j;
//	t->y = (size_t)i;
	while (++i < 4)
		tet[i] = (unsigned char *)ft_memset((void *)(unsigned char *)ft_memalloc(sizeof(unsigned char) * 5), 46, 4);
	return (tet);
}

int main()
{
	unsigned int c[20];
	unsigned int *a;
	unsigned char	**u, s[40], *t;
	a = c;
	*a++ = (0xCC) << 8;
	*a++ = (0xF0) << 8;
	*a++ = (0x8888);
	*a++ = (0x6C) << 8;
	*a++ = (0x8C4) << 4;
	*a++ = (0xC6) << 8;
	*a++ = (0x4C8) << 4;
	*a++ = (0xE8) << 8;
	*a++ = (0xC44) << 4;
	*a++ = (0x2E) << 8;
	*a++ = (0x88C) << 4;
	*a++ = (0xE2) << 8;
	*a++ = (0x44C) << 4;
	*a++ = (0x8E) << 8;
	*a++ = (0xC88) << 4;
	*a++ = (0xE4) << 8;
	*a++ = (0x4C4) << 4;
	*a++ = (0x4E) << 8;
	*a++ = (0x8C8) << 4;
	*a++ = 0;

	// a = c;
	// while (u)
	// {
	// 	printf("%d\n\n", *a);
	// 	u = int2tetra(*a, 'A' + a - c);
	// 	printf("%s\n%s\n%s\n%s\n\n", u[0], u[1], u[2], u[3]);
	// 	a++;
	// }

	ft_memcpy((void *)s, (void *)c, 40);
	t = s;
	while (t - s < 40)
		printf("\\%o",*t++);
	/*
	char **c;
	int	i = -1,j = -1;
c = ft_memalloc(4 * sizeof(char *));
c[0] = ft_memalloc(4);
c[1] = ft_memalloc(4);
c[2] = ft_memalloc(4);
ft_memset(c[2],'Z',3);
ft_memset(c[1],'Z',3);
ft_memset(c[0],'Z',3);
*c[3] = 'A';

while (c[++i])
{
	j = -1;
	printf("\t");
	while (c[i][++j])
		printf("\t%c", c[i][j]);
}

	unsigned int i, a[40];
	a[0] = (0xCC);
	a[1] = (0xF0);
	a[2] = (0x88);
	a[3] = (0x6C);
	a[4] = (0x8C);
	a[5] = (0xC6);
	a[6] = (0x4C);
	a[7] = (0xE8);
	a[8] = (0xC4);
	a[9] = (0x2E);
	a[10] = (0x88);
	a[11] = (0xE2);
	a[12] = (0x44);
	a[13] = (0x8E);
	a[14] = (0xC8);
	a[15] = (0xE4);
	a[16] = (0x4C);
	a[17] = (0x4E);
	a[18] = (0x8C);
	a[19] = 0;
	i = -1;
	while(++i < 20)
		printf("%o\t", a[i]);
	printf("\n");
	a[0] = (0x00);
	a[1] = (0x00);
	a[2] = (0x88);
	a[3] = (0x00);
	a[4] = (0x40);
	a[5] = (0x00);
	a[6] = (0x80);
	a[7] = (0x00);
	a[8] = (0x40);
	a[9] = (0x00);
	a[10] = (0xC0);
	a[11] = (0x00);
	a[12] = (0xC0);
	a[13] = (0x00);
	a[14] = (0x80);
	a[15] = (0x00);
	a[16] = (0x40);
	a[17] = (0x00);
	a[18] = (0x80);
	a[19] = 0;
	i = -1;
	while(++i < 20)
		printf("%o\t", a[i]);
*/
		}