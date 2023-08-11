#include <stdio.h>

int main(void)
{
    int a, b;
    char op;

    printf("Ingrese un numero: ");
    scanf("%d", &a);
    printf("Ingrese un numero: ");
    scanf("%d", &b);
    printf("Ingrese una operación: ");
    scanf("%*c%c", &op);

    switch (op)
    {
    case '+':
        printf("Ingresado %d %c %d = %d\n", a, op, b, a + b);
        break;
    case '-':
        printf("Ingresado %d %c %d = %d\n", a, op, b, a - b);
        break;
    case '*':
        printf("Ingresado %d %c %d = %d\n", a, op, b, a * b);
        break;
    case '/':
        if (b != 0)
        {
            printf("Ingresado %d %c %d = %d\n", a, op, b, a / b);
        }
        else
        {
            printf("No se puede dividir por 0\n");
        }
        break;
    default:
        printf("Operacion inválida\n");
        break;
    }

    return 0;
}