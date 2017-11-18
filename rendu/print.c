/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:28 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 17:25:59 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmap(char **map, int sizemap)
{
	int		i;

	i = 0;
	while (i < sizemap)
	{
		ft_putstr(map[i]);
		i++;
		ft_putchar('\n');
	}
}

void	ft_usage(void)
{
	ft_putstr("usage: fillit source_file\n");
}
