/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:24:13 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 21:12:09 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		nbtetri;
	char	***tab;

	if (ac != 2)
	{
		ft_usage();
		return (0);
	}
	nbtetri = 0;
	if (!(tab = ft_check_fillit(av, &nbtetri)))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_solver(tab, nbtetri);
	return (1);
}//close le reade 
