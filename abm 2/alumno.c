#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Alumno.h"

void mostrarAlumno(eAlumno x)
{
    printf("  %d  %10s      %2d    %c     %2d     %2d     %3.2f      %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag = 0;
    system("cls");
    printf("**** Listado de Alumnos ****\n\n");

    printf(" Legajo      Nombre     Edad  Sexo  Nota1  Nota2  Promedio   FIngreso\n\n");
    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        system("cls");
        printf("\n---No hay alumnos que mostrar---");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{

    eAlumno auxAlumno;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].promedio > vec[j].promedio && vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
    printf ("\nAlumnos ordenados por promedio\n\n");
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
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarAlumnos(eAlumno alumnos[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        alumnos[i].isEmpty = 1;
    }
}

int buscarLibre(eAlumno alumnos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno alumnos[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( alumnos[i].isEmpty == 0 && alumnos[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno alumnos[], int tam)
{

    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("**** Alta Alumno ****\n\n");

    indice = buscarLibre(alumnos, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }
    else
    {
        printf("\nIngrese legajo: ");
        scanf("%d", &legajo );

        esta = buscarAlumno(legajo, alumnos, tam);

        if( esta != -1)
        {
            printf("\nLegajo ya registrado\n");
            mostrarAlumno(alumnos[esta]);
            system("pause");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets( nombre );

            printf("Ingrese edad:");
            scanf("%d", &edad);

            printf("Ingrese sexo:");
            fflush(stdin);
            scanf("%c", &sexo);

            printf("Ingrese nota parcial 1:");
            scanf("%d", &nota1);

            printf("Ingrese nota parcial 2:");
            scanf("%d", &nota2);

            printf("Ingrese fecha ingreso: dd/mm/aaaa ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

            alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, fecha);
            todoOk = 1;
        }
    }
    return todoOk;
}

eAlumno newAlumno(int legajo, char nombre[], char sexo, int edad, int n1, int n2, eFecha fecha)
{
    eAlumno nuevoAlumno;
    nuevoAlumno.legajo = legajo;
    strcpy(nuevoAlumno.nombre, nombre);
    nuevoAlumno.edad = edad;
    nuevoAlumno.sexo = sexo;
    nuevoAlumno.nota1 = n1;
    nuevoAlumno.nota2 = n2;
    nuevoAlumno.promedio = (float) (n1 + n2) / 2;
    nuevoAlumno.fechaIngreso = fecha;
    nuevoAlumno.isEmpty = 0;

    return nuevoAlumno;
}

int bajaAlumno(eAlumno alumnos[], int tam)
{

    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    system("cls");
    printf("**** Baja Alumno ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        mostrarAlumno(alumnos[indice]);
        printf("\nConfirma eliminacion?: ");
        fflush(stdin);
        confirma = getche();
        if( confirma == 's')
        {
            alumnos[indice].isEmpty = 1;
            printf("\n\nSe ha eliminado el alumno\n");
            todoOk = 1;
        }
        else
        {
            printf("\n\nSe ha cancelado la baja\n");
        }
        system("pause");
    }
    return todoOk;
}


int modificarAlumno(eAlumno alumnos[], int tam)
{

    int todoOk = 0;
    int indice;
    int legajo;
    int opcion;
    int nota;


    system("cls");
    printf("**** Modificar Alumno ****\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, alumnos, tam);

    if( indice == -1 )
    {
        printf("\nNo tenemos registrado ese legajo\n");
        system("pause");
    }
    else
    {
        mostrarAlumno(alumnos[indice]);

        printf("Modificar\n\n");
        printf("Nota parcial 1\n");
        printf("Nota parcial 2\n");

        printf("Ingrese opcion:");
        scanf("%d", &opcion);

        if( opcion == 1)
        {
            printf("Ingrese nota 1: ");
            scanf("%d", &nota);
            // falta validar nota
            alumnos[indice].nota1 = nota;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("Se actualizo la nota");
            todoOk = 1;
        }
        else if( opcion == 2)
        {
            printf("Ingrese nota 2: ");
            scanf("%d", &nota);
            // falta validar nota
            alumnos[indice].nota2 = nota;
            alumnos[indice].promedio = (float) (alumnos[indice].nota1 + alumnos[indice].nota2)/2;
            printf("Se actualizo la nota");
            todoOk = 1;

        }
        else
        {
            printf("No es una opcion valida\n");
        }

        system("pause");
    }
    return todoOk;
}

int altaAlumnoAuto(eAlumno alumnos[], int tam, int legajo)
{

    int todoOk = 0;
    int indice;


    int edad;
    int nota1;
    int nota2;
    char sexo;
    char nombre[20];
    eFecha fecha;

    system("cls");
    printf("**** Alta Alumno ****\n\n");

    indice = buscarLibre(alumnos, tam);

    if( indice == -1)
    {
        printf("Sistema Completo. No se pueden agregar mas alumnos\n");
        system("pause");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets( nombre );

        printf("Ingrese edad:");
        scanf("%d", &edad);

        printf("Ingrese sexo:");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota parcial 1:");
        scanf("%d", &nota1);

        printf("Ingrese nota parcial 2:");
        scanf("%d", &nota2);

        printf("Ingrese fecha ingreso: dd/mm/aaaa ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        alumnos[indice] = newAlumno(legajo, nombre, sexo, edad, nota1, nota2, fecha);
        todoOk = 1;
    }

return todoOk;
}



int hardcodearAlumnos (eAlumno alumnos[], int tam, int cantidad){

        int cont = 0;

        eAlumno listaAuxiliar[]=
        {

                {20000, "Juan", 30, 'm', 2, 10, 6,{12, 6, 2017}, 0},
                {20001, "Ana", 20, 'f', 6, 8, 7,{12, 5, 2019}, 0},
                {20002, "Pedro", 24, 'm', 5, 4, 4.5,{12, 9, 2018}, 0},
                {20003, "Carlos", 23, 'm', 6, 6, 6,{12, 5, 2015}, 0},
                {20004, "Susana", 28, 'f', 2, 4, 3,{12, 3, 2018}, 0},
                {20005, "Melisa", 19, 'f', 2, 8, 5,{12, 5, 2016}, 0},
                {20006, "Facundo", 20, 'm', 10, 10, 10,{12, 5, 2003}, 0},
                {20007, "Adrian", 24, 'm', 9, 8, 8.5,{12, 8, 2012}, 0},
                {20008, "Florencia", 31, 'f', 5, 6, 5.5,{12, 3, 2011}, 0},
                {20009, "Belen", 18, 'f', 8, 8, 8,{15, 5, 2018}, 0}


        };

        if (cantidad <= tam && cantidad < 11){

            for (int i = 0 ; i < cantidad ; i++){

                alumnos[i] = listaAuxiliar[i];
                cont ++;
            }

        }
        return cont;
}
