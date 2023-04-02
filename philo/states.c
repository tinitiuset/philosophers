/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:09:56 by mvalient          #+#    #+#             */
/*   Updated: 2023/04/02 20:22:52 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
 * Usage: nofity_state(philo, fork | eat | think | die);
 */
void	nofity_state(t_philo *philo, void (*state))
{
	state(philo);
}

void	fork(t_philo *philo)
{
	long long int	timestamp_in_ms;

	printf("%lld %d has taken a fork\n", timestamp_in_ms, philo->index);
}

void	eat(t_philo *philo)
{
	long long int	timestamp_in_ms;

	printf("%lld %d is eating\n", timestamp_in_ms, philo->index);
}

void	think(t_philo *philo)
{
	long long int	timestamp_in_ms;

	printf("%lld %d is thinking\n", timestamp_in_ms, philo->index);
}

void	die(t_philo *philo)
{
	long long int	timestamp_in_ms;

	printf("%lld %d died\n", timestamp_in_ms, philo->index);
}
