#include <stdio.h>
#include <string.h>
int main(void)
{
    FILE *fp;
    int cantWrite;
    char v[] = "Hola info1!!!";
    // abrimos
    fp = fopen("./prueba.txt", "w");
    if (fp == NULL)
    {
        printf("Error al abrir\n");
        return -1;
    }
    // hacemos cosas
    cantWrite = fwrite(&v[0], sizeof(v[0]), strlen(v), fp);
    // 00000000  48 6f 6c 61 20 69 6e 66  6f 31 21 21 21           |Hola info1!!!|
    // 0000000d
    // creo que no se escribio el /0 porque el strlen devuelve el tamaño sin el /0
    if (cantWrite < 0)
    {
        printf("Error escritura\n");
    }
    // cerramos
    fclose(fp);
    return 0;
}