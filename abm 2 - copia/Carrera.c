#include "Carrera.h"

void mostrarCarreras(eCarrera carreras[], int tam){

    printf ("\nId:    Descripcion: \n\n");
    for (int i = 0 ; i < tam ; i++){

        mostrarCarrera(carreras[i]);
    }
    printf ("\n\n");
}


void mostrarCarrera(eCarrera carrera){

    printf ("%d   %s\n", carrera.id, carrera.descripcion);


}
