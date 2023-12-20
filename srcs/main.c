/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:31:07 by glabaden          #+#    #+#             */
/*   Updated: 2023/12/20 07:31:10 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{

	pid_t pid;
	int fds[2];
	pipe(fds);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	int pomme;
	if (pid == 0)
		pomme = 4;
	else
		pomme  = 3;
	pomme = pomme + 2;

	if(pid == 0)
	{
		
		write(fds[1],&pomme);
		close
	}
	else
	{
		dup2(fds[0],STDIN_FILENO);
		int result = pomme + 
		printf("%d",result);
		wait(NULL);
	}

		
 
	return (0);

}
