/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:21:49 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/23 22:44:36 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	ft_parent_free(t_pipex *s)
{
	int	i;

	i = 0;
	while (s->cmd_path_only[i])
	{
		free(s->cmd_path_only[i]);
		i++;
	}
	free(s->cmd_path_only);
}

void	ft_child_free(t_pipex *s)
{
	int	i;

	i = 0;
	while (s->cmd_args[i])
	{
		free(s->cmd_args[i]);
		i++;
	}
	free(s->cmd_args);
	free(s->command);
}

char	*ft_get_cmd(char *cmd, char **paths)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
