/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:46:16 by mvalient          #+#    #+#             */
/*   Updated: 2023/04/28 17:51:49 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philo(t_data *data)
{
	t_philo	*temp_philo;

	temp_philo = data->philo;
	while (temp_philo)
	{
		pthread_join(temp_philo->thread, NULL);
		temp_philo = temp_philo->next;
	}
}

void	wake_philo(t_data *data)
{
	t_philo	*temp_philo;

	temp_philo = data->philo;
	while (temp_philo)
	{
		pthread_create(&temp_philo->thread, NULL, philosopher, data);
		temp_philo = temp_philo->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->stat = malloc(sizeof(t_stats));
	if (argc < 5 || argc > 6)
		return (1);
	data->stat->number_philo = ft_atoi(argv[1]);
	data->stat->time_die = ft_atoi(argv[2]);
	data->stat->time_eat = ft_atoi(argv[3]);
	data->stat->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->stat->must_eat = ft_atoi(argv[5]);
	else
		data->stat->must_eat = -1;
	data->philo = create_philo_list(data->stat->number_philo);
	data->fork = create_fork_list(data->stat->number_philo);
	wake_philo(data);
	wait_philo(data);
	return (0);
}
