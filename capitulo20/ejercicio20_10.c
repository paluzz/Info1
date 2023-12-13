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

void liberar(struct estudiante *p, int dataCant)
{
    for (int i = 0; i < CANT; i++)
    {
        free((p + i)->final);
    }
    free(p);
}

int buscar(struct estudiante *p, int dataCant, char *nombre, char *materia)
{
    int i, j, nombreOk = 0, materiaOk = 0, nota;

    // buscamos existencia de nombre y materia
    for (i = 0; i < dataCant; i++)
    {
        for (j = 0; j < (p + i)->cantFinales; j++)
        {
            if (strcmp(nombre, (p + i)->nombre) == 0)
            {
                nombreOk = 1;
                if (strcmp(materia, ((p + i)->final + j)->materia) == 0)
                {
                    materiaOk = 1;
                    break;
                }
            }
        }
    }

    if (nombreOk != 1)
    {
        nota = -1;
    }
    else if (materiaOk != 1)
    {
        nota = -2;
    }
    else
    {
        // buscamos la nota
        for (i = 0; i < dataCant; i++)
        {
            for (j = 0; j < (p + i)->cantFinales; j++)
            {
                if ((strcmp(nombre, (p + i)->nombre) == 0) && (strcmp(materia, ((p + i)->final + j)->materia) == 0))
                {
                    nota = ((p + i)->final + j)->nota;
                }
            }
        }
    }

    return nota;
}

int main(void)
{
    int nota;
    struct estudiante *alumno = ingreso(CANT); // no ingresar fisica o pepe

    // caso nota
    nota = buscar(alumno, CANT, "damian", "info");
    printf("La nota de damian en info es: %d\n", nota);
    // caso materia (-2)
    nota = buscar(alumno, CANT, "damian", "fisica");
    printf("La nota de damian en fisica es: %d\n", nota);
    // caso nombre (-1)
    nota = buscar(alumno, CANT, "pepe", "info");
    printf("La nota de pepe en info es: %d\n", nota);
    // liberar memoria
    liberar(alumno, CANT);
    return 0;
}