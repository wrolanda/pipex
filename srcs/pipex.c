/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:44 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/20 17:05:44 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(int infile, char *cmd1, char *cmd2, int outfile)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
		return ;
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork"));
	if (child1 == 0)
		ft_child_one(infile, end, cmd1);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork"));
	if (child2 == 0)
		ft_child_two(outfile, end, cmd2);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	ft_child_one(int infile, int end[2], char *cmd1)
{
	//if (dup2(infile, STDIN_FILENO) < 0)
	//	return ;
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return ;
	close(end[0]);
	close(infile);
	close(end[1]);
	execlp("ping", "ping", "-c", "5", "google.com", NULL);
	//exit(EXIT_FAILURE);
}

void	ft_child_two(int outfile, int end[2], char *cmd2)
{
	if (dup2(end[0], STDIN_FILENO) < 0)
		return ;
	if (dup2(outfile, STDOUT_FILENO) < 0)
		return ;
	close(end[1]);
	execlp("grep", "grep", "rtt", NULL);
	close(outfile);
	//exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 3)
		printf("Incorrect number of arguments\n");
	
	int infile = 3;
	int outfile;	
	outfile = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, S_IREAD|S_IWRITE);
	if (outfile < 0)
		return (printf("cant open/create outfile\n"));
	pipex(infile, "cmd1","cmd2", outfile);

	return (0);
}
