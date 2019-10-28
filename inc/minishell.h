/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:58:44 by mbrella           #+#    #+#             */
/*   Updated: 2019/10/11 10:58:46 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include <signal.h>
# include "pwd.h"
# include "grp.h"
# include <sys/stat.h>
# include <sys/types.h>
# include "time.h"
#include <sys/wait.h>
# include <sys/xattr.h>


pid_t	g_pid;
int		do_exe(char **mas, char **envl);
int     do_cd(char **mas, char ***envl);
int     show_env(char **mas);
char	*find_var(char *dop, char **envl);
int		find_exe(char *dir_name, char *filename);
int		do_echo(char *line, char **envl);
int		full_exe(char **mas, char **envl);
int		free_dmas(char **mas);
int     ft_setenv(char **mas, char ***envl, char **dopmas, int type);
char	**ft_split_echo(char *str, char *delim);
int     full_env(char **mas, char ***envl);

#endif
