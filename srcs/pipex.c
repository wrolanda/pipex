/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:44 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/09 16:07:06 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(int infile, int outfile, char *cmd1, char *cmd2)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork"));
	if (child1 == 0)
		child_one(infile, end[2], cmd1);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork"));
	if (child2 == 0)
		child_two(outfile, end[2], cmd2);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child_one(int infile, int end[2], char *cmd1)
{
	if (dup2(infile, STDIN_FILENO) < 0)
		return ;
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return ;
	close(end[0]);
	close(infile);
	exit(EXIT_FAILURE);
}

void	child_two(int outfile, int end[2], char *cmd2)
{
	if (dup2(end[0], STDIN_FILENO) < 0)
		return ;
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return ;
	close(end[1]);
	close(outfile);
	exit(EXIT_FAILURE);
}
