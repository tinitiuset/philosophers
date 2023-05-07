/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:46:16 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 11:24:41 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_clear_data(t_d *data)
{
	t_p	*temp_philo;
	t_f	*temp_fork;

	while (data->p != NULL)
	{
		temp_philo = data->p->n;
		free(data->p);
		data->p = temp_philo;
	}
	while (data->f != NULL)
	{
		temp_fork = data->f->n;
		free(data->f);
		data->f = temp_fork;
	}
	free(data->s);
	free(data);
}

static void	ft_select_forks(t_d *data, t_p_d *pdata)
{
	t_f	*temp_fork;

	temp_fork = data->f;
	while (temp_fork)
	{
		if (temp_fork->i == pdata->p->i)
			pdata->l = temp_fork;
		if (temp_fork->i == pdata->p->i + 1)
			pdata->r = temp_fork;
		temp_fork = temp_fork->n;
	}
	if (pdata->r == NULL)
		pdata->r = data->f;
}

static void	ft_wait_philo(t_d *data)
{
	t_p		*temp_philo;
	void	*ret;

	temp_philo = data->p;
	while (temp_philo)
	{
		pthread_join(temp_philo->t, &ret);
		temp_philo = temp_philo->n;
	}
	printf("Simulation ended");
}

static void	ft_wake_philo(t_d *data)
{
	t_p		*temp_philo;
	t_p_d	*p_data;

	data->s->t = ft_date();
	temp_philo = data->p;
	while (temp_philo)
	{
		p_data = malloc(sizeof(t_p_d));
		memset(p_data, 0, sizeof(t_p_d));
		p_data->s = data->s;
		p_data->p = temp_philo;
		p_data->p->l = p_data->s->t;
		ft_select_forks(data, p_data);
		pthread_create(&temp_philo->t, NULL, ft_philosopher, p_data);
		temp_philo = temp_philo->n;
	}
}

int	main(int argc, char **argv)
{
	t_d	*data;

	data = malloc(sizeof(t_d));
	data->s = malloc(sizeof(t_s));
	if (argc < 5 || argc > 6)
		return (1);
	data->s->n = ft_atoi(argv[1]);
	data->s->d = ft_atoi(argv[2]);
	data->s->e = ft_atoi(argv[3]);
	data->s->s = ft_atoi(argv[4]);
	data->s->t = ft_date();
	data->s->dd = false;
	if (argc == 6)
		data->s->m = ft_atoi(argv[5]);
	else
		data->s->m = -1;
	data->p = ft_create_philo_list(data->s->n);
	data->f = ft_create_fork_list(data->s->n);
	ft_wake_philo(data);
	ft_wait_philo(data);
	ft_clear_data(data);
	return (0);
}
