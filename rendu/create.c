/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:04 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 17:40:39 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_cre_tetri(char ***tab, char *buf, int pos, int notetri)
{
	int		line;
	int		i;

	line = -1;
	while (line++ < 3)
	{
		if (!(tab[notetri][line] = (char *)ft_memalloc(sizeof(char) * 5)))
			return (NULL);
		i = 0;
		while (i < 4)
		{
			if (buf[pos++] == '#')
				tab[notetri][line][i++] = 'A' + notetri;
			else
				tab[notetri][line][i++] = '.';
		}
		pos++;
	}
	return (tab);
}

char	***ft_create_tetris(char ***tab, char *buf, int nbtetri)
{
	int		pos;
	int		notetri;

	notetri = 0;
	pos = 0;
	while (notetri < nbtetri)
	{
		if (!(tab[notetri] = (char **)ft_memalloc(sizeof(char *) * 4)))
			return (NULL);
		if (!(ft_cre_tetri(tab, buf, pos, notetri)))
			return (NULL);
		pos += 21;
		notetri++;
	}
	return (tab);
}
