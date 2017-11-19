/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:23:53 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/19 13:36:32 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_form(char *buf, int pos, int i)
{
	int		link;

	link = 0;
	if (i + 5 < 20 && buf[pos + 5] == '#')
		link++;
	if (i + 1 < 20 && buf[pos + 1] == '#')
		link++;
	if (i != 0 && buf[pos - 1] == '#')
		link++;
	if (i > 4 && buf[pos - 5] == '#')
		link++;
	return (link);
}

int		ft_check_one_tetri(char *buf, int pos, int i, int tetri)
{
	int		htag;
	int		link;
	int		tmp;

	htag = 0;
	link = 0;
	while (++i < 20)
	{
		if (buf[pos] != '.' && buf[pos] != '#' && buf[pos] != '\n')
			return (0);
		if (buf[pos] == '#' && ++htag)
		{
			if (!(tmp = ft_check_form(buf, pos, i)))
				return (0);
			link += tmp;
		}
		if (buf[pos] && ((pos - tetri + 1) % 5 == 0) && buf[pos] != '\n')
			return (0);
		pos++;
	}
	if (link != 6 && link != 8)
		return (0);
	return (htag);
}

int		ft_check_tetri(char *buf, t_map *tmap)
{
	int		tetri;
	int		i;
	int		pos;

	pos = 0;
	tetri = 0;
	while (tetri < tmap->nbtetri)
	{
		i = -1;
		if (ft_check_one_tetri(buf, pos, i, tetri) != 4)
			return (0);
		tetri++;
		if (buf[pos + 20] && buf[pos + 20] != '\n')
			return (0);
		pos = pos + 21;
	}
	return (1);
}

char	***ft_check_fillit(char **av, t_map *tmap)
{
	int		fd;
	int		ret;
	char	buf[548];
	char	***tab;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buf, 547);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (NULL);
	if (ret == 547 || (ret + 1) % 21 != 0)
		return (NULL);
	tmap->nbtetri = (ret + 1) / 21;
	if (!(tab = ft_memalloc(sizeof(char *) * (tmap->nbtetri + 1))))
		return (NULL);
	if (!(ft_check_tetri(buf, tmap)))
		return (NULL);
	if (!(tab = ft_create_tetris(tab, buf, tmap->nbtetri)))
		return (NULL);
	return (tab);
}
