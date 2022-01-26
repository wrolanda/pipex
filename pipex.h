/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:41:17 by wrolanda          #+#    #+#             */
/*   Updated: 2022/01/26 13:12:58 by wrolanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/*for access, unlink, close, read, write, pipe, dup, dup2, execve, fork*/
# include <unistd.h>
/*for open*/
# include <fcntl.h>
/*for malloc, free, exit*/
# include <stdlib.h>
/*for wait, waitpid*/
# include <sys/wait.h>
/*for perror*/
# include <stdio.h>

#endif
