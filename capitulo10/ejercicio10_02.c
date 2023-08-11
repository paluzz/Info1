#include <stdio.h>
#include <math.h>

int main(void)
{
    int x, y;
    float distancia, a, b;

    printf("Ingrese coordenada 'x': ");
    scanf("%d", &x);
    printf("Ingrese coordenada 'y': ");
    scanf("%d", &y);

    if ((x == 0) && (y == 0))
    {
        printf("El vector (%d,%d) esta sobre el Origen de coordenadas\n", x, y);
    }
    else if (x == 0 && y != 0)
    {
        printf("El vector (%d,%d) esta sobre el eje de absisas\n", x, y);
    }
    else if (y == 0 && x != 0)
    {
        printf("El vector (%d,%d) esta sobre el eje de ordendas\n", x, y);
    }
    else
    {
        if (x > 0)
        {
            if (y > 0)
            {
                printf("El vector (%d,%d) se encuentra en el primer cuadrante \n", x, y);
            }
            else
            {
                printf("El vector (%d,%d) se encuentra en el cuarto cuadrante \n", x, y);
            }
        }
        else
        {
            if (y > 0)
            {
                printf("(%d,%d) se encuentra en el segundo cuadrante \n", x, y);
            }
            else
            {
                printf("(%d,%d) se encuentra en el tercer cuadrante \n", x, y);
            }
        }
    }

    a = pow((float)x, 2);
    b = pow((float)y, 2);
    distancia = sqrtf(a + b);

    printf("La distancia al origen de coordenadas es: %.3f\n", distancia);

    return 0;
}