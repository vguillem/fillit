/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:39:32 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/19 13:41:11 by vguillem         ###   ########.fr       */
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
typedef struct	s_map
{
	int		nbtetri;
	int		notetri;
	int		sizemap;
}				t_map;
char			***ft_check_fillit(char **av, t_map *tmap);
char			***ft_cre_tetri(char ***tab, char *buf, int pos, int notetri);
char			***ft_create_tetris(char ***tab, char *buf, int nbtetri);
int				ft_solver(char ***tab, t_map *tmap);
char			**ft_createmap(int	sizemap);
int				ft_mapsize(int nbtetri);
char			**ft_savemap(char **map, int sizemap);
void			ft_printmap(char **map, int sizemap);
void			ft_remap(char **map, char **savemap, int sizemap);
void			ft_usage();
void			ft_freemap(char **map, int sizemap);
void			ft_freetab(char ***tab, int nbtetri);

#endif
