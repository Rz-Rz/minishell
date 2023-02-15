/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:38:49 by kdhrif            #+#    #+#             */
/*   Updated: 2023/02/15 17:03:35 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		ft_echo(char **av)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	if (av[1] && ft_strncmp(av[1], "-n", ft_strlen(av[1])) == 0)
	{
		n = 1;
		i++;
	}
	while (av[i])
	{
		ft_putstr_fd(av[i], STDOUT);
		if (av[i + 1])
			ft_putchar_fd(' ', STDOUT);
		i++;
	}
	if (!n)
		ft_putchar('\n');
	return (0);
}
