/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:41:17 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/10 16:10:44 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#define S_IREAD           0400
#define S_IWRITE          0200

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

void	pipex(int infile, int outfile, char *cmd1, char *cmd2);
void	ft_child_one(int infile, int end[2], char *cmd1);
void	ft_child_two(int outfile, int end[2], char *cmd2);

#endif
