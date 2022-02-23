/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:41:17 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/23 20:22:52 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*for access, unlink, close, read, write, pipe, dup, dup2, execve, fork,
 STDOUT_FIILENO, STDIN_FIILENO*/
# include <unistd.h>
/*for open*/
# include <fcntl.h>
/*for malloc, free, exit*/
# include <stdlib.h>
/*for wait, waitpid*/
# include <sys/wait.h>
/*for perror*/
# include <stdio.h>

/* R and W для собственника, группы и ост-х */
# define S_IREAD           0444
# define S_IWRITE          0222

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*cmd_path;
	char	**cmds;
	char	**cmd_args;
	char	*command;

}		t_pipex;

void	pipex(t_pipex *s, char **argv, char **envp);
void	ft_child_one(t_pipex *s, int end[2], char *argv, char **envp);
void	ft_child_two(t_pipex *s, int end[2], char *argv, char **envp);
char	*ft_find_path(char **envp);
void	ft_parent_free(t_pipex *s);
void	ft_child_free(t_pipex *s);
char	*ft_get_cmd(char *cmd, char **paths);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);

#endif
