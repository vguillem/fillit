/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:20 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 17:27:07 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_createmap(int sizemap)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * sizemap)))
		return (NULL);
	while (i < sizemap)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * (sizemap + 1))))
			return (NULL);
		ft_memset(map[i], '.', sizemap);
		i++;
	}
	return (map);
}

int		ft_mapsize(int nbtetri)
{
	int		i;

	i = 0;
	while (i * i < nbtetri * 4)
		i++;
	return (i);
}

void	ft_remap(char **map, char **mapsav, int sizemap)
{
	int		i;

	i = 0;
	while (i < sizemap)
	{
		ft_strcpy(map[i], mapsav[i]);
		i++;
	}
}

char	**ft_savemap(char **map, int sizemap)
{
	char	**mapsav;
	int		i;

	i = 0;
	if (!(mapsav = (char **)ft_memalloc(sizeof(char *) * sizemap)))
		return (NULL);
	while (i < sizemap)
	{
		if (!(mapsav[i] = ft_strdup(map[i])))
			return (NULL);
		i++;
	}
	return (mapsav);
}
