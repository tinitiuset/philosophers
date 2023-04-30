/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:01:51 by mvalient          #+#    #+#             */
/*   Updated: 2023/04/30 20:03:51 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_try_eat(t_p_data *data, long date)
{
	pthread_mutex_lock(&data->l_fork->on_use);
	printf("%ld Philosopher %d has taken a fork\n",
		ft_date(), data->philo->index);
	pthread_mutex_lock(&data->r_fork->on_use);
	printf("%ld Philosopher %d has taken a fork\n",
		ft_date(), data->philo->index);
	printf("%ld Philosopher %d is eating\n",
		ft_date(), data->philo->index);
	usleep(data->stat->time_eat * 1000);
	pthread_mutex_unlock(&data->l_fork->on_use);
	pthread_mutex_unlock(&data->r_fork->on_use);
}

void	*ft_philosopher(void *attr)
{
	t_p_data		*p_data;
	int				alive;
	int				eaten;

	alive = 1;
	eaten = 0;
	p_data = (t_p_data *)attr;
	printf("Philosopher %d is alive\n", p_data->philo->index);
	while (alive && eaten < p_data->stat->must_eat)
	{
		ft_try_eat(p_data, ft_date());
		eaten ++;
		printf("%ld Philosopher %d is sleeping\n",
			ft_date(), p_data->philo->index);
		usleep(p_data->stat->time_sleep * 1000);
	}
	free(attr);
	pthread_exit(0);
}
