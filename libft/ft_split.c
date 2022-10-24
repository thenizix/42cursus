/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnencini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:44:35 by dnencini          #+#    #+#             */
/*   Updated: 2022/10/06 09:46:52 by dnencini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 /*lo scopo della funzione split () , e' di dividere la stringa,
  con il carattere specificato come delimitatore,
  in un array** di stringhe.
          char  	**ft_split(char const *s1, char c);

  */
#include <stdlib.h>
//individuo spazi tab e ritorni di linea
int			ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

// conto le parole
int		count_words(char *str)
{
	int	count;
	count = 0;
	while (*str)
	{
		// fino a quando non e' delimitatore , incrementa str
		while (*str && ft_isspace(*str))
			str++;

		if (*str && !ft_isspace(*str))
		{
			//incrementa count
			count++;
			// conta fino al prossimo spazio
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
	//la funzione restituisce il numero di words presenti
}

char	*malloc_word(char *str)
//creo lo spazio per inserire le stringhe risultatnti
{
	char *word;
	int	i;

	i = 0;
// finche str e' vera e str[i] non e' uno spazio, incrementa i.
	while (str[i] && !ft_isspace(str[i]))
		i++;
		//alloco nel puntatore a char word ,  lo spazio per la word
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{

		//inserisco in word  str  fino al delimitatore spazio
		word[i] = str[i];
		i++;
	}
	//inserisco ritorno di linea nella stringa
	word[i] = '\0';
	return (word);
	// ritorno il puntatore a char
}

char	**ft_split(char *str)
{

	//dichiaro un punt a punt di tipo char e alloco
	//la memoria per il numero di array che produrro'
	char **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));

	// == routine per infilare le word dentro gli  array allocati
	int i = 0;
	while (*str)
	{
		// mi muovo all inizio di una nuova word
		while (*str && ft_isspace(*str))
			str++;
			//Incremento l indice di str
		if (*str && !ft_isspace(*str))
		{
			// salva word nell array
			arr[i] = malloc_word(str);
			i++;
			// move to the next whitespace
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	// nullchiude l array e lo ritorno
	arr[i] = NULL;
	return (arr);
}

#include <stdio.h>

 int		main(int ac, char **av)
 {
  	char **arr;

  	char *test = "   Ciao. .. sono \tun pericoloso   test molto pericoloso, molto";
  	arr = ft_split(test);
  	printf("%s\n", arr[0]);
 	printf("%s\n", arr[1]);
  	printf("%s\n", arr[2]);
  	printf("%s\n", arr[3]);
  	printf("%s\n", arr[3+2]);
  }
/*E' evidente che questa funzione e' inefficiente ,
prima di tutto se uso un delimitatore diverso da quello del subject
dopo averla seguita e commentata penso di riscriverla ...
blla l 'idea di una lista  https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c */

