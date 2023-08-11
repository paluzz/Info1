#include <stdio.h>
#include <string.h>
int trim(char *str, char chr, char *strRes)
{
    int i, j = 0, cantidad = 0;
    int longitud = strlen(str);

    for (i = 0; i < longitud; i++, j++)
    {
        // copiamos el string
        if (*(str + i) != chr)
        {
            *(strRes + j) = *(str + i);
        }
        else
        {
            j--;
            cantidad++;
        }
    }
    j = (longitud - cantidad);
    strRes[j] = '\0';

    // si existe chr en str -> cantidad, else -1
    return (strchr(str, chr) != NULL) ? cantidad : -1;
}
void toLowerCase(char v[])
{
    int i = 0;
    while (v[i] != '\0')
    {
        if (v[i] >= 'A' && v[i] <= 'Z')
        {
            v[i] += ('a' - 'A');
        }
        i++;
    }
}
int detectorPalindromo(char *palabraPtr)
{
    if (palabraPtr != NULL)
    {
        int l = strlen(palabraPtr);
        int status, flag = 1, i, j;
        char strRes[256];

        if (l < 2)
        {
            return (-2);
        }
        else
        {
            i = trim(palabraPtr, ' ', strRes); // borramos espacios
            toLowerCase(strRes);

            if (i != -1) // trim devuelve -1 en caso de no hacer nada
            {
                l -= i; // reasignamos longitud
            }
            for (i = 0, j = l - 1; i < (l / 2); i++, j--)
            {
                if (strRes[i] != strRes[j])
                {
                    return (-1);
                }
                else
                {
                    status = 0;
                }
            }
        }
        if (status == 0)
        {
            return 0;
        }
    }
}
int main(void)
{
    int resultado;

    resultado = detectorPalindromo("a");
    printf("-2 : %d\n", resultado);

    resultado = detectorPalindromo("animal");
    printf("-1 : %d\n", resultado);

    resultado = detectorPalindromo("abcba");
    printf("0 : %d\n", resultado);

    resultado = detectorPalindromo("Anita lava la tina");
    printf("0 : %d\n", resultado);

    return 0;
}