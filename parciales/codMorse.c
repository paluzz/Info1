// Codificador MORSE

#include <stdio.h>
#include <string.h>

int codificadorMorse(char *texto, char *morse)
{
    char *morseChar[] = {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. "};
    char *morseNum[] = {"----- ", ".---- ", "..--- ", "...-- ", "....- ", "..... ", "-.... ", "--... ", "---.. ", "----. "};

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if ((texto[i] >= 'a' && texto[i] <= 'z'))
        {
            strcat(morse, morseChar[texto[i] - 'a']);
        }
        else if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            strcat(morse, morseChar[texto[i] - 'A']);
        }
        else if (texto[i] >= '0' && texto[i] <= '9')
        {
            strcat(morse, morseNum[texto[i] - '0']);
        }
        else if (texto[i] == ' ')
        {
        }
        else
        {
            morse[0] = '\0';
            return -1;
        }
    }
    return 0;
}
int main(void)
{
    int c;
    char morse[128];

    c = codificadorMorse("hola", morse);
    printf("texto: hola\tmorse: %s\treturn: %d\n", morse, c);
    // reiniciamos el vector xq usamos strcat en la funcion
    morse[0] = '\0';
    c = codificadorMorse("Codigo Morse", morse);
    printf("texto: Codigo Morse\tmorse: %s\treturn: %d\n", morse, c);
    morse[0] = '\0';
    c = codificadorMorse("1234", morse);
    printf("texto: 1234\tmorse: %s\treturn: %d\n", morse, c);
    morse[0] = '\0';
    c = codificadorMorse("ab12", morse);
    printf("texto: ab12\tmorse: %s\treturn: %d\n", morse, c);
    morse[0] = '\0';
    c = codificadorMorse("abc*", morse);
    printf("texto: abc*\tmorse: %s\treturn: %d\n", morse, c);

    return 0;
}