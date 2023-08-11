#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT ((int)20)
#define FALSE ((int)-999)
// prototipos
int aleatorio();
int rango(int, int, int);
int baseDatos(int, int[]);

int main(void)
{
    int num = aleatorio();
    int adivinacion, flag = 0, i = 0;
    int v[CANT];

    printf("Adivine el numero aleatorio entre 0-9:  ");

    while (!flag)
    {
        scanf("%d", &adivinacion);
        v[i] = adivinacion;

        if (adivinacion == rango(adivinacion, 0, 9))
        {
            if (adivinacion == baseDatos(adivinacion, v))
            {
                printf("Numero repetido!\nIntentalo de nuevo: ");
            }
            else
            {
                if (num == adivinacion)
                {
                    printf("Correcto!!, el numero era %d\n", num);
                    flag = 1;
                }
                else
                {
                    printf("Fallaste!!\nIntentalo de nuevo: ");
                }
                i++;
            }
        }
        else
        {
            printf("Fuera de rango\nIntentalo de nuevo: ");
        }
    }

    return 0;
}

int aleatorio()
{
    srand(time(NULL));
    // filtramos el ultimo digito
    return (rand() % 10);
}

int rango(int a, int b, int c)
{
    return (a >= b && a <= c) ? a : FALSE;
}

int baseDatos(int input, int v[])
{
    int contador = 0;
    for (int i = 0; i < CANT; i++)
    {
        if (v[i] == input)
        {
            contador++;
        }
    }
    return contador > 1 ? input : FALSE;
}