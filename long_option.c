/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:28:06 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:26:13 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void				read_mode(t_dir **entry, struct stat buf)
{
	ft_memset((*entry)->file->permissions, '-', 11);
	(*entry)->file->permissions[10] = '\0';
	if (S_ISDIR(buf.st_mode))
		(*entry)->file->permissions[0] = 'd';
	if (buf.st_mode & S_IRUSR)
		(*entry)->file->permissions[1] = 'r';
	if (buf.st_mode & S_IWUSR)
		(*entry)->file->permissions[2] = 'w';
	if (buf.st_mode & S_IXUSR)
		(*entry)->file->permissions[3] = 'x';
	if (buf.st_mode & S_IRGRP)
		(*entry)->file->permissions[4] = 'r';
	if (buf.st_mode & S_IWGRP)
		(*entry)->file->permissions[5] = 'w';
	if (buf.st_mode & S_IXGRP)
		(*entry)->file->permissions[6] = 'x';
	if (buf.st_mode & S_IROTH)
		(*entry)->file->permissions[7] = 'r';
	if (buf.st_mode & S_IWOTH)
		(*entry)->file->permissions[8] = 'w';
	if (buf.st_mode & S_ISVTX)
		(*entry)->file->permissions[9] = 't';
	else if (buf.st_mode & S_IXOTH)
		(*entry)->file->permissions[9] = 'x';
}

void				read_uid_gid(t_dir **entry, struct stat buf)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = getpwuid(buf.st_uid);
	(*entry)->file->uid = ft_strdup(uid->pw_name);
	gid = getgrgid(buf.st_gid);
	(*entry)->file->gid = ft_strdup(gid->gr_name);
}

void				read_size(t_dir **entry, struct stat buf)
{
	(*entry)->file->size = (size_t)buf.st_size;
}

void				read_time(t_dir **entry, struct stat buf)
{
	(*entry)->file->time = buf.st_mtimespec;
	(*entry)->file->formatted_time =
		ft_strdup_range(ctime(&buf.st_mtime), 0, 15);
}

void				read_links(t_dir **entry, struct stat buf)
{
	(*entry)->file->links = buf.st_nlink;
}
