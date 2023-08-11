#include <stdio.h>
#define TRUE 1
#define FALSE 0

int esNumero(char *dataPtr)
{
    int i = 0;
    int num = TRUE;
    while (*(dataPtr + i) != '\0')
    {
        if (!(*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9'))
        {
            num = FALSE;
        }
        i++;
    }
    return num == TRUE ? TRUE : FALSE;
}

int main(void)
{
    char str[20];
    char *p;
    printf("Ingrese string de numeros: ");
    scanf("%s", str);
    p = &str[0];

    if (esNumero(p) == TRUE)
    {
        printf("Es numero\n");
    }
    else
    {
        printf("No es numero\n");
    }

    return 0;
}