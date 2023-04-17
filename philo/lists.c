/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:38:32 by mvalient          #+#    #+#             */
/*   Updated: 2023/04/17 19:56:09 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philo_list(int num)
{
	t_philo	*head;
	t_philo	*tmp;
	int		i;

	i = 0;
	head = malloc(sizeof(t_philo));
	head->index = i;
	head->next = NULL;
	tmp = head;
	while (++i < num)
	{
		tmp->next = malloc(sizeof(t_philo));
		tmp = tmp->next;
		tmp->index = i;
		tmp->next = NULL;
	}
	return (head);
}

t_fork	*create_fork_list(int num)
{
	t_fork	*head;
	t_fork	*tmp;
	int		i;

	i = 0;
	head = malloc(sizeof(t_fork));
	head->index = i;
	head->next = NULL;
	tmp = head;
	while (++i < num)
	{
		tmp->next = malloc(sizeof(t_fork));
		tmp = tmp->next;
		tmp->index = i;
		tmp->next = NULL;
	}
	return (head);
}
