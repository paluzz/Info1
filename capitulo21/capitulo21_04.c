/*
    CONCLUSIONES:
    - cat ./bDatos.txt :
        El archivo se ve en formato decimal, respetando ENTER y espacios
    - hexdump ./bDatos.txt -C
        El archivo aparece en binario, no se imprimen los ENTER en el texto, pero si aparece su binario
        como el /r '0d' y /n '0a'

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATOS "./bDatos.txt"
#define CANT 10

struct usuario
{
    char *nombre;
    int edad;
};

struct usuario *ingreso(int dataCant)
{
    char nombre[32];
    struct usuario *p;
    p = (struct usuario *)malloc(sizeof(struct usuario) * dataCant);
    if (p == NULL)
    {
        printf("Error ingreso");
        return NULL;
    }
    // pedimos datos y los guardamos
    for (int i = 0; i < CANT; i++)
    {
        printf("ingrese nombre: ");
        scanf("%s", nombre);
        (p + i)->nombre = (char *)malloc(sizeof(char) * strlen(nombre));
        strcpy((p + i)->nombre, nombre);

        printf("ingrese edad: ");
        scanf("%d", &(p + i)->edad);
    }
    return p;
}
void liberar(struct usuario *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        free((p + i)->nombre);
    }
    free(p);
}

int main(void)
{
    FILE *fp;
    int i, r;

    // ingresamos datos
    struct usuario *user = ingreso(CANT);

    // abrimos archivo
    fp = fopen(DATOS, "w");
    if (fp == NULL)
    {
        printf("error ruta\n");
        return -1;
    }

    // hacemos cosas
    for (int i = 0; i < CANT; i++)
    {
        r = fprintf(fp, "%s,%d\r\n", (user + i)->nombre, (user + i)->edad);
        if (r < 0)
        {
            printf("error al escribir\n");
            return -2;
        }
    }
    // cerramos
    fclose(fp);

    // liberamos estructura
    liberar(user, CANT);

    return 0;
}