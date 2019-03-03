/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahorker <ahorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 21:23:58 by ahorker           #+#    #+#             */
/*   Updated: 2018/12/19 20:56:12 by ahorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	**ft_arrnew(size_t m, size_t n, unsigned char c)
{
	long long int	i, j;
	unsigned char	**out;

	if (m + 1 == 0 || n + 1 == 0)
		return (NULL);
	if ((out = (unsigned char **)malloc((m + 1) *
			sizeof(unsigned char *))) == NULL)
		return (NULL);
	out[m] = NULL;
	i = -1;
	while ((size_t)(++i) < m)
	{
		if ((out[i] = (unsigned char *)malloc(n + 1)) == NULL)
		{
			while (--i > -1)
				free(out[i]);
			free(out);
			return (NULL);
		}
		out[i][n] = '\0';
		j = -1;
		while ((size_t)(++j) < n)
			out[i][j] = c;
	}
	return ((void **)out);
}