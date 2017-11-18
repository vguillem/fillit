/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:39:32 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/18 20:34:57 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "../libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_pos
{
	int		i;
	int		j;
	int		iref;
}				t_pos;

char			***ft_check_fillit(char **av, int *nbtetri);
char			***ft_cre_tetri(char ***tab, char *buf, int pos, int notetri);
char			***ft_create_tetris(char ***tab, char *buf, int nbtetri);
int				ft_solver(char ***tab, int nbtetri);
char			**ft_createmap(int	sizemap);
int				ft_mapsize(int nbtetri);
char			**ft_savemap(char **map, int sizemap);
void			ft_printmap(char **map, int sizemap);
void			ft_remap(char **map, char **savemap, int sizemap);
void			ft_usage();
void			ft_freemap(char **map, int sizemap);

#endif
