/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:04 by msolinsk          #+#    #+#             */
/*   Updated: 2024/05/09 10:36:13 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{
	// char	str[] = "Ola ma kota.";
	char	*str = NULL;
	int		n = 987654;
	int		len1;
	int		len2;

	// printf("(NIL) = %p", NULL);
	// printf("INT MIN = %d\n", INT_MIN);
	printf("INT MAX =		 %d\n", INT_MAX);
	printf("UNSIGNED INT MAX =	 %u\n", UINT_MAX);
	printf("UNSIGNED INT MAX =	 %u\n", UINT32_MAX);

	printf("ft_strchr: %s\n\n", ft_strchr("Ola ma kota.", 'm'));

	len1 = ft_printf(" %c ", '@');
	len2 = printf(" %c ", '@');
	printf("\n%d | %d\n\n", len1, len2);
	// printf(" | %c\n", '@');

	len1 = ft_printf("Test %%s  | %s\n", str);
	len2 = printf("Test %%s  | %s\n", str);
	printf("%d | %d\n\n", len1, len2);
	// printf(" | %s\n", str);

	len1 = ft_printf("Test %%p  | %p\n", &str);
	len2 = printf("Test %%p  | %p\n", &str);
	printf("%d | %d\n\n", len1, len2);
	// printf(" | %p\n", &str);

	len1 = ft_printf("Test %%d  | %d\n", n);
	len2 = printf("Test %%d  | %d\n", n);
	printf("%d | %d\n\n", len1, len2);
	// printf(" | %d\n", n);

	len1 = ft_printf("Test %%i  | %i\n", n);
	len2 = printf("Test %%i  | %i\n", n);
	printf("%d | %d\n\n", len1, len2);
	// printf(" | %i\n", n);

	len1 = ft_printf("Test %%u  | %u\n", n);
	len2 = printf("Test %%u  | %u\n", n);
	printf("%d | %d\n\n", len1, len2);
	// printf(" | %u\n", n);

	len1 = ft_printf("Test %%x  | %x\n", n);
	len2 = printf("Test %%x  | %x\n", n);
	printf("%d | %d\n\n", len1, len2);
	// printf("  | %x\n", n);

	len1 = ft_printf("Test %%X  | %X\n", n);
	len2 = printf("Test %%X  | %X\n", n);
	printf("%d | %d\n\n", len1, len2);
	// printf("  | %X\n", n);

	len1 = ft_printf("Test  %%\n");
	len2 = printf("Test  %%\n");
	printf("%d | %d\n\n", len1, len2);
	// printf("  | %%\n");

	len1 = ft_printf("Test invalid input: %d\n", str);
	// len2 = printf("Test invalid input: %d\n", str);
	printf("%d\n\n", len1);

	len1 = ft_printf("Test not supported function: %b end.\n", 'a');
	printf("%d\n\n", len1);
	return (0);
}
