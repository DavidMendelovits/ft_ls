/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:49:29 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:28:55 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				free_file(t_file *f)
{
	if (!f)
	{
		return ;
	}
	if (f->name)
	{
		free(f->name);
	}
	if (f->uid && f->gid)
	{
		free(f->uid);
		free(f->gid);
	}
	if (f->formatted_time)
	{
		free(f->formatted_time);
	}
	free(f);
}

void				free_directory(t_dir *d)
{
	t_dir			*tmp;

	if (!d)
		return ;
	while (d)
	{
		tmp = d;
		d = d->next;
		free_file(tmp->file);
		free(tmp);
	}
}
