/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:44 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/09 15:51:31 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(int infile, int outfile, char *cmd1, char *cmd2)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
		return (perror("fork"));
	if (parent == 0)
		child_process(infile, end[2], cmd1);
	else
		parent_process(outfile, end[2], cmd2);
}

void	child_process(int infile, int end[2], char *cmd1)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		return ;
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return ;
	close(end[0]);
	close(infile);
	exit(EXIT_FAILURE);
}

void	parent_process(int outfile, int end[2], char *cmd2)
{
	int	status;

	waitpid(-1, &status, 0);
	if (dup2(end[0], STDIN_FILENO) < 0)
		return ;
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return ;
	close(end[1]);
	close(outfile);
	exit(EXIT_FAILURE);
}
