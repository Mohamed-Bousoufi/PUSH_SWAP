/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousouf <mbousouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:40:12 by mbousouf          #+#    #+#             */
/*   Updated: 2023/03/07 16:33:41 by mbousouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_result(char **p, int nom)
{
	int	i;

	i = nom;
	if (!p)
		p = 0;
	else
		while (i > 0)
			free(p[i--]);
	free(p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	if (s == '\0' && len >= 0)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		return (NULL);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = (char *)malloc(len + 1);
	if (!p)
	{
		return (NULL);
	}
	while (len)
	{
		p[i] = s[start + i];
		i++;
		len--;
	}
	p[i] = '\0';
	return (p);
}

static int	numot(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static char	**ft_get_next(const char *s, char c, int len)
{
	char	**p;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	p = malloc((len + 1) * sizeof(char *));
	if (!p)
		return (0);
	while (len && s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		p[j] = ft_substr(s, start, (i - start));
		start = i;
		i++;
		j++;
		len--;
	}
	p[j] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		lenght;

	if (!s)
		return (0);
	lenght = numot(s, c);
	p = ft_get_next(s, c, lenght);
	if (!p)
	{
		free_result(p, numot(s, c));
		return (0);
	}
	return (p);
}
