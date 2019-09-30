#include "Comida.h"


void mostrarComidas(eComida comidas[], int tam){
    printf(" Id   Descripcion\n\n");
    for(int i=0; i < tam; i++){
        mostrarComida( comidas[i]);
    }
    printf("\n");
}

void mostrarComida(eComida comida){

    printf("  %d      %10s\n", comida.id, comida.descripcion);

}


int cargarDescComida(int id, eComida comidas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
