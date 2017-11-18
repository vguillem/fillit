/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:50:13 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 17:57:08 by vguillem         ###   ########.fr       */
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
