/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:38:53 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:29:15 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				swap_nodes(t_file **a, t_file **b)
{
	t_file			*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void				sort_lex(t_dir **head, t_opt *o)
{
	t_dir			*tmp;
	int				sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = *head;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->file->name, tmp->next->file->name) > 0 && !o->r)
			{
				swap_nodes(&tmp->file, &tmp->next->file);
				sorted = 0;
			}
			else if (ft_strcmp(tmp->file->name, tmp->next->file->name) < 0
			&& o->r)
			{
				swap_nodes(&tmp->file, &tmp->next->file);
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
}

int					compare_time(t_file *a, t_file *b, t_opt *o)
{
	if (a->time.tv_sec == b->time.tv_sec)
	{
		if (a->time.tv_nsec < b->time.tv_nsec && !o->r)
		{
			return (1);
		}
		else if (a->time.tv_nsec > b->time.tv_nsec && o->r)
		{
			return (1);
		}
	}
	else if (a->time.tv_sec < b->time.tv_sec && !o->r)
	{
		return (1);
	}
	else if (a->time.tv_sec > b->time.tv_sec && o->r)
	{
		return (1);
	}
	return (0);
}

void				sort_time(t_dir **head, t_opt *o)
{
	t_dir			*tmp;
	int				sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = *head;
		while (tmp->next)
		{
			if (compare_time(tmp->file, tmp->next->file, o))
			{
				swap_nodes(&tmp->file, &tmp->next->file);
				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
}

void				sort_dir(t_dir **head, t_opt *o)
{
	if (o->t)
	{
		sort_time(head, o);
	}
	else
	{
		sort_lex(head, o);
	}
}
