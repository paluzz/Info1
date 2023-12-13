#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CANT ((int)3)
struct persona
{
    char *nombre;
    int edad;
    char sexo;
};

struct persona *ingreso(int dataCant)
{
    int i;
    char nombre[16];

    struct persona *datos;
    datos = (struct persona *)malloc(sizeof(struct persona) * dataCant);
    if (datos == NULL)
    {
        return NULL;
    }

    for (i = 0; i < dataCant; i++)
    {
        printf("%d. Ingrese nombre: ", i + 1);
        scanf("%s", nombre);
        //  pedimos memoria
        (datos + i)->nombre = (char *)malloc(sizeof(char) * strlen(nombre));
        if ((datos + i)->nombre == NULL)
        {
            return NULL;
        }
        else
        {
            strcpy((datos + i)->nombre, nombre);
            printf("%d. Ingrese edad: ", i + 1);
            scanf("%d", &((datos + i)->edad));
            printf("%d. Ingrese sexo: ", i + 1);
            scanf("%*c%c", &((datos + i)->sexo));
            printf("\n");
        }
    }
    return datos;
}

void imprimir(struct persona *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        printf("%d. nombre: %s edad: %d sexo: %c\n", i + 1, (p + i)->nombre, (p + i)->edad, (p + i)->sexo);
    }
}

void liberar(struct persona *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        free((p + i)->nombre);
    }
    free(p);
}

void ordenar(struct persona *p, int dataCant)
{
    struct persona aux;

    for (int i = 0; i < (dataCant - 1); i++)
    {
        for (int j = i + 1; j < dataCant; j++)
        {
            // pedimos que a[] > b[]
            if (strcmp(((p + i)->nombre), ((p + j)->nombre)) > 0)
            {
                memcpy(&aux, (p + j), sizeof(struct persona));
                memcpy((p + j), (p + i), sizeof(struct persona));
                memcpy((p + i), &aux, sizeof(struct persona));
            }
        }
    }
}

int main(void)
{
    struct persona *usuario = ingreso(CANT);
    // impresion datos
    printf("\n PRIMERA IMPRESION:\n");
    imprimir(usuario, CANT);

    // ordenamos alfabeticamente
    ordenar(usuario, CANT);

    // impresion datos
    printf("\n SEGUNDA IMPRESION:\n");
    imprimir(usuario, CANT);

    // liberamos memoria
    liberar(usuario, CANT);

    return 0;
}