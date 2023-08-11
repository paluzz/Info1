#include <stdio.h>
#include <math.h>

int main(void)
{
    int num1;
    float raiz;
    printf("ingrese un numero: ");
    scanf("%d", &num1);

    raiz = sqrt((float)num1);
    /*
        No existe la raiz cuadrada de los negativos en R
        la funcion sqrt() retorna => nan (not a number)
    */
    printf("La raiz cuadrada de %d es %.4f\n", num1, raiz);
    return 0;
}
