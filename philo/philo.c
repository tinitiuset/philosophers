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
static void	ft_sleep(t_p_data *data)
{
	long	sleep;

	if (data->s->dead)
		return ;
	printf("%ld Philosopher %d is sleeping\n",
		ft_dd(data->s->s), data->p->i);
	sleep = 0;
	while (sleep < data->s->time_sleep)
	{
		if (is_dead(data->p->last_meal, ft_date(), data->s->time_die))
		{
			if (data->s->dead)
				return ;
			data->s->dead = true;
			printf("%ld Philosopher %d died\n",
				ft_dd(data->s->s), data->p->i);
			return ;
		}
		ft_usleep(1);
		sleep++;
	}
}

static void	get_left_fork(t_p_data *data)
{
	while (!is_dead(data->p->last_meal, ft_date(), data->s->time_die))
	{
		if (!data->l_fork->used)
		{
			pthread_mutex_lock(&data->l_fork->mutex);
			data->l_fork->used = true;
			if (data->s->dead)
				return ;
			printf("%ld Philosopher %d has taken a fork\n",
				ft_dd(data->s->s), data->p->i);
			break ;
		}
	}
}

static void	get_right_fork(t_p_data *data)
{
	while (!is_dead(data->p->last_meal, ft_date(), data->s->time_die))
	{
		if (!data->r_fork->used)
		{
			pthread_mutex_lock(&data->r_fork->mutex);
			data->r_fork->used = true;
			if (data->s->dead)
				return ;
			printf("%ld Philosopher %d has taken a fork\n",
				ft_dd(data->s->s), data->p->i);
			break ;
		}
	}
}

static int	ft_try_eat(t_p_data *data)
{
	get_left_fork(data);
	get_right_fork(data);
	if (is_dead(data->p->last_meal, ft_date(), data->s->time_die))
		return (0);
	data->p->last_meal = ft_date();
	printf("%ld Philosopher %d is eating\n",
		ft_dd(data->s->s), data->p->i);
	ft_usleep(data->s->time_eat);
	data->l_fork->used = false;
	data->r_fork->used = false;
	pthread_mutex_unlock(&data->l_fork->mutex);
	pthread_mutex_unlock(&data->r_fork->mutex);
	return (1);
}

void	*ft_philosopher(void *attr)
{
	t_p_data		*p_d;
	int				eaten;

	eaten = 0;
	p_d = (t_p_data *)attr;
	if (p_d->p->i % 2 == 1)
		ft_usleep(10);
	while ((eaten < p_d->s->m || p_d->s->m == -1) && p_d->s->dead == false)
	{
		if (ft_try_eat(p_d))
			eaten ++;
		else
		{
			if (!p_d->s->dead)
			{
				p_d->s->dead = true;
				printf("%ld Philosopher %d died\n", ft_dd(p_d->s->s), p_d->p->i);
			}
		}
		if (p_d->s->dead == true)
			break ;
		ft_sleep(p_d);
	}
	free(attr);
	pthread_exit(0);
}
