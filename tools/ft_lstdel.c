/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:50:57 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/14 10:53:53 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	if (alst && del)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
		}
	}
}
