/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glabaden <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:31:07 by glabaden          #+#    #+#             */
/*   Updated: 2023/12/22 07:46:59 by glabaden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *ft_get_pathname(char **env,char *cmd)
{
	int	i;
	int	j;
	char	**split_path;
	char	*path_cmd;
	
	i = 0;
	j = 0;
	while(env[i])
	{
		if(ft_strnstr(env[i],"PATH=",5))
			break;
		i++;
	}
	split_path = ft_split(env[i],':');
	i = 0;
	while(split_path[i])
	{
		path_cmd = ft_strjoin(split_path[i],"/");
		path_cmd = ft_strjoin(path_cmd,cmd);
		if(access(path_cmd, X_OK | F_OK) == 0)
			return (path_cmd);
		i++;
	}
	return (0);
}	
int execute_cmd(char **env , char *argv )
{
	char **cmd_cut;
	char *path;
	cmd_cut = ft_split(argv,' ');
	path = ft_get_pathname(env,cmd_cut[0]);
	printf("%d",execve(path,cmd_cut,NULL));
	return (0);
}
void child_proc(char **env , int argc ,char **argv,int pipe_fds[2])
{
	int fd_arg  = open(argv[1],O_RDONLY);
	dup2(fd_arg,0);
	dup2(pipe_fds[1],1);
	execute_cmd(env,argv[2]);
}
void parent_proc(char **env , int argc ,char **argv,int pipe_fds[2])
{
	int fd_arg  = open(argv[4] ,O_WRONLY| O_CREAT | O_TRUNC);
	dup2(fd_arg,1);
	dup2(pipe_fds[0],0);
	execute_cmd(env,argv[3]);
	wait(NULL);
}
int main(int argc,char **argv,char **env)
{
	int pipe_fds[2];
	pid_t pid;

	if(argc != 5)
		return (0);
	if(pipe(pipe_fds) == -1)
		return (1);
	pid = fork();
	if(pid == -1)
		return(2);
	if(pid == 0)
		child_proc(env,argc,argv,pipe_fds);
	else
		parent_proc(env,argc,argv,pipe_fds);
	
	
}
