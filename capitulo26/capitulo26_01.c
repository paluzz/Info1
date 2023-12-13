#include <stdio.h>

int potencia(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return (x * potencia(x, y - 1));
    }
}

int main()
{
    // Ejemplo de uso: calcular 2^3
    int resultado = potencia(2, 3);

    printf("El resultado es: %d\n", resultado);

    return 0;
}
