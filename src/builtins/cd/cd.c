#include "../../../inc/minishell.h"

void print_pth(char *pth)
{
	pth = getcwd(NULL, 0);
	ft_putstr_fd(pth, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	free(pth);
}

int	ft_cd(char *path, int print_path)
{
	/* char *cwd; */
	/* char buff[4096]; */

	/* cwd = getcwd(buff, 4096); */
	if (!chdir(path))
	{
		if (print_path)
		{
			print_pth(path);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
	else {
		{
			ft_putstr_fd("cd: ", STDERR_FILENO);
			if (access(path, F_OK) == -1)
				ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
			else if (access(path, R_OK) == -1)
				ft_putstr_fd("permission denied: ", STDERR_FILENO);
			else
				ft_putstr_fd("not a directory: ", STDERR_FILENO);
		}
	}
	return (0);
}
