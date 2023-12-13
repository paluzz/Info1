#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct persona
{
    char *nombre;
    int edad;
    char sexo;
};

int main(void)
{
    int i;
    char nombre[16];

    struct persona *datos;
    datos = (struct persona *)malloc(sizeof(struct persona) * 10);
    if (datos == NULL)
    {
        return -1;
    }

    for (i = 0; i < 10; i++)
    {
        printf("ingrese nombre #%d: ", i + 1);
        scanf("%s", nombre);
        // pedimos memoria
        datos[i].nombre = (char *)malloc(sizeof(char) * strlen(nombre));
        if (datos[i].nombre == NULL)
        {
            return -1;
        }
        else
        {
            strcpy(datos[i].nombre, nombre);
            printf("ingrese edad #%d: ", i + 1);
            scanf("%d", &(datos[i].edad));
            printf("ingrese sexo #%d:", i + 1);
            scanf("%*c%c", &(datos[i].sexo));
        }
    }

    // impresion datos
    for (i = 0; i < 10; i++)
    {
        printf("nombre #%d: %s\tedad #%d: %d\tsexo #%d: %c\n", i + 1, datos[i].nombre, i + 1, datos[i].edad, i + 1, datos[i].sexo);
    }

    // liberamos memoria
    for (i = 0; i < 10; i++)
    {
        free(datos[i].nombre);
    }
    free(datos);

    return 0;
}