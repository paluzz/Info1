#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    char linea[200], texto[2000], *p;
    int aux;

    // Leemos ejercicio
    fp = fopen("./../capitulo20/ejercicio20_01.c", "r");
    if (fp == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }

    // copiamos en texto[]
    while (!feof(fp))
    {
        p = fgets(linea, sizeof(linea), fp);
        if (p == NULL)
        {
            printf("Error al leer\n");
            return (-2);
        }
        else
        {
            // hago strcat en vez de printf porque no me imprimia el ultimo caracter
            strcat(texto, linea);
        }
    }
    aux = strlen(texto);
    texto[aux] = '\0';

    // mostramos en terminal
    printf("%s\n", texto);
    // cerramos
    aux = fclose(fp);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
        return (-3);
    }

    return (0);
}