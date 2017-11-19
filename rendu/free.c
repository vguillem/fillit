/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:50:13 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/19 13:40:58 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freemap(char **map, int sizemap)
{
	int		i;

	i = 0;
	while (i < sizemap)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freetab(char ***tab, int nbtetri)
{
	int		i;
	int		j;

	i = 0;
	while (i < nbtetri)
	{
		j = 0;
		while (j < 4)
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}
