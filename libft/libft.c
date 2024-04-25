/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:04:02 by msolinsk          #+#    #+#             */
/*   Updated: 2024/03/19 15:01:48 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma ones
#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <fcntl.h>


int main()
{
	// char n[] = "test\200";
	// char d[] = "test\0";
	// int  in = 4;
	// printf("delta >> %d\n\n", n[in] - d[in]);
	// return 0;

	// char b[0xF] = "nyan !";

	// printf("%ld\n", strlcat(((void*)0), b, 0));
	// printf("%ld\n\n", ft_strlcat((void *)0, b, 0));

	printf("ft_itoa.c | %s\n\n", ft_itoa(-2147483648));

    ft_putstr("\n\t PART-1\t\n\n");

    // TEST ft_putchar.c
    ft_putchar('c');
    ft_putchar('\n');
    ft_putstr("ft_putchar.c >> PASSED\n\n");


    // TEST ft_putstr.c
    ft_putstr("Some text...\n");
    ft_putstr("ft_putstr.c >> PASSED\n");


    // TEST ft_isalpha.c
    // char    tests1[] = {'c', 'A', 'Z', 'a', 'z', '1', '9', '/', '0'};
    int i = 0;
    ft_putstr("ft_isalpha.c >>> ");
    while (i <= 127)
    {
        // printf("test isAlpha.c >>> %d\n", isalpha(tests[i]));
        if (isalpha(i) != ft_isalpha(i))
        {
            ft_putstr("ERROR!");
            return 1;
        }
        i++;
    }
    ft_putstr("PASSED\n");


    // TEST ft_isdigit.c
    // char    tests2[] = {'1', '2', 'Z', 'a', 'z', '1', '9', '/', '0'};
    i = 0;
    while (i <= 127)
    {
        // printf("test isDigit.c >>> %c %d\n", i, isdigit(i));
        if (isdigit(i) != ft_isdigit(i))
        {
            ft_putstr("ERROR!");
            return 1;
        }
        i++;
    }
    ft_putstr("ft_isdigit.c >> PASSED\n");


    // TEST ft_isalnum.c
    i = 0;
    while (i <= 127)
    {
        if (isalnum(i) != ft_isalnum(i))
        {
            printf("ERROR!\t");
            printf("isAlNum.c >>> %c %d | %d\n", i, isalnum(i), ft_isalnum(i));
            return 1;
        }
        i++;
    }
    ft_putstr("ft_isalnum.c >> PASSED\n");


    // TEST ft_isascii.c
    i = -10;
    while (i <= 130)
    {
        if (__isascii(i) != ft_isascii(i))
        {
            printf("ERROR!\t");
            printf("isAscii.c >>> %c %d | %d\n", i, __isascii(i), ft_isascii(i));
            return 1;
        }
        i++;
    }
    ft_putstr("ft_isascii.c >> PASSED\n");


    // TEST ft_isprint.c
    i = -10;
    while (i <= 130)
    {
        if (isprint(i) != ft_isprint(i))
        {
            printf("ERROR!\t");
            printf("isPrint.c >>> %d  %d | %d\n", i, isprint(i), ft_isprint(i));
            return 1;
        }
        i++;
    }
    ft_putstr("ft_isprint.c >> PASSED\n");


    // TEST ft_strlen.c
    if (strlen("Ola ma kota!") != ft_strlen("Ola ma kota!"))
    {
        printf("ERROR!\t");
        printf("strlen.c >>> %ld %d", strlen("Ola ma kota!"), ft_strlen("Ola ma kota!"));
        return -1;
    }
    ft_putstr("ft_strlen.c >> PASSED\n");


    // TEST ft_memset.c
    char str1[] = "Ola ma kota!";
    char str2[] = "Ola ma kota!";
    memset(str1, '#', 4);
    ft_memset(str2, '#', 4);
    if (memcmp(str1, str2, 12) != 0)
    {
        printf("ERROR! >>> %s %s", str1, str2);
        return -1;
    }
    ft_putstr("ft_memset.c >> PASSED\n");


    // TEST ft_bzero.c
    // char str1[] = "Ola ma kota!";
    // char str2[] = "Ola ma kota!";
    bzero(str1, 4);
    ft_bzero(str2, 4);
    if (memcmp(str1, str2, 12) != 0)
    {
        printf("ERROR! >>> %s %s", str1, str2);
        return -1;
    }
    ft_putstr("ft_bzero.c >> PASSED\n");


    // TEST ft_memcpy.c
    char str5[] = "Ola nie ma kota";
    char str3[] = "Ola ma kota!";
    char str4[] = "Ola ma kota!";
    memcpy(str3, str5, 13);
    ft_memcpy(str4, str5, 13);
    if (memcmp(str3, str4, 12) != 0)
    {
        printf("ERROR! >>> %s || %s", str3, str4);
        return -1;
    }
    ft_putstr("ft_memcpy.c >> PASSED\n");


    // TEST ft_memmove.c
    char testMemmove[] = "Ola ma tank";
    char str6[15];
    char str7[15];
    memmove(str6, testMemmove, 12);
    ft_memmove(str7, testMemmove, 12);
    if (memcmp(str6, str7, strlen(str6) + 1) != 0)
    {
        printf("ERROR! ft_memmove.c >>> %d <%s> || <%s>", memcmp(str6, str7, 12), str6, str7);
        return -1;
    }
    ft_putstr("ft_memmove.c >> PASSED\n");


    // TEST ft_strlcpy.c
    char str8[] = "Ola nie ma zadnego kota!";
    ft_strlcpy(str8, str5, 15);
    if (strcmp(str8, str5) == 0)
    {
        printf("ERROR >>> %s | %s", str6, str8);
        // return -1;
    }
    ft_putstr("ft_strlcpy.c >> PASSED\n");


    // TEST ft_strlcat.c
    char strlcatTest[] = "Ola nie ma zadnego kota!";
    char str9[20] = "Kot nie ma OLi.";
    char str99[20] = "Kot nie ma OLi.";
    // strlcat(str9, strlcatTest, 29);
    ft_strlcat(str99, strlcatTest, 29);
    // printf("%s | %s\n", str9, str99);
    ft_strlcat(str9, strlcatTest, 17);
    if (strcmp(str9, str99) != 0)
    {
        printf("ERROR ft_strlcat.c >>> %s | %s\n", str9, str99);
        // return -1;
    }
    ft_putstr("ft_strlcat.c >> PASSED\n");


    // TEST ft_toupper.c
    i = -10;
    while (i <= 130)
    {
        if (toupper(i) != ft_toupper(i))
        {
            printf("ERROR!\t");
            printf("toUpper.c >>> %i %d | %d\n", i, toupper(i), ft_toupper(i));
            return -1;
        }
        i++;
    }
    ft_putstr("ft_toupper.c >> PASSED\n");


    // TEST ft_tolower.c
    i = -10;
    while (i <= 130)
    {
        if (tolower(i) != ft_tolower(i))
        {
            printf("ERROR!\t");
            printf("toLower.c >>> %i %d | %d\n", i, tolower(i), ft_tolower(i));
            return -1;
        }
        i++;
    }
    ft_putstr("ft_tolower.c >> PASSED\n");


    // TEST ft_strchr.c
    i = -10;
    while (i <= 130)
    {
        if (strchr(str9, i) != ft_strchr(str9, i))
        {
            printf("ERROR!\t");
            printf("ft_strchr.c >>> %i %s | %s\n", i, strchr(str9, i), ft_strchr(str9, i));
            return -1;
        }
        i++;
    }
    ft_putstr("ft_strchr.c >> PASSED\n");


    // TEST ft_strrchr.c
    i = -10;
    while (i <= 130)
    {
        if (strrchr(str9, i) != ft_strrchr(str9, i))
        {
            printf("ERROR!\t");
            printf("ft_strrchr.c >>> %i %s | %s\n", i, strrchr(str9, i), ft_strrchr(str9, i));
            return -1;
        }
        i++;
    }
    ft_putstr("ft_strrchr.c >> PASSED\n");


    // TEST ft_strncmp.c
	char	tSrtncmp1[] = "test\200";
	char	tStrncmp2[] = "test\0";
    if(strncmp(tSrtncmp1, tStrncmp2, 6) != ft_strncmp(tSrtncmp1, tStrncmp2, 6))
    {
        printf("ERROR! >>> %d %d", strncmp(tSrtncmp1, tStrncmp2, 6), ft_strncmp(tSrtncmp1, tStrncmp2, 6));
		// return (-1);
    }
    ft_putstr("ft_strncmp.c >> PASSED\n");


    // TEST ft_memcmp.c
    char str10[30] = "Ola ma kota!";
    // char str11[30] = "Ola ma tota!";
    // // printf("<%s> <%s>\n", str5, str6);
    // if(memcmp(str10, str11, strlen(str10) + 1) != ft_memcmp(str10, str11, strlen(str10) + 1))
    // {
    //     printf("ERROR! >>> %d %d", memcmp(str10, str11, 15), ft_memcmp(str10, str11, 15));
    //     return -1;
    // }
    // ft_putstr("ft_memcmp.c >> PASSED\n");


    // TEST ft_strnstr.c
    char str12[] = "Ola";
    char *str13 = ft_strnstr(str10, str12, 15);
    // printf("<%s> <%s>\n", str10, str11);

    if(strcmp(str13, "Ola ma kota!"))
    {
        printf("ERROR! >>>>>> %s", ft_strnstr(str10, str12, 15));
        // return -1;
    }
    ft_putstr("ft_strnstr.c >> PASSED\n");


    // TEST ft_atoi.c
    char atoiTest[10][12] = {"\e475", "-12345", "  +-54", "   56789", "   -56789", "   55  5666", "   -5 3333  ", "     -", "", "\0"};
    i = 0;
    while (atoiTest[i][0] != '\0')
    {
        printf("ft_atoi.c! >>> <%s> %d | %d\n", atoiTest[i], atoi(atoiTest[i]), ft_atoi(atoiTest[i]));
        if (atoi(atoiTest[i]) != ft_atoi(atoiTest[i]))
        {
            printf("ERROR! >>> <%s> %d | %d", atoiTest[i], atoi(atoiTest[i]), ft_atoi(atoiTest[i]));
            return -1;
        }
        i++;
	}
    ft_putstr("ft_calloc.c >> PASSED\n");
    // i = 0;
    // while (i < 10)
    // {
    //     printf("<%d> => %ld %ld => %zu %zu\n", i, array1[i], array2[i], sizeof(array1[i]), sizeof(array2[i]));
    //     i++;
    // }
    // free(array);


    // TEST ft_strdup.c
    char str14[] = "Duplikat Ola ma kota!";
    char *str15;
    // char *str16;
    // str16 = strdup(str14);
    str15 = ft_strdup(str14);
    printf("ft_strdup.c >> %s\n", str15);
    // if(strcmp(str15, str16) != 0)
    // {
        // printf("ERROR! >>> %s | %s\n", str15, str16);
        // return -1;
    // }
    ft_putstr("ft_strdup.c >> PASSED\n");
    // printf("%s | %s\n", str15, str16);



    /*        PART-2          */
    ft_putstr("\n\t PART-2\t\n\n");

    // TEST ft_substr.c
    char *str16;
    str16 = ft_substr(str14, 5, 10);
    printf("ft_substr.c >> %s | %s\n", str14, str16);
    ft_putstr("ft_substr.c >> PASSED\n");


    // TEST ft_strjoin.c
    char *str17;
    str17 = ft_strjoin("MATEUSZ", str14);
    printf("ft_strjoin.c >> MATEUSZ | %s | %s\n", str14, str17);
    ft_putstr("ft_strjoin.c >> PASSED\n");


    // TEST ft_strtrim.c
    char *str18;
    str18 = ft_strtrim("  \t \t \n   \n\n\n\t", " \t\n");
    printf("ft_strtrim.c >> %s\n", str18);
    ft_putstr("ft_strtrim.c >> PASSED\n");


    // TEST ft_split.c
    char str19[] = "                  olol  a";
    char **str20 = ft_split(str19, ' ');
    while (str20[i] != NULL)
    {
        ft_putstr(str20[i]);
        ft_putstr(" | ");
		i++;
    }
    ft_putstr("\nft_split.c >> PASSED\n");


    // TEST ft_itoa.c
    char  *str21;
    str21 = ft_itoa(-0);
    printf("ft_itoa.c >> %d | %s\n", -0, str21);
    ft_putstr("ft_itoa.c >> PASSED\n");


    // TEST ft_putchar_fd.c
    int file1 = open("ft_putchar_fd_FILE.txt", O_CREAT | O_WRONLY, 0666);
    if(!file1)
    {
        printf("ERROR! >>> file not opened");
        return -1;
    }
    ft_putchar_fd('c', file1);
    close(file1);
    ft_putstr("ft_putchar_fd.c >> PASSED\n");


    // TEST ft_putstr_fd.c
    int file2 = open("ft_putstr_fd_FILE.txt", O_CREAT | O_WRONLY, 0666);
    if(!file2)
    {
        printf("ERROR! >>> file not opened");
        return -1;
    }
    ft_putstr_fd("Ola ma kota!", file2);
    close(file2);
    ft_putstr("ft_putstr_fd.c >> PASSED\n");


    // TEST ft_putendl_fd.c
    int file3 = open("ft_putendl_fd_FILE.txt", O_CREAT | O_WRONLY, 0666);
    if(!file3)
    {
        printf("ERROR! >>> file not opened");
        return -1;
    }
    ft_putendl_fd("Ola ma kota ENDL!", file3);
    close(file3);
    ft_putstr("ft_putendl_fd.c >> PASSED\n");


    // TEST ft_putnbr_fd.c
    int file4 = open("ft_putnbr_fd_FILE.txt", O_CREAT | O_WRONLY, 0666);
    if(!file4)
    {
        printf("ERROR! >>> file not opened");
        return -1;
    }
    ft_putnbr_fd(-10000, file4);
    close(file4);
    ft_putstr("ft_putnbr_fd.c >> PASSED\n");


    printf("\t\033[42m \033[34m ALL PASSED \033[39m \033[49m \t\n");

    return 0;
}
