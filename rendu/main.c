/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:13 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/19 08:45:06 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	***tab;
	t_map	tmap;

	if (ac != 2)
	{
		ft_usage();
		return (0);
	}
	tmap.nbtetri = 0;
	if (!(tab = ft_check_fillit(av, &tmap)))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_solver(tab, &tmap);
	return (1);
}
