#include "../includes/fillit.h"

char    **filled_new(char **elem, char **new_elem)
{
    int i;
    int j;

    i = 0;
    while (new_elem[i])
    {
        j = 0;
        while (new_elem[i][j])
        {
            new_elem[i][j] = 'A';
            j++;
        }
        i++;
    }
    return (new_elem);
}
