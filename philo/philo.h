/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:51:38 by mvalient          #+#    #+#             */
/*   Updated: 2023/04/17 19:40:21 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stats
{
	int	number_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
}			t_stats;

typedef struct s_fork
{
	int				index;
	struct s_fork	*next;
}			t_fork;

typedef struct s_philo
{
	int				index;
	pthread_t 		thread;
	struct s_philo	*next;
}			t_philo;

int	ft_atoi(const char *nptr);
t_philo *create_philo_list(int number_philo);
t_fork *create_fork_list(int number_philo);

#endif
