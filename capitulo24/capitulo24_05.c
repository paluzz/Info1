#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILAS 3
#define COLUMNAS 3
#define VICTORIA 1
#define EMPATE 2

void matrizImprimir(char *p, int filas, int columnas)
{
    if (p != NULL)
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                printf("%c\t", *(p + (i * columnas) + j));
            }
            printf("\n");
        }
    }
}

char *matrizCrear(int filas, int columnas)
{
    char *p;
    p = (char *)malloc(sizeof(char) * (filas * columnas));
    if (p == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            *(p + (i * columnas) + j) = '-';
        }
    }
    return p;
}

void jugada(char *p, int casilla, char c)
{
    *(p + (casilla - 1)) = c;
}
int victoria(char *p, int filas, int columnas)
{
    int i, j;
    char c = '-';
    char x[] = "XXX";
    char y[] = "000";
    char hor[4], vert[4], diag1[4], diag2[4];
    char *q;

    q = strchr(p, c);
    if (q != NULL)
    {
        // busqueda horizontal
        for (i = 0; i < filas; i++)
        {
            for (j = 0; j < columnas; j++)
            {
                hor[j] = *(p + (i * columnas) + j);
            }
            hor[j] = '\0';
            if (strcmp(hor, x) == 0 || strcmp(hor, y) == 0)
            {
                return 1;
            }
        }

        // busqueda vertical
        for (i = 0; i < filas; i++)
        {
            for (j = 0; j < columnas; j++)
            {
                vert[j] = *(p + (j * filas) + i);
            }
            vert[j] = '\0';

            if (strcmp(vert, x) == 0 || strcmp(vert, y) == 0)
            {
                return 1;
            }
        }
        // busqueda diagonal

        diag1[0] = *(p + 0);
        diag1[1] = *(p + 4);
        diag1[2] = *(p + 8);
        diag1[3] = '\0';

        diag2[0] = *(p + 2);
        diag2[1] = *(p + 4);
        diag2[2] = *(p + 6);
        diag2[3] = '\0';

        if (strcmp(diag1, x) == 0 || strcmp(diag1, y) == 0 || strcmp(diag2, x) == 0 || strcmp(diag2, y) == 0)
        {
            return 1;
        }

        return -1;
    }
    else
    {
        return 2;
    }
}

int main(void)
{

    int game = 0, i = 0, resultado, casilla;
    char c;
    char player[] = "X0";
    char jugadas[] = "123456789";
    char *p = NULL, *q = NULL;
    p = matrizCrear(FILAS, COLUMNAS);

    while (!game)
    {

        printf("-------------------------------\n");
        printf("turno player: '%c'\n", player[i]);
        printf("Ingrese posicion:\n\n");
        printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
        printf("\nPosicion: ");
        scanf("%d", &casilla);
        printf("\n\n-------------------------------\n\n");

        if (!(casilla > 0 && casilla < 10))
        {
            printf("jugada incorrecta\n");
            matrizImprimir(p, FILAS, COLUMNAS);
        }
        else
        {
            c = casilla + '0';
            // comprobar casilla jugada
            q = strchr(jugadas, c);
            if (q == NULL)
            {
                printf("jugada incorrecta\n");
                matrizImprimir(p, FILAS, COLUMNAS);
            }
            else
            {
                // limpiamos esa casilla
                *q = '0';
                // escribimos jugada
                jugada(p, casilla, player[i]);
                // imprimir matriz
                matrizImprimir(p, FILAS, COLUMNAS);

                // comprobar victoria
                resultado = victoria(p, FILAS, COLUMNAS);
                if (resultado == VICTORIA)
                {
                    game = 1;
                    printf("\n-------------------------------\n\n");
                    printf("Ganador jugador %c\n\n", player[i]);
                }
                else if (resultado == EMPATE)
                {
                    game = 1;
                    printf("\n-------------------------------\n\n");
                    printf("Empate\n\n");
                }
                else
                {
                    // cambiar player
                    if (i == 0)
                    {
                        i = 1;
                    }
                    else
                    {
                        i = 0;
                    }
                }
            }
        }
    }

    free(p);
    return 0;
}