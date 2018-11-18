/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:15:57 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/15 09:27:33 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
# include <time.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct		s_opt
{
	int				l:1;
	int				a:1;
	int				t:1;
	int				r:1;
	int				big_r:1;
}					t_opt;

typedef struct		s_file
{
	char			*name;
	char			permissions[11];
	size_t			links;
	char			*uid;
	char			*gid;
	struct timespec	time;
	char			*formatted_time;
	size_t			size;
	int				dir:1;
}					t_file;

typedef struct		s_dir
{
	struct s_file	*file;
	char			*path;
	struct s_dir	*next;
	struct s_dir	*prev;
}					t_dir;

typedef struct		s_list
{
	char			*path;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int					ft_ls(char *path, t_opt *o);
void				add_path_front(t_list **head, char *path);
void				add_entry_front(t_dir **head, char *filename);
char				*path_join(char *path, char *filename);
void				do_recursion(t_dir *dir, t_opt *o, char *path);
void				queue_paths(t_list *paths, t_opt *o);

t_dir				*read_entries(DIR *dirp, t_opt *o);
t_dir				*read_dir(char *path, t_opt *o);
void				read_details(char *path, t_dir **dir);

void				read_mode(t_dir **entry, struct stat buf);
void				read_uid_gid(t_dir **entry, struct stat buf);
void				read_size(t_dir **entry, struct stat buf);
void				read_time(t_dir **entry, struct stat buf);
void				read_links(t_dir **entry, struct stat buf);

void				sort_lex(t_dir **head, t_opt *o);
void				sort_time(t_dir **head, t_opt *o);
void				sort_dir(t_dir **head, t_opt *o);
void				swap_nodes(t_file **a, t_file **b);

void				init_options(t_opt *o);
t_list				*split_options(t_opt *o, int argc, char **argv);
int					opt_check(t_opt *o, char *arg);

void				print_paths(t_list *paths);
void				print_entries(t_dir *dir);
void				print_long(t_dir *entries);

void				free_directory(t_dir *d);
void				free_file(t_file *f);
#endif
