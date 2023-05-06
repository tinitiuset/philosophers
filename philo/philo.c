/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:01:51 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/06 23:43:48 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_dead(long last_meal, long now, int time_to_die)
{
	if ((now - last_meal) > time_to_die)
		return (1);
	return (0);
}

/*
 * Routine will put philosopher to sleep
 */
void	ft_sleep(t_p_data *data)
{
	if (data->stat->dead)
		return ;
	printf("%ld Philosopher %d is sleeping\n",
		   ft_date_diff(data->stat->start_time), data->philo->index);
	ft_usleep(data->stat->time_sleep);
}

static int	ft_try_eat(t_p_data *data)
{
	while (!is_dead(data->philo->last_meal, ft_date(), data->stat->time_die))
	{
		if (!data->l_fork->used)
		{
			pthread_mutex_lock(&data->l_fork->mutex);
			data->l_fork->used = true;
			printf("%ld Philosopher %d has taken a fork\n",
				   ft_date_diff(data->stat->start_time), data->philo->index);
			break ;
		}
	}
	while (!is_dead(data->philo->last_meal, ft_date(), data->stat->time_die))
	{
		if (!data->r_fork->used)
		{
			pthread_mutex_lock(&data->r_fork->mutex);
			data->r_fork->used = true;
			printf("%ld Philosopher %d has taken a fork\n",
				   ft_date_diff(data->stat->start_time), data->philo->index);
			break ;
		}
	}
	if (is_dead(data->philo->last_meal, ft_date(), data->stat->time_die))
		return (0);
	data->philo->last_meal = ft_date();
	printf("%ld Philosopher %d is eating\n",
		   ft_date_diff(data->stat->start_time), data->philo->index);
	ft_usleep(data->stat->time_eat);
	data->l_fork->used = false;
	data->r_fork->used = false;
	pthread_mutex_unlock(&data->l_fork->mutex);
	pthread_mutex_unlock(&data->r_fork->mutex);
	return (1);
}

void	*ft_philosopher(void *attr)
{
	t_p_data		*p_data;
	bool 			*dead;
	int				eaten;

	eaten = 0;
	p_data = (t_p_data *)attr;
	dead = &p_data->stat->dead;
	p_data->philo->last_meal = p_data->stat->start_time;
	if (p_data->philo->index % 2 == 1)
		ft_usleep(10);
	while ((eaten < p_data->stat->must_eat || p_data->stat->must_eat == -1) && *dead == false)
	{
		if (ft_try_eat(p_data))
			eaten ++;
		else
		{
			if (!*dead)
			{
				printf("%ld Philosopher %d is dead\n",
					   ft_date_diff(p_data->stat->start_time), p_data->philo->index);
				*dead = true;
			}
		}
		if (*dead == true)
			break ;
		ft_sleep(p_data);
	}
	free(attr);
	if (*dead == true)
		pthread_exit((void *)1);
	pthread_exit(0);
}
