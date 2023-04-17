/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:46:16 by mvalient          #+#    #+#             */
/*   Updated: 2023/04/17 19:54:21 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_stats		stats;
	t_philo		*philo_list;
	t_fork		*fork_list;

	if (argc < 5 || argc > 6)
		return (1);
	stats.number_philo = ft_atoi(argv[1]);
	stats.time_die = ft_atoi(argv[2]);
	stats.time_eat = ft_atoi(argv[3]);
	stats.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		stats.must_eat = ft_atoi(argv[5]);
	else
		stats.must_eat = -1;
	philo_list = create_philo_list(stats.number_philo);
	fork_list = create_fork_list(stats.number_philo);
	return (0);
}
