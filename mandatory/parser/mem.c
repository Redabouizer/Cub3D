/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:24:21 by rbouizer          #+#    #+#             */
/*   Updated: 2025/03/22 20:28:07 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*my_malloc(t_mem **manager, size_t size)
{
	void	*ptr;
	t_mem	*new_node;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_putendl_fd("Error: Memory allocation failed", 2);
		return (NULL);
	}
	new_node = (t_mem *)malloc(sizeof(t_mem));
	if (new_node == NULL)
	{
		ft_putendl_fd("Error: Memory allocation for manager failed", 2);
		free(ptr);
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = *manager;
	*manager = new_node;
	return (ptr);
}

void	cleanup(t_mem **manager)
{
	t_mem	*current;
	t_mem	*next;

	current = *manager;
	while (current != NULL)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	*manager = NULL;
}