/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:51:38 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 09:38:44 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <memory.h>
# include <stdbool.h>

typedef struct s_stats
{
	int		number_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	long	start_time;
	bool	dead;
}			t_stats;

typedef struct s_fork
{
	int				index;
	bool			used;
	pthread_mutex_t	mutex;
	struct s_fork	*next;
}			t_fork;

typedef struct s_philo
{
	int				index;
	pthread_t		thread;
	struct s_philo	*next;
	long			last_meal;
}			t_philo;

typedef struct s_p_data
{
	t_stats	*stat;
	t_philo	*philo;
	t_fork	*l_fork;
	t_fork	*r_fork;
}			t_p_data;

typedef struct s_data
{
	t_stats	*stat;
	t_philo	*philo;
	t_fork	*fork;
}			t_data;

int		ft_atoi(const char *nptr);
t_philo	*ft_create_philo_list(int number_philo);
t_fork	*ft_create_fork_list(int number_philo);
void	*ft_philosopher(void *attr);
long	ft_date(void);
long	ft_date_diff(long date);
void	ft_usleep(long int time_in_ms);
int		is_dead(long last_meal, long now, int time_to_die);

#endif
