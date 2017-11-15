#ifndef FILLIT_H

# define FILLIT_H

# include "./libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	***ft_check_fillit(int ac, char **av);
char	***ft_create_tetri(char ***tab, char *buf, int nbtetri);

#endif
