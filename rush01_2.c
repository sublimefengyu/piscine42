#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char			**ft_split(char *str, char *charset);
void            ft_putstr(char *str);

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
        i++;
    return i;
}

int    ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb > 1)
        return (nb * ft_recursive_factorial(nb - 1));
    return (1);
}

char    *permut_tab(int n)
{
    char *str;
    
    str = (char *)malloc(sizeof(char) * (n + 1));
    str[n] = 0;
    while(n--)
        str[n] = '1' + n;
    return str;
}

int        ft_permut(char    *tab, int    size, int    r, char        ***permu)
{
    char    **perm;
    char    temp;
    int    i;
    
    perm = *permu;
    if (size==1)
    {
        i = -1;
        while(tab[++i])
            perm[r][i] = tab[i];
        printf("%s\n", tab);
        return (r + 1);
    }
    else
    {
        i = 0;
        while (i < size)
        {
            r = ft_permut(tab, size - 1, r, &perm);
            if (size % 2 == 1)
            {
                temp = tab[0];
                tab[0] = tab[size - 1];
                tab[size - 1] = temp;
            }
            else
            {
                temp = tab[i];
                tab[i] = tab[size - 1];
                tab[size - 1] = temp;
            }
            i++;
        }
        return r;
    }
}


int				check_good_permu(char *permu, char cond1, char cond2, int size)
{
    int i;
    int c;
    char temp;
    
    i = 0;
    c = 1;
    temp = *permu;
    while (++i < size)
    {
        if (temp < *(permu + i))
        {
            c++;
            temp = *(permu + i);
        }
    }
    if (c + '0' != cond1)
        return (0);
    c = 1;
    temp = *(permu + size - 1);
    while (i-- > 0)
    {
        if (temp < *(permu + i))
        {
            temp = *(permu + i);
            c++;
        }
    }
    if (c + '0' != cond2)
        return (0);
    return (1);
}

int				check_good_ligne(int ligne, char **res, char cond1, char cond2)
{
    int i;
    int c;
    char temp;
    int size;
    
    size = ft_strlen(*res);
    i = 0;
    c = 1;
    temp = *(*(res) + ligne);
    while (++i < size)
    {
        if (temp < *(*(res + i) + ligne))
        {
            c++;
            temp = *(*(res + i) + ligne);
        }
    }
    if (c + '0' != cond1)
        return (0);
    c = 1;
    temp = *(*(res + size - 1) + ligne);
    i--;
    while (i-- > 0)
    {
        if (temp < *(*(res + i) + ligne))
        {
            temp = *(*(res + i) + ligne);
            c++;
        }
    }
    if (c + '0' != cond2)
        return (0);
    return (1);
}

int					rush(char **permu, char **para, int c, char **res)
{
    printf("rush\n");
    int i;
    int size;
    int k;
    int r;
    
    k = 0;
    i = -1;
    size = ft_strlen(*permu);
    r = 0;
    if (c == size)
    {
        while (++i < size)
            k += check_good_ligne(i, res, *(*(para + i + 2*size)), *(*(para + i + 3*size)));
        if (k == size)
        {
            i = -1;
            while (++i < size)
            {
                ft_putstr(*(res + i));
                write(1,"\n",1);
            }
            return (r + 1);
        }
        return (r);
    }
    else
    {
        i = -1;
        while (++i < ft_recursive_factorial(size) && r == 0)
            if (check_good_permu(*(permu + i), *(*(para + c)), *(*(para + c + size)), size))
            {
                    k = -1;
                    while (++k < size)
                        *(*(res + c) + k) = *(*(permu + i) + k);
                    r = rush(permu, para, c + 1, res);
                    if (r)
                        return r;
            }
        return (r);
    }
}

int			main(int argc, char **argv)
{
    int tablesize;
    char **perm;
    char **res;
    int size;
    int i;
    
    size = 4;
    if (argc == 3)
    {
        size = atoi(argv[2]);
        argc--;
    }
    if (argc != 2)
        return 1;
    i = 0;
    tablesize = ft_recursive_factorial(size);
    perm = (char**)malloc(sizeof(char*) * (tablesize + 1));
    *(perm + tablesize) = NULL;
    res = (char**)malloc(sizeof(char*) * (size + 1));
    *(res + size) = NULL;
    while (i < tablesize)
    {
        *(perm + i) = (char*)malloc(sizeof(char) * (size + 1));
        *(*(perm + i) + size) = '\0';
        i++;
    }
    i = -1;
    while (++i < size)
    {
        *(res + i) = (char*)malloc(sizeof(char) * (size + 1));
        *(*(res + i) + size) = '\0';
    }
    ft_permut(permut_tab(size), size, 0, &perm);
    i = rush(perm, ft_split(argv[1], " "), 0, res);
    if (i == 0)
        ft_putstr("Error \n");
}
