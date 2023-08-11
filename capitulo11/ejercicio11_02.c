#include <stdio.h>

int main(void)
{
    int a, b;

    printf("Ingrese un numero: ");
    scanf("%d", &a);
    printf("Ingrese un numero: ");
    scanf("%d", &b);

    while (a != b)
    {
        if (a < b)
        {
            printf("%d\n", a);
            a++;
        }
        else // Solo si a > b
        {
            printf("%d\n", a);
            a--;
        }
    }
    // El if es innecesario ya que este codigo
    // se ejecuta SIEMPRE porque luego del ultimo ciclo a == b
    // pero lo dejo para que sea mas claro el funcionamiento
    if (a == b)
    {
        printf("%d\n", a);
    }

    return 0;
}