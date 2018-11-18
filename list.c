/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:03:39 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/12 17:56:27 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				add_path_front(t_list **head, char *path)
{
	t_list			*new;

	new = malloc(sizeof(t_list));
	new->path = ft_strdup(path);
	new->prev = NULL;
	if (!(*head))
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

void				add_entry_front(t_dir **head, char *filename)
{
	t_dir			*new;

	new = malloc(sizeof(t_dir));
	new->file = malloc(sizeof(t_file));
	new->prev = NULL;
	new->file->name = ft_strdup(filename);
	if (!(*head))
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}
