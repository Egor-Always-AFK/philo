/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:23:59 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/12 16:56:54 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_shell(const char *str)
{
	long	val;

	if (ft_is_numeric_arg(str) == 1)
	{
		printf("Argument must be numeric.\n");
		exit(1);
	}
	val = ft_atoi(str);
	if ((val > (long)INT_MAX + 1 && val < 0) || \
		(val > INT_MAX && val > 0))
	{
		printf("Parameter must be a positive number type of int.\n");
		exit(1);
	}
	return (val);
}

int	check(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (i == 1 && (ft_atoi_shell(av[i]) < 1 \
		|| ft_atoi_shell(av[i]) > 199))
		{
			printf("Number of philosophers can't be less than"
				" 1 and more than 199.\n");
			return (1);
		}
		if ((i == 2 || i == 3 || i == 4) && ft_atoi_shell(av[i]) < 60)
		{
			printf("Philosophers activity must have "
				"a duration of 60 ms at least.\n");
			return (1);
		}
		if (ft_atoi_shell(av[i]) <= 1)
		{
			printf("Parameter must be a positive number type of int.\n");
			return (1);
		}
	}
	return (0);
}

int	ft_is_numeric_arg(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	return (check_rmd(str));
}

int	check_rmd(const char *str)
{
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			flag = 1;
		i++;
	}
	return (flag);
}
