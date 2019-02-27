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

char	**createmap(int size)
{
	char **map;
	int i;

	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		exit(6);
	map[size] = NULL;
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			exit(7);
		ft_memset(map[i], '.', size);
		map[i][size] = 0;
	}
	return (map);
}

void 	backtracking(char **map, char ***t)
{
	int	i, j, k;

	i = 0;
	while ()
	while (t[i] != NULL)
	{
		puttetra(map, tetra[i]);
		backtracking(map, tetra);
		removetera(map, tetra[i++]);
	}

}

void	fillit(char ***t, int n)
{
	char **map;
	map = createmap(2 * n);
	backtracking(map, t);
}
