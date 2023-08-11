#include <stdio.h>
#include <string.h>

int decodificadorMorse(char *morse, char *texto)
{
    char *morseChar[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", '\0'};
    char abecedario[] = "abcdefghijklmnopqrstuvwxyz";
    char aux[5];
    int i, j, k, z;

    for (i = 0, j = 0, z = 0; morse[i] != '\0'; i++)
    {
        // guardamos parcialmente el string
        if (morse[i] != ' ')
        {
            aux[j] = morse[i];
            j++;
        }
        else
        {
            aux[j] = '\0';
            // obtenemos la posicion k del codigo morse
            for (k = 0; k < 26; k++)
            {
                if (strcmp(aux, morseChar[k]) == 0)
                {
                    // transformamos a texto
                    texto[z] = abecedario[k];
                }
            }
            z++;
            // reiniciamos vector aux
            j = 0;
            aux[j] = '\0';
        }
    }

    // verificamos si el ultimo caracter termina en espacio
    // para no olvidarnos de convertirlo
    if (morse[i - 1] != ' ')
    {
        aux[j] = '\0';
        for (k = 0; k < 26; k++)
        {
            if (strcmp(aux, morseChar[k]) == 0)
            {
                // transformamos a texto
                texto[z] = abecedario[k];
            }
        }
        z++;
    }

    texto[z] = '\0';

    return 0;
}

int main(void)
{
    int c;
    char texto[64];
    c = decodificadorMorse(".... --- .-.. .- ", texto);
    printf("esperado: hola\tobtenido: %s\treturn: %d\n", texto, c);

    c = decodificadorMorse("-.-. --- -.. .. --. --- -- --- .-. ... . ", texto);
    printf("esperado: codigomorse\tobtenido: %s\treturn: %d\n", texto, c);

    c = decodificadorMorse("-.-. --- -.. .. --. --- -- --- .-. ... . ..-.", texto);
    printf("esperado: codigomorsef\tobtenido: %s\treturn: %d\n", texto, c);

    return 0;
}