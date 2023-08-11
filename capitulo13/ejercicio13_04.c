#include <stdio.h>

float calculo(float, float, char);

int main(void)
{
    char op;
    float a, b;
    printf("Ingrese num: ");
    scanf("%f", &a);
    printf("Ingrese num: ");
    scanf("%f", &b);
    printf("Ingrese operacion: ");
    scanf("%*c%c", &op);

    printf("resultado : %.2f\n", calculo(a, b, op));

    return 0;
}

float calculo(float opA, float opB, char op)
{
    float resultado = 0;
    switch (op)
    {
    case '+':
        resultado = opA + opB;
        break;
    case '-':
        resultado = opA - opB;
        break;
    case '*':
        resultado = opA * opB;
        break;
    case '/':
        if (opB != 0)
        {
            resultado = opA / opB;
        }
        break;

    default:
        break;
    }

    return resultado;
}