#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        // fgets(nombre, strlen(nombre), stdin);
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

int main(void)
{
    int i;
    struct persona *usuario = ingreso(10);
    // impresion datos
    for (i = 0; i < 10; i++)
    {
        printf("%d. nombre: %s edad: %d sexo: %c\n", i + 1, usuario[i].nombre, usuario[i].edad, usuario[i].sexo);
    }

    // liberamos memoria
    for (i = 0; i < 10; i++)
    {
        free(usuario[i].nombre);
    }
    free(usuario);

    return 0;
}