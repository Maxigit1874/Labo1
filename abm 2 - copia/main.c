#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Alumno.h"

#define TAM 10




int cargarDescCarrera(int idCarrera, eCarrra carreras[], int tam, char descripcion[]);

int menu();


int main()
{

    eAlumno lista[TAM];
    eCarrera carreras[] = {{1000, "TUP"},{1001, "TUSI"},{1002, "LIC"}};
    int legajo = 20000;
    char salir = 'n';


    inicializarAlumnos(lista, TAM);

    legajo = legajo + hardcodearAlumnos (lista, TAM, 10);



    do
    {
        switch(menu())
        {
        case 1:
            // aca va el alta alumno
            //altaAlumno(lista, TAM);
            if(altaAlumnoAuto(lista, TAM, legajo))
            {
                legajo++;
            }
            break;
        case 2:
            bajaAlumno(lista, TAM);
            break;
        case 3:
            modificarAlumno(lista, TAM);
            // aca va modificar alumno
            break;
        case 4:
            mostrarAlumnos(lista, TAM);
            // aca va el alta alumno
            break;
        case 5:
            ordenarAlumnos(lista, TAM);
            // aca va el alta alumno
            break;
        case 6:
            printf("Informes\n");
            // aca va el alta alumno
            break;
        case 7:
            mostrarCarreras(carreras, 3);
            break;

        case 8:
            printf("Corfirma Salida?");
            fflush(stdin);
            salir = getch();
            // aca va el alta alumno
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}



int menu()
{

    int opcion;
    system("cls");
    printf("--Menu de Opciones--\n\n");
    printf("1- Alta Alumno\n");
    printf("2- Baja Alumno\n");
    printf("3- Modificar Alumno\n");
    printf("4- Listar Alumnos\n");
    printf("5- Ordenar Alumno\n");
    printf("6- Informes\n");
    printf("7- Mostrar carreras\n");
    printf("8- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



