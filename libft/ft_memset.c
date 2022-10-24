/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnencini <daniele.nencini@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:34:49 by dnencini          #+#    #+#             */
/*   Updated: 2022/10/05 12:37:00 by dnencini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*memset() riempie un blocco di memoria con n bytes del valore x indicato  
La sintassi della funzione memset() è la seguente:

 ptr ==> Indirizzo iniziale della memoria da riempire
x ==> Valore da compilare
n ==> Numero di byte di ptr da riempire 
void *memset(void *ptr, int x, size_t n);
 ptr è un void  , quindi possiamo passare qualsiasi tipo di puntatore a questa funzione.
 
 es: 
    char str[50] = "Esempio di stringa da riempire";
    memset(str + 13, '*', 8*sizeof(char));
  
    // Riempie 8 caratteri partendo da str[13] con '.'
   */
 



#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;
// faccio subito il casting di b assegnandolo a str
	str = (unsigned char *)b;
	i = 0;

//riempie con c  finche i < len 
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
	// ritorna b che e' un puntatore di tipo void
}
