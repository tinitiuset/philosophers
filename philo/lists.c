/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:38:32 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/03 18:46:36 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_create_philo_list(int num)
{
	t_philo	*head;
	t_philo	*tmp;
	int		i;

	i = 1;
	head = malloc(sizeof(t_philo));
	head->i = i;
	head->next = NULL;
	tmp = head;
	while (++i <= num)
	{
		tmp->next = malloc(sizeof(t_philo));
		tmp = tmp->next;
		tmp->i = i;
		tmp->next = NULL;
	}
	return (head);
}

t_fork	*ft_create_fork_list(int num)
{
	t_fork	*head;
	t_fork	*tmp;
	int		i;

	i = 1;
	head = malloc(sizeof(t_fork));
	memset(head, 0, sizeof(t_fork));
	head->index = i;
	pthread_mutex_init(&head->mutex, NULL);
	head->next = NULL;
	tmp = head;
	while (++i <= num)
	{
		tmp->next = malloc(sizeof(t_fork));
		memset(tmp->next, 0, sizeof(t_fork));
		tmp = tmp->next;
		tmp->index = i;
		pthread_mutex_init(&head->mutex, NULL);
		tmp->next = NULL;
	}
	return (head);
}
