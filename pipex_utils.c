/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:21:49 by wrolanda          #+#    #+#             */
/*   Updated: 2022/02/23 18:42:05 by wrolanda         ###   ########.fr       */
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
	while (s->cmds[i])
	{
		free(s->cmds[i]);
		i++;
	}
	free(s->cmds);
}
