// gcc capitulo22_07.c  -o copiar -Wall
// ./copiar <origen> <destino>
#include <stdio.h>

int main(int args, char *argv[])
{
    if (args != 3)
    {
        printf("USO: copiar <origen> <destino> \n");
        return -1;
    }
    FILE *fpo, *fpd;
    char *origen = argv[1];
    char *destino = argv[2];
    char aux[1024];
    int cantRead, cantWrite;

    // abrimos archivos
    fpo = fopen(origen, "r");
    fpd = fopen(destino, "w");
    if (fpo == NULL || fpd == NULL)
    {
        printf("Error al ejecutar el programa\n");
        return -5;
    }
    // copiamos contenido
    while (!feof(fpo))
    {
        cantRead = fread(&aux[0], sizeof(aux[0]), 1, fpo);
        if (cantRead < 0)
        {
            printf("error lectura\n");
            return -3;
        }
        else
        {
            cantWrite = fwrite(&aux[0], sizeof(aux[0]), cantRead, fpd);
            if (cantWrite < 0)
            {
                printf("Error escritura\n");
                return -4;
            }
        }
    }

    if (cantRead == cantWrite)
    {
        printf("Archivo copiado correctamente\n");
    }
    // cerramos archivos
    fclose(fpo);
    fclose(fpd);
    return 0;
}