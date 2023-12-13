#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CANT ((int)3)
struct finales
{
    char materia[16];
    int nota;
};
struct estudiante
{
    char nombre[16];
    int cantFinales;
    struct finales *final;
};

struct estudiante *ingreso(int dataCant)
{
    int i, j, cantFinales = 0, flag = 1;
    struct estudiante *alumno;
    alumno = (struct estudiante *)malloc(sizeof(struct estudiante) * dataCant);
    struct finales *aux = NULL;
    if (alumno == NULL)
    {
        return NULL;
    }
    for (i = 0; i < dataCant; i++)
    {
        printf("%d.Nombre estudiante: ", (i + 1));
        scanf("%s", (alumno + i)->nombre);
        (alumno + i)->final = (struct finales *)malloc(sizeof(struct finales) * 1);
        if ((alumno + i)->final != NULL)
        {
            for (j = 0, flag = 1, cantFinales = 0; flag == 1; j++)
            {
                aux = realloc((alumno + i)->final, sizeof(struct finales) * (j + 1));
                (alumno + i)->final = aux;
                printf("Ingrese materia: ");
                scanf("%s", ((alumno + i)->final + j)->materia);
                printf("Ingrese nota: ");
                scanf("%d", &((alumno + i)->final + j)->nota);
                cantFinales++;
                if (((alumno + i)->final + j)->nota == -1)
                {
                    flag = 0;
                    cantFinales--;
                }
            }
            (alumno + i)->cantFinales = cantFinales;
            printf("\n");
        }
    }
    return alumno;
}

void imprimir(struct estudiante *p, int dataCant)
{
    printf("Impresion de datos: \n");
    for (int i = 0; i < dataCant; i++)
    {
        printf("\nNombre: %s\n", (p + i)->nombre);
        for (int j = 0; j < (p + i)->cantFinales; j++)
        {
            printf("Materia: %s  nota: %d\n", (p + i)->final[j].materia, (p + i)->final[j].nota);
        }
    }
}
int main(void)
{
    struct estudiante *alumno = ingreso(CANT);
    // imprimir
    imprimir(alumno, CANT);
    // liberar memoria
    for (int i = 0; i < CANT; i++)
    {
        free(alumno[i].final);
    }
    free(alumno);

    return 0;
}