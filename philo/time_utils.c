/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:53:24 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 09:42:13 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_date(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	ft_date_diff(long date)
{
	return (ft_date() - date);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = ft_date();
	while ((ft_date() - start_time) < time_in_ms)
		usleep(100);
}

int	is_dead(long last_meal, long now, int time_to_die)
{
	if ((now - last_meal) > time_to_die)
		return (1);
	return (0);
}
