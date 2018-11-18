/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:34:18 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:25:28 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir				*read_entries(DIR *dirp, t_opt *o)
{
	struct dirent	*entry;
	t_dir			*dir;

	dir = NULL;
	while ((entry = readdir(dirp)))
	{
		if (entry->d_name[0] != '.' || o->a)
			add_entry_front(&dir, entry->d_name);
	}
	return (dir);
}

t_dir				*read_dir(char *path, t_opt *o)
{
	DIR				*dirp;
	t_dir			*dir;

	dir = NULL;
	dirp = opendir(path);
	if (!dirp && errno == ENOENT)
	{
		b_printf("invalid path!\n");
		return (NULL);
	}
	else if (!dirp && errno == ENOTDIR)
	{
		b_printf("%s is file, not dir\n", path);
		add_entry_front(&dir, path);
	}
	else if (dirp)
		dir = read_entries(dirp, o);
	closedir(dirp);
	return (dir);
}

void				read_details(char *path, t_dir **dir)
{
	char			*complete_path;
	t_dir			*tmp;
	struct stat		buf;

	tmp = *dir;
	while (tmp)
	{
		complete_path = path_join(path, tmp->file->name);
		lstat(complete_path, &buf);
		free(complete_path);
		read_mode(&tmp, buf);
		read_links(&tmp, buf);
		read_uid_gid(&tmp, buf);
		read_size(&tmp, buf);
		read_time(&tmp, buf);
		tmp = tmp->next;
	}
}
