/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:32:27 by dmendelo          #+#    #+#             */
/*   Updated: 2018/11/14 10:23:55 by dmendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				init_options(t_opt *o)
{
	o->l = 0;
	o->a = 0;
	o->r = 0;
	o->big_r = 0;
	o->t = 0;
}

int					opt_check(t_opt *o, char *arg)
{
	int				i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'l')
			o->l = 1;
		else if (arg[i] == 'a')
			o->a = 1;
		else if (arg[i] == 'r')
			o->r = 1;
		else if (arg[i] == 'R')
			o->big_r = 1;
		else if (arg[i] == 't')
			o->t = 1;
		else
			return (0);
		i += 1;
	}
	return (1);
}

t_list				*split_options(t_opt *o, int argc, char **argv)
{
	t_list			*paths;
	int				i;

	i = 1;
	paths = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (!opt_check(o, argv[i]))
			{
				b_printf("invalid opt\n");
				return (NULL);
			}
		}
		else
			add_path_front(&paths, argv[i]);
		i += 1;
	}
	if (!paths)
		add_path_front(&paths, ".");
	return (paths);
}
