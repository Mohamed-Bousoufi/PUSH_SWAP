/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:18:07 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/12 21:27:20 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

long long	ft_atoi(const char *str)
{
	int			signe;
	long long	res;
	int			sz;
	int			i;

	sz = ft_strlen(str);
	signe = 1;
	res = 0;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if ((str[i] == 43 || str[i] == 45))
		if (str[i++] == 45)
			signe = -1;
	while (str[i] >= 48 && str[i] <= 57)
		res = res * 10 + str[i++] - 48;
	sz--;
	return (res * signe);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_not_number(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9')
			&& (s[i] != ' ' && s[i] != '-' && s[i] != '+'))
			ft_error();
		i++;
	}
}

void	check_arg(char *s)
{
	int	i;
	int	var;
	int	sp;

	i = 0;
	var = 0;
	sp = 0;
	check_not_number(s);
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || (s[i] == ' '
				|| s[i] == '-' || s[i] == '+'))
			if ((s[i] == '-' || s[i] == '+')
				&& (s[i + 1] < '0' || s[i + 1] > '9'))
				var++;
		if ((s[i] == '-' || s[i] == '+')
			&& (s[i + 1] >= '0' && s[i + 1] <= '9')
			&& (s[i - 1] >= '0' && s[i - 1] <= '9'))
			var++;
		if (s[i] >= '0' && s[i] <= '9')
			sp++;
		i++;
	}
	if (var > 0 || sp == 0)
		ft_error();
}
