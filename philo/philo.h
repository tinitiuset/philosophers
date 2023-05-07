/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:51:38 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 11:22:40 by mvalient         ###   ########.fr       */
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

typedef struct s_s
{
	int		n;
	int		d;
	int		e;
	int		s;
	int		m;
	long	t;
	bool	dd;
}			t_s;

typedef struct s_f
{
	int				i;
	bool			u;
	pthread_mutex_t	m;
	struct s_f		*n;
}			t_f;

typedef struct s_p
{
	int				i;
	pthread_t		t;
	struct s_p		*n;
	long			l;
}			t_p;

typedef struct s_p_d
{
	t_s	*s;
	t_p	*p;
	t_f	*l;
	t_f	*r;
}			t_p_d;

typedef struct s_d
{
	t_s	*s;
	t_p	*p;
	t_f	*f;
}			t_d;

int		ft_atoi(const char *nptr);
t_p		*ft_create_philo_list(int number_philo);
t_f		*ft_create_fork_list(int number_philo);
void	*ft_philosopher(void *attr);
long	ft_date(void);
long	ft_d_d(long date);
void	ft_usleep(long int time_in_ms);
int		is_dead(long last_meal, long now, int time_to_die);

#endif
