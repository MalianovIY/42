#include "fillit.h"

//unsigned char	**int2tetra(unsigned short int a, char c)//, tetra_t *t) //'A' == 65, '.' == 46
//{
//	unsigned char 	**tet;
//	int		i;//, j;
//
//	i = -1;
//	//if (a == 0)
//	//	exit(221);
//	tet = (char **)malloc(sizeof(char *) * 5);
//	tet[4] = NULL;
//	while ((a & 0xF000) != 0 && i < 4)
//	{
//		tet[++i] = (char *)malloc(sizeof(char) * 5);
//		tet[i][0] = 46 + (char)((a & 0x8000) != 0) * (c - 46);
//		tet[i][1] = 46 + (char)((a & 0x4000) != 0) * (c - 46);
//		tet[i][2] = 46 + (char)((a & 0x2000) != 0) * (c - 46);
//		tet[i][3] = 46 + (char)((a & 0x1000) != 0) * (c - 46);
//		tet[i][4] = 0;
//		a <<= 4;
//	}
////	j = -1;
//	while (++j < 5)
//		if (tet[i][j] != '.')
//			t->x = (size_t)j;
//	t->y = (size_t)i;
//	while (++i < 4)
//		tet[i] = ft_memset((char *)ft_memalloc(sizeof(char) * 5), 46, 4);
//	return (tet);
//}
typedef struct f
{
	char *s;
	char c;
}			t_e;
void	test(t_e *f)
{
	f[0].c = 'd';
	f[1].c = 'e';
	f[2].c = 'f';
	f[0].s = "j";
	f[1].s = "k";
	f[2].s = "l";
}
int main()
{
	t_e	*f;
	f = malloc(sizeof(t_e)*3);
	f[0].c = 'a';
	f[1].c = 'b';
	f[2].c = 'c';
	f[0].s = malloc(2);
	f[0].s = "g";
	f[1].s = malloc(2);
	f[1].s = "h";
	f[2].s = malloc(2);
	f[2].s = "i";
	test(f);
	int i = -1;
	while (++i < 3)
		printf("%c - %s\n",f[i].c,f[i].s);
}
//	unsigned int c[10];
//	unsigned int *a;
//	unsigned char	s[40], *u;
//	a = c;
//	*a++ = (0xCC00F000);
//	*a++ = (0x88886C00);
//	*a++ = (0x8C40C600);
//	*a++ = (0x4C80E800);
//	*a++ = (0xC4402E00);
//	*a++ = (0x88C0E200);
//	*a++ = (0x44C08E00);
//	*a++ = (0xC880E400);
//	*a++ = (0x4C404E00);
//	*a++ = (0x8C800000);
//	*a++ = 0;

//	a = c;
//	u = s;
//	ft_memcpy(u,a,40);
//	while (u - s < 40)
//		printf("\\%o",*u++);
//	a = c;
//	u = s - 1;
//	while (u - s < 40)
//	{
//		//printf("%d\n\n", *a);
//		//++u = int2tetra((unsigned short int)((*a) >> 16), 'A' + a - c);
//		printf("%s\n%s\n%s\n%s\n\n", u[0], u[1], u[2], u[3]);
//		a++;
//	}
//
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
//