#include <stdio.h>
int myHexa(char *dataPtr)
{
    int i = 0;
    printf("El string '%s' en hexa es: ", dataPtr);
    while (*(dataPtr + i) != '\0')
    {
        printf("%x ", *(dataPtr + i));
        i++;
    }
    printf("\n");

    return i;
}
int main(void)
{
    char str[] = "calculadora";
    char *p;
    p = &str[0];

    printf("La longitud del string es: %d\n", myHexa(p));

    return 0;
}