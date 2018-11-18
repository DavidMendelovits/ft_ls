/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:36:34 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:25:18 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*path_join(char *path, char *filename)
{
	char		*ret;
	int			i;
	int			j;

	ret = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(filename) + 2));
	i = 0;
	j = 0;
	while (path[j])
	{
		ret[i] = path[j];
		i += 1;
		j += 1;
	}
	ret[i++] = '/';
	j = 0;
	while (filename[j])
	{
		ret[i] = filename[j];
		i += 1;
		j += 1;
	}
	ret[i] = '\0';
	return (ret);
}

void				do_recursion(t_dir *dir, t_opt *o, char *path)
{
	char		*path_;

	while (dir)
	{
		if (dir->file->permissions[0] == 'd' &&
		(ft_strcmp(dir->file->name, ".") && ft_strcmp(dir->file->name, "..")))
		{
			path_ = path_join(path, dir->file->name);
			b_printf("\n%s:\n", path_);
			ft_ls(path_, o);
			free(path_);
		}
		dir = dir->next;
	}
}
