#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	***ft_check_fillit(int ac, char **av, int *nbtetri);
char	***ft_create_tetri(char ***tab, char *buf, int pos, int notetri);
char	***ft_create_tetris(char ***tab, char *buf, int nbtetri);
//int		ft_solver(char ***tab, int nbtetri);

#endif
