/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:19:36 by ahorker           #+#    #+#             */
/*   Updated: 2019/02/14 05:40:58 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**int2tetra(unsigned int a, char c, tetra_t *t) //'A' == 65, '.' == 46
{
	char 	**tet;
	int		i, j;

	i = -1;
	if (a == 0)
		exit(221);
	tet = (char **)malloc(sizeof(char *) * 5);
	tet[4] = NULL;
	while ((a & 0xF000) != 0 && i < 4)
	{
		tet[++i] = (char *)malloc(sizeof(char) * 5);
		tet[i][0] = 46 + (char)((a & 0x8000) != 0) * (c - 46);
		tet[i][1] = 46 + (char)((a & 0x4000) != 0) * (c - 46);
		tet[i][2] = 46 + (char)((a & 0x2000) != 0) * (c - 46);
		tet[i][3] = 46 + (char)((a & 0x1000) != 0) * (c - 46);
		tet[i][4] = 0;
		a <<= 4;
	}
	j = -1;
	while (++j < 5)
		if (tet[i][j] != '.')
			t->x = (size_t)j;
	t->y = (size_t)i;
	while (++i < 4)
		tet[i] = ft_memset((char *)ft_memalloc(sizeof(char) * 5), 46, 4);
	return (tet);
}

int		tetread(int fd, char buf[], int *t)
{
	int	ret, wl, i;

	ret = (int)read(fd, buf, 21);
	if ((ret < 20 && ret > 0) || ret < 0)
		exit(1);
	buf[ret] = 0;
	i = -1;
	t[0] = 0;
	wl = 5;
	while (buf[++i])
		if (((buf[i] == '.' || buf[i] == '#') && i % 5 != 4 && i != 20) ||
				(buf[i] == '\n' && (i % 5 == 4 || i == 20)))
			if ((*t = (buf[i] == '#') ? ((*t << 1) | 1) : *t) != 0 && buf[i] == '#')
				wl = wl < i % 5 ? wl : i % 5;
			else
				*t = (buf[i] == '.') ? (*t << 1) : *t;
		else
			exit(2);
	*t <<= wl;
	while ((*t & 0xF000) == 0 && *t)
		*t <<= 4;
	return (ret);
}

void	tetreadvalid(int fd, int const tet[], int inp[])
{
	char	buf[22];
	int		i, j, t, ret, p;

	j = 0;
	ret = 22;
	p = 1;
	while (ret > 19)
	{
		ret = tetread(fd, buf, &t);
		p = ret == 20 ? 0 : p;
		i = -1;
		while (tet[++i] && t)
			if (t == tet[i])
				break ;
		if (i > 18)
			exit(4);
		else
			inp[j++] = t;
		if (ret < 21)
			break ;
	}
	if (p == 1)
		exit(5);
}

int		main(int argc, char *argv[])
{
	int		fd, i, j, size, mx, my;
	unsigned int	tet[20],inp[27];
	tetra_t	*tetra;

	ft_memcpy((void *)&tet[0],(void *)STRING_TETRA_1, 20);
	ft_memcpy((void *)&tet[10],(void *)STRING_TETRA_2, 20);
//	unsigned char *t; t = tet;
//	while (t - tet < 40)
//		printf("\\%o",*t++);printf();
	ft_bzero(inp, 27);
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 29);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	tetreadvalid(fd, tet, inp);
	close(argv[1]);
	size = 0;
	while (inp[size] && size < 27)
		size++;
	tetra = (tetra_t *)malloc(sizeof(tetra_t) * (size + 1));
	tetra[size].t = NULL;
	j = -1;
	while (++j < 20)
	{
		tetra[j].t = int2tetra(tet[j], 'A' + j, &(tetra[j]));
		i = -1;
		tetra[j].x = 0;
		tetra[j].y = 0;
		tetra[j].k = 0;
		while (tetra[j].t[0][tetra[j].k] == '.')
			tetra[j].k++;
		ft_putendl(tetra[j].t[0]);
		ft_putendl(tetra[j].t[1]);
		ft_putendl(tetra[j].t[2]);
		ft_putendl(tetra[j].t[3]);
		ft_putendl("");
	}
	//if (fillit(&tetra, (size_t)size) == 1)
	//	printf("1!!!11!!!");
	exit(0);
}
