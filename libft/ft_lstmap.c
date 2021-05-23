/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:58:37 by jihoh             #+#    #+#             */
/*   Updated: 2021/05/23 13:54:09 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *cur;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	cur = new;
	lst = lst->next;
	while (lst)
	{
		if (!(cur->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (new);
}
