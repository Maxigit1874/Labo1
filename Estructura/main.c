#include <stdio.h>
#include <stdlib.h>

int main()
{

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct{

    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaingreso;

}eAlumno;


    eAlumno alumno1; //= {1245, "Juan", 22, 'm', 7, 5, 6, {5,3,2019}};
    eAlumno alumno2;

    printf ("Ingrese nombre: ");
    gets(alumno1.nombre);

    printf ("Ingrese legajo: ");
    scanf("%d", &alumno1.legajo);

    printf ("Ingrese edad: ");
    scanf("%d", &alumno1.edad);


    printf ("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &alumno1.sexo);


    printf ("Ingrese nota parcial 1: ");
    scanf("%d", &alumno1.nota1);

    printf ("Ingrese nota parcial 2: ");
    scanf("%d", &alumno1.nota2);

    printf("Ingrese dia de ingreso: ");
    scanf ("%d", &alumno1.fechaingreso.dia);

    printf("Ingrese mes de ingreso: ");
    scanf ("%d", &alumno1.fechaingreso.mes);

    printf("Ingrese anio de ingreso: ");
    scanf ("%d", &alumno1.fechaingreso.anio);


    alumno1.promedio = (float) (alumno1.nota1 + alumno1.nota2) / 2;

    printf ("Nombre: %s\nLegajo: %d\nEdad: %d\nSexo: %c\nNota 1: %d\nNota 2: %d\nPromedio: %.2f\nFecha ingreso: %02d/%02d/%d", alumno1.nombre , alumno1.legajo, alumno1.edad, alumno1.sexo, alumno1.nota1, alumno1.nota2, alumno1.promedio, alumno1.fechaingreso.dia, alumno1.fechaingreso.mes, alumno1.fechaingreso.anio);


    return 0;
}
