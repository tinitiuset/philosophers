/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:46:16 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/03 19:26:04 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear_data(t_data *data)
{
	t_philo	*temp_philo;
	t_fork	*temp_fork;

	while (data->philo != NULL)
	{
		temp_philo = data->philo->next;
		free(data->philo);
		data->philo = temp_philo;
	}
	while (data->fork != NULL)
	{
		temp_fork = data->fork->next;
		free(data->fork);
		data->fork = temp_fork;
	}
	free(data->stat);
	free(data);
}

void	ft_select_forks(t_data *data, t_p_data *pdata)
{
	t_fork	*temp_fork;

	temp_fork = data->fork;
	while (temp_fork)
	{
		if (temp_fork->index == pdata->philo->index)
			pdata->l_fork = temp_fork;
		if (temp_fork->index == pdata->philo->index + 1)
			pdata->r_fork = temp_fork;
		temp_fork = temp_fork->next;
	}
	if (pdata->r_fork == NULL)
		pdata->r_fork = data->fork;
}

void	ft_wait_philo(t_data *data)
{
	t_philo	*temp_philo;
	void	*ret;

	temp_philo = data->philo;
	while (temp_philo)
	{
		pthread_join(temp_philo->thread, &ret);
		temp_philo = temp_philo->next;
	}
	if (ret == NULL)
		printf("All philosophers have eaten \n");
	else
		printf("Philosopher %d died\n", (int)ret);
}

void	ft_wake_philo(t_data *data)
{
	t_philo		*temp_philo;
	t_p_data	*p_data;

	temp_philo = data->philo;
	while (temp_philo)
	{
		p_data = malloc(sizeof(t_p_data));
		memset(p_data, 0, sizeof(t_p_data));
		p_data->stat = data->stat;
		p_data->philo = temp_philo;
		ft_select_forks(data, p_data);
		pthread_create(&temp_philo->thread, NULL, ft_philosopher, p_data);
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
	data->philo = ft_create_philo_list(data->stat->number_philo);
	data->fork = ft_create_fork_list(data->stat->number_philo);
	ft_wake_philo(data);
	ft_wait_philo(data);
	ft_clear_data(data);
	return (0);
}
