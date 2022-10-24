/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnencini <daniele.nencini@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:20:50 by dnencini          #+#    #+#             */
/*   Updated: 2022/10/06 11:22:29 by dnencini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Con  atoi non c'è modo di scoprire se la stringa passata è davvero un numero,
. Gestisce solo valori decimali (base 10), quindi non può gestire basi arbitrarie.
 Inoltre, non può gestire valori maggiori di signed int (32 bit sulla maggior parte delle piattaforme)
 E' necessario utilizzare strtol() perché atoi() non ritorna controllo degli errori

es:
	char riga[] = "1234567";
	atoi(riga) oppure atoi(&riga[0]) ritorna un int che vale: 1234567;

	atoi(&riga[3]) ritorna un int che vale: 4567

 Infatti &riga[c] ritorna un char*, un puntatore ad un char come richiesto dalla funzione atoi

 */


#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long		result;
	long		sign;
	int		i;
	char	*str;
/* dichiaro long dopo sperimentazione sul campo,
ridichiaro un ptr per disambiguita' */
	str = (char *)nptr;
	i = 0;
	result = 0;
	sign = 1;

	//elimino dall esame i caratteri indesiderati
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;

		//individuiamo un segno - , e nel caso rendiamo negativo sign
		//e scorriamo l indice i
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
//Infine valuto se si tratta di un numero ed esco
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}


/*
per i subject,isdigit() andrebbe dichiarata qui, ma e' gia parte della ftlib

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
*/
