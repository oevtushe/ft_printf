/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:42:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_tools.h"

void	ft_lstaddelem(t_list **lst, void **content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(*content, content_size);
	ft_lstappend(lst, new_elem);
	free(*content);
}
