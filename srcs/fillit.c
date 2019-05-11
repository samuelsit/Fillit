#include "../includes/fillit.h"
#include <stdio.h> // à retirer

void    fillit(char *file)
{
        int     nbTet;
        int     lenTab;

        nbTet = nbTetriminos(file);
        ft_putstr("Nombre de Tetriminos : ");
        ft_putnbr(nbTet);
        ft_putstr("\n\n");

        lenTab = ft_sqrt(nbTet * 4);
        ft_putstr("Formule lenTab : sqrt(nbTet * 4)\n");
        ft_putstr("Taille du Terrain : ");
        ft_putnbr(lenTab);
        ft_putchar('\n');

}
