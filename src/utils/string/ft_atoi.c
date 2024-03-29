/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:21:40 by yboudoui          #+#    #+#             */
/*   Updated: 2023/03/15 13:38:11 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	long long int	result;
	long long int	sign;

	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	sign = (*nptr == '+') - (*nptr == '-');
	nptr += (!!sign);
	result = 0;
	while (ft_isdigit(*nptr))
		result = (result * 10) + (*nptr++ - '0');
	result *= ((!!sign) * sign) + (!sign);
	return (result);
}
