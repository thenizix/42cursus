/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnencini <daniele.nencini@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:42:26 by dnencini          #+#    #+#             */
/*   Updated: 2022/10/05 12:42:59 by dnencini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//mirabile utilizzo di memset
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
