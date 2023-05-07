/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:01:51 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 11:24:53 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_p_d *data)
{
	long	s;

	if (data->s->dd)
		return ;
	printf("%ld Philosopher %d is sleeping\n",
		ft_d_d(data->s->t), data->p->i);
	s = 0;
	while (s < data->s->s)
	{
		if (is_dead(data->p->l, ft_date(), data->s->d))
		{
			if (data->s->dd)
				return ;
			data->s->dd = true;
			printf("%ld Philosopher %d died\n",
				ft_d_d(data->s->t), data->p->i);
			return ;
		}
		ft_usleep(1);
		s++;
	}
}

static void	get_left_fork(t_p_d *data)
{
	while (!is_dead(data->p->l, ft_date(), data->s->d))
	{
		if (!data->l->u)
		{
			pthread_mutex_lock(&data->l->m);
			data->l->u = true;
			if (data->s->dd)
				return ;
			printf("%ld Philosopher %d has taken a fork\n",
				ft_d_d(data->s->t), data->p->i);
			break ;
		}
	}
}

static void	get_right_fork(t_p_d *data)
{
	while (!is_dead(data->p->l, ft_date(), data->s->d))
	{
		if (!data->r->u)
		{
			pthread_mutex_lock(&data->r->m);
			data->r->u = true;
			if (data->s->dd)
				return ;
			printf("%ld Philosopher %d has taken a fork\n",
				ft_d_d(data->s->t), data->p->i);
			break ;
		}
	}
}

static int	ft_try_eat(t_p_d *data)
{
	get_left_fork(data);
	get_right_fork(data);
	if (is_dead(data->p->l, ft_date(), data->s->d))
		return (0);
	data->p->l = ft_date();
	printf("%ld Philosopher %d is eating\n", ft_d_d(data->s->t), data->p->i);
	ft_usleep(data->s->e);
	data->l->u = false;
	data->r->u = false;
	pthread_mutex_unlock(&data->l->m);
	pthread_mutex_unlock(&data->r->m);
	return (1);
}

void	*ft_philosopher(void *attr)
{
	t_p_d	*p;
	int		e;

	e = 0;
	p = (t_p_d *)attr;
	if (p->p->i % 2 == 1)
		ft_usleep(10);
	while ((e < p->s->m || p->s->m == -1) && p->s->dd == false)
	{
		if (ft_try_eat(p))
			e ++;
		else
		{
			if (!p->s->dd)
			{
				p->s->dd = true;
				printf("%ld Philosopher %d died\n", ft_d_d(p->s->t), p->p->i);
			}
		}
		if (p->s->dd == true)
			break ;
		ft_sleep(p);
	}
	free(attr);
	pthread_exit(0);
}
