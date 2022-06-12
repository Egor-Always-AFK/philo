/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:58:00 by ocapers           #+#    #+#             */
/*   Updated: 2022/06/12 17:22:40 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		pthread_create(&info->philo[i].thread, NULL, philo, &info->philo[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info		info;
	pthread_t	thread;

	thread = NULL;
	if (argc < 5 || argc > 6)
		printf("error!\ninvalid number of arguments");
	if (check(argc, argv) == 1)
		return (1);
	init(&info, argv);
	create_philos(&info);
	monitor(&info);
}
