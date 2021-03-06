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

#ifndef MINISHELL_H
# define MINISHELL_H

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
# include <sys/wait.h>
# include <sys/xattr.h>

pid_t	g_pid;

int		ispar(char c);
int		do_exe(char **mas, char **envl);
int		ft_maslen(char **mas);
int		ft_maslen_with(char **mas);
int		do_cd(char **mas, char ***envl);
int		show_env(char **mas);
char	*find_var(char *dop, char **envl);
int		find_last(char *line, char c);
int		find_exe(char *dir_name, char *filename);
int		ft_error_with(int caseerror, char ***mas);
int		do_echo(char *line, char **envl);
int		print_path();
int		ft_error(int caseerror);
int		full_exe(char **mas, char **envl);
int		free_dmas(char ***mas);
int		ft_setenv(char **mas, char ***envl, char **dopmas, int type);
char	**ft_split_echo(char *str, char *delim);
int		full_env(char **mas, char ***envl);
int		do_rest(char *name, char **mas, char ***env);
int		dop_go_to_dir(char *line, char ***envl);
int		ft_dopenv(char **mas, char ***envl);

#endif
