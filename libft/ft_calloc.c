/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnencini <daniele.nencini@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:28:35 by dnencini          #+#    #+#             */
/*   Updated: 2022/10/11 11:02:41 by dnencini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* void *calloc(size_t nitems, size_t size)
alloca la memoria richiesta e restituisce un puntatore ad essa.
 La differenza tra malloc e calloc è che malloc non imposta la memoria su zero
 mentre calloc imposta la memoria allocata a zero
*/
#include "libft.h"
//#include <stdio.h>
//nmemb −   numero di elementi da allocare.
//size −  dimensione degli elementi.

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
//controllo overflow
	if (size && nmemb > 2147483647 / size)
		return (NULL);
//alloco la memoria  con malloc e faccio il casting dentro p
	p = (char *)malloc(nmemb * size);
	if (!p)
		return (NULL);
//porto tutti gli elementi a zero
	ft_memset(p, 0, nmemb * size);
	return (p);
//p che ritorna e' un puntatore char della dimensione necessaria
}
