/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:10:44 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:28:40 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_ls(char *path, t_opt *o)
{
	t_dir			*dir;

	dir = read_dir(path, o);
	if (!dir)
		return (0);
	read_details(path, &dir);
	sort_dir(&dir, o);
	if (o->l)
	{
		print_long(dir);
	}
	else
		print_entries(dir);
	if (o->big_r)
	{
		do_recursion(dir, o, path);
	}
	free_directory(dir);
	return (1);
}

void				queue_paths(t_list *paths, t_opt *o)
{
	static int		multiple = 0;

	if (!multiple && paths && paths->next)
		multiple = 1;
	if (!paths)
	{
		return ;
	}
	if (paths->path)
	{
		if (multiple)
			b_printf("%s:\n", paths->path);
		if (!ft_ls(paths->path, o))
			return ;
	}
	if (paths->next)
	{
		queue_paths(paths->next, o);
	}
	free(paths->path);
	free(paths);
}

int					main(int argc, char **argv)
{
	t_opt			options;
	t_list			*paths;

	init_options(&options);
	if (argc == 1)
	{
		ft_ls(".", &options);
	}
	else
	{
		paths = split_options(&options, argc, argv);
		if (paths)
		{
			queue_paths(paths, &options);
		}
		else
		{
			return (1);
		}
	}
	return (0);
}
