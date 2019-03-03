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

 void	int2tetra(USI a, char c, t_tet *t, char ***g)
{
	int		i, j;
	char	**tet;

	tet = *g;
	if (a == 0)
		exit(221);
	i = -1;
	while ((a & 0xF000) != 0 && ++i < 4)
	{
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
	t->t = tet;
}

int		tetread(int fd, char buf[], USI *t)
{
	short int	i;
	USI			ret, wl;

	ret = (unsigned short int)read(fd, buf, 21);
	if ((ret < 20 && ret > 0) || ret < 0)
		exit(1);
	buf[ret] = 0;
	i = -1;
	t[0] = 0;
	wl = 5;
	while (buf[++i])
		if (((buf[i] == 46 || buf[i] == 35) && i % 5 != 4 && i != 20) ||
				(buf[i] == 10 && (i % 5 == 4 || i == 20)))
			if ((*t = buf[i] == 35 ? ((*t << 1) | 1) : *t) != 0 &&
					buf[i] == 35)
				wl = wl < i % 5 ? wl : i % 5;
			else
				*t = (buf[i] == '.') ? (*t << 1) : *t;
		else
			exit(2);
	*t <<= wl;
	while ((*t & 0xF000) == 0 && *t)
		*t <<= 4;
	if (*t == 0)
		exit (6);
	return (ret);
}

void	tetreadvalid(int fd, USI const tet[], USI inp[], int *size)
{
	char	buf[22];
	int		i, j, ret, p;
	USI		t;

	j = 0;
	ret = 22;
	p = 1;
	while (ret > 19)
	{
		ret = tetread(fd, buf, &t);
		p = (ret == 20 ? 0 : p);
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
	*size = j;
	if (p == 1)
		exit(5);
}

int		main(int argc, char **argv)
{
	int		fd, j, size;
	USI		tet[27], inp[27];
	t_tet	*tetra;
	char	**t;

	ft_bzero(tet, 54);
	ft_bzero(inp, 54);
	ft_memcpy((void *)&tet[0],(void *)STR_TETRA_1, 16);
	ft_memcpy((void *)&tet[8],(void *)STR_TETRA_2, 16);
	ft_memcpy((void *)&tet[16],(void *)STR_TETRA_3, 16);
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 29);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	tetreadvalid(fd, tet, inp, &size);
	close(fd);
	tetra = (t_tet *)malloc(sizeof(t_tet) * (size + 1));
	tetra[size].t = NULL;
	j = -1;
	while (++j < size)
	{
		t = (char **)ft_arrnew(4, 4, 46);
		int2tetra(inp[j], 65 + j, &tetra[j], &t);
		tetra[j].k = 0;
		tetra[j].p = 0;
		while (tetra[j].t[0][tetra[j].k] == 46)
			tetra[j].k++;
	}
	if (fillit(&tetra, (size_t)size) == 1)
		printf("1!!!11!!!");
	exit(0);
}
