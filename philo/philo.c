/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:01:51 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 11:13:50 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Routine will put philosopher to sleep
 * and check if dies while sleeping
 */
void	ft_sleep(t_p_data *data)
{
	long	sleep;

	if (data->stat->dead)
		return ;
	printf("%ld Philosopher %d is sleeping\n",
		ft_date_diff(data->stat->start_time), data->philo->index);
	sleep = 0;
	while (sleep < data->stat->time_sleep)
	{
		if (is_dead(data->philo->last_meal, ft_date(), data->stat->time_die))
		{
			if (data->stat->dead)
				return ;
			data->stat->dead = true;
			printf("%ld Philosopher %d died\n",
				ft_date_diff(data->stat->start_time), data->philo->index);
			return ;
		}
		ft_usleep(1);
		sleep++;
	}
}

static void	get_left_fork(t_p_data *data)
{
	while (!is_dead(data->philo->last_meal, ft_date(), data->stat->time_die))
	{
		if (!data->l_fork->used)
		{
			pthread_mutex_lock(&data->l_fork->mutex);
			data->l_fork->used = true;
			if (data->stat->dead)
				return ;
			printf("%ld Philosopher %d has taken a fork\n",
				ft_date_diff(data->stat->start_time), data->philo->index);
			break ;
		}
	}
}

static void	get_right_fork(t_p_data *data)
{
	while (!is_dead(data->philo->last_meal, ft_date(), data->stat->time_die))
	{
		if (!data->r_fork->used)
		{
			pthread_mutex_lock(&data->r_fork->mutex);
			data->r_fork->used = true;
			if (data->stat->dead)
				return ;
			printf("%ld Philosopher %d has taken a fork\n",
				ft_date_diff(data->stat->start_time), data->philo->index);
			break ;
		}
	}
}

static int	ft_try_eat(t_p_data *data)
{
	get_left_fork(data);
	get_right_fork(data);
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
	int				eaten;

	eaten = 0;
	p_data = (t_p_data *)attr;
	if (p_data->philo->index % 2 == 1)
		ft_usleep(10);
	while ((eaten < p_data->stat->must_eat || p_data->stat->must_eat == -1) && p_data->stat->dead == false)
	{
		if (ft_try_eat(p_data))
			eaten ++;
		else
		{
			if (!p_data->stat->dead)
			{
				p_data->stat->dead = true;
				printf("%ld Philosopher %d died\n",
					ft_date_diff(p_data->stat->start_time), p_data->philo->index);
			}
		}
		if (p_data->stat->dead == true)
			break ;
		ft_sleep(p_data);
	}
	free(attr);
	pthread_exit(0);
}
