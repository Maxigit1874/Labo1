#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char nombre[20];
    char auxNom[100];
    char apellido[20];
    char auxApe [100];
    char nombreCompleto[41];
    int i = 0;

    printf ("Ingrese nombre: ");
    fflush(stdin);
    gets (auxNom);

    while (strlen(auxNom) > 19){

        printf ("Error! demasiados caracteres.");
        printf ("Ingrese nombre: ");
        fflush(stdin);
        gets (auxNom);

    }

    strcpy(nombre, auxNom);

    printf ("Ingrese apellido: ");
    fflush(stdin);
    gets (auxApe);

    while (strlen(auxApe) > 19){

        printf ("Error! demasiados caracteres.");
        printf ("Ingrese apellido: ");
        fflush(stdin);
        gets (auxApe);

    }

    strcpy(apellido, auxApe);

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0]= toupper(nombreCompleto[0]);

    while (nombreCompleto[i] != '\0'){

        if (nombreCompleto[i] == ' '){
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);

        }
        i++;

    }
    //printf ("%s", nombre);


    printf ("%s",nombreCompleto);


    return 0;
}
