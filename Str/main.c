#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[10];
    char auxCad[100];



    printf ("ingrese  nombre: ");
    gets (auxCad);

    while  (strlen (auxCad) > 9){

        printf ("Error. nombre demasiado largo reingrese.");
        gets(auxCad);
    }
    strcpy(nombre, auxCad);

    printf ("%s\n", nombre);

    return 0;
}

