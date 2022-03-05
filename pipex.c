/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:17:44 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/28 22:04:33 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	pipex(t_pipex *s, char **argv, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
		return (perror("Pipe"));
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork"));
	if (child1 == 0)
		ft_child_one(s, end, argv[2], envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork"));
	if (child2 == 0)
		ft_child_two(s, end, argv[3], envp);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	ft_child_one(t_pipex *s, int end[2], char *argv, char **envp)
{
	if (dup2(s->infile, STDIN_FILENO) < 0)
		return ;
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return ;
	close(end[0]);
	close(end[1]);
	s->cmd_args = ft_split(argv, ' ');
	s->command = ft_get_cmd(s->cmd_args[0], s->cmd_path_only);
	if (!s->command)
	{
		ft_child_free(s);
		perror("first command not found");
		exit(1);
	}
	execve(s->command, s->cmd_args, envp);
	close(s->infile);
}

void	ft_child_two(t_pipex *s, int end[2], char *argv, char **envp)
{
	if (dup2(end[0], STDIN_FILENO) < 0)
		return ;
	if (dup2(s->outfile, STDOUT_FILENO) < 0)
		return ;
	close(end[1]);
	s->cmd_args = ft_split(argv, ' ');
	s->command = ft_get_cmd(s->cmd_args[0], s->cmd_path_only);
	if (!s->command)
	{
		ft_child_free(s);
		perror("second command not found");
		exit(1);
	}
	execve(s->command, s->cmd_args, envp);
	close(s->outfile);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	s;

	if (argc != 5)
		return (write (1, "Incorrect number of arguments\n", 31));
	s.infile = open(argv[1], O_RDONLY);
	s.outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
	if (s.infile < 0 || s.outfile < 0)
	{
		perror("bash: ");
		return (-1);
	}
	s.cmd_path_all = ft_find_path(envp);
	s.cmd_path_only = ft_split(s.cmd_path_all, ':');
	pipex(&s, argv, envp);
	ft_parent_free(&s);
	return (0);
}
