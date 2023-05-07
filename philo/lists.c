/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:38:32 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/07 11:20:01 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_p	*ft_create_philo_list(int num)
{
	t_p	*head;
	t_p	*tmp;
	int	i;

	i = 1;
	head = malloc(sizeof(t_p));
	head->i = i;
	head->n = NULL;
	tmp = head;
	while (++i <= num)
	{
		tmp->n = malloc(sizeof(t_p));
		tmp = tmp->n;
		tmp->i = i;
		tmp->n = NULL;
	}
	return (head);
}

t_f	*ft_create_fork_list(int num)
{
	t_f	*head;
	t_f	*tmp;
	int	i;

	i = 1;
	head = malloc(sizeof(t_f));
	head->i = i;
	pthread_mutex_init(&head->m, NULL);
	head->n = NULL;
	tmp = head;
	while (++i <= num)
	{
		tmp->n = malloc(sizeof(t_f));
		memset(tmp->n, 0, sizeof(t_f));
		tmp = tmp->n;
		tmp->i = i;
		pthread_mutex_init(&head->m, NULL);
		tmp->n = NULL;
	}
	return (head);
}
