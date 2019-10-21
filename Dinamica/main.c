#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* n;

    n = (int*) malloc (sizeof(int)*5);

    for (int i = 0; i < 5 ; i++){

        printf ("Ingrese numero %d: ", i+1);
        scanf ("%d",  n + i);
    }

    for (int i = 0; i < 5 ; i ++){

        printf ("%d ", n[i]);
    }

    return 0;
}
