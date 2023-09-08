/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:53:09 by kramjatt          #+#    #+#             */
/*   Updated: 2022/10/05 15:47:48 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*start;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	start = ft_lstnew((*f)(lst->content));
	if (start == NULL)
		return (NULL);
	final = start;
	lst = lst->next;
	while (lst)
	{
		start = ft_lstnew((*f)(lst->content));
		if (start == NULL)
		{
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, start);
		lst = lst->next;
	}
	return (final);
}
