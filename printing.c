/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:05:30 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:23:31 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_paths(t_list *paths)
{
	if (!paths)
	{
		return ;
	}
	if (paths->path)
	{
		b_printf("%s\n", paths->path);
	}
	if (paths->next)
	{
		print_paths(paths->next);
	}
}

void			print_entries(t_dir *dir)
{
	if (!dir)
	{
		return ;
	}
	if (dir->file->name)
	{
		b_printf("%s\n", dir->file->name);
	}
	if (dir->next)
	{
		print_entries(dir->next);
	}
}

void			print_long(t_dir *entries)
{
	b_printf("%s  ", entries->file->permissions);
	b_printf("%u ", (unsigned int)entries->file->links);
	b_printf("%s ", entries->file->uid);
	b_printf("%s ", entries->file->gid);
	b_printf("%u ", (unsigned int)entries->file->size);
	b_printf("%s ", entries->file->formatted_time);
	b_printf("%s\n", entries->file->name);
	if (entries->next)
	{
		print_long(entries->next);
	}
}
