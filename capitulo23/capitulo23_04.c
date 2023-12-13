/*
    ESTE PROGRAMA ES EXACTAMENTE EL MISMO QUE EL ANTERIOR
    LO HICE DIRECTAMENTE CON ARRAY A PUNTEROS EN EL 23_03
    xD
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma(int a, int b)
{
    return (a + b);
}
int resta(int a, int b)
{
    return (a - b);
}
int multiplicacion(int a, int b)
{
    return (a * b);
}
int division(int a, int b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        return -1;
    }
}

int main(int args, char *argv[])
{
    if (args != 4)
    {
        printf("Uso: <entero1> <operacion> <entero2>\n");
        return -1;
    }
    char *p = NULL;
    char listOp[] = "+-/x"; // reemplazo * con x, por alguna razon me da error
    char op = argv[2][0];
    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    int operando, r;
    int (*func[4])(int, int);
    func[0] = suma;
    func[1] = resta;
    func[2] = division;
    func[3] = multiplicacion;

    p = strchr(listOp, op);
    if (p == NULL)
    {
        printf("Operacion invalida\r\n");
        return (-3);
    }

    operando = (int)(p - listOp);

    if (operando >= 0 && operando <= 3)
    {
        r = func[operando](a, b);
        if ((operando == 2) && (r == -1))
        {
            printf("No se puede dividir por 0\n");
        }
        else
        {
            printf("%d %c %d = %d\n", a, op, b, r);
        }
    }
    else
    {
        printf("Error fuera de rango\n");
    }

    return 0;
}