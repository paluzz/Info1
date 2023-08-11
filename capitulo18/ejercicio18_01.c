#include <stdio.h>
#include <string.h>

void ordenarChar(char *dataPtr, int dataCant)
{
    char temp;
    int i, j;
    for (i = 0; i < (dataCant - 1); i++)
    {
        for (j = i + 1; j < dataCant; j++)
        {
            if (*(dataPtr + i) > *(dataPtr + j))
            {
                temp = *(dataPtr + j);
                *(dataPtr + j) = *(dataPtr + i);
                *(dataPtr + i) = temp;
            }
        }
    }
}

int main()
{
    char v[] = "sadertjklzxxcsaqweasd";
    int cant[] = {8, 7, 19, 12, 15};
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("Antes de ordenar: %s\n", v);
        ordenarChar(v, cant[i]);
        printf("Despues de ordenar: %s\n", v);
        strcpy(v, "sadertjklzxxcsaqweasd");
    }

    return 0;
}