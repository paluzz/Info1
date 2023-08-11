#include <stdio.h>
#include <string.h>

int tamanioPalabra(char *str, char *corta, char *larga)
{
    int palabra_corta_len = strlen(str); // Inicializamos con un valor grande para encontrar una palabra más corta
    int palabra_larga_len = 0;
    int cantidad_palabras = 0;
    char *inicio = NULL, *fin = NULL;
    int i = 0; // Variable para recorrer el puntero usando *(str + i)

    while (*(str + i))
    {
        // Encontramos el inicio de la palabra (ignoramos punto y coma y espacios)
        while (*(str + i) && *(str + i) == ';')
        {
            i++;
        }

        // Si llegamos al final del string, terminamos el bucle
        if (*(str + i) == '\0')
        {
            break;
        }
        inicio = &str[i];

        // Contamos la palabra actual y actualizamos la cantidad de palabras
        cantidad_palabras++;

        // Encontramos el final de la palabra
        while (*(str + i) && *(str + i) != ';')
        {
            i++;
        }
        fin = &str[i];

        // Calculamos el tamaño de la palabra actual
        int tam_palabra_actual = fin - inicio;

        // Actualizamos la palabra más corta y más larga si corresponde
        if (tam_palabra_actual < palabra_corta_len)
        {
            palabra_corta_len = tam_palabra_actual;
            strncpy(corta, inicio, palabra_corta_len);
            corta[palabra_corta_len] = '\0';
        }

        if (tam_palabra_actual > palabra_larga_len)
        {
            palabra_larga_len = tam_palabra_actual;
            strncpy(larga, inicio, palabra_larga_len);
            larga[palabra_larga_len] = '\0';
        }
    }

    return cantidad_palabras;
}

int main(void)
{
    int tam;
    char corta[50], larga[50];
    tam = tamanioPalabra("amarillo;blanco;rojo", corta, larga);
    printf("Tamaño: %d\tcorta: %s\tlarga: %s\n", tam, corta, larga);

    tam = tamanioPalabra("a;ante;bajon;ferrocarril", corta, larga);
    printf("Tamaño: %d\tcorta: %s\tlarga: %s\n", tam, corta, larga);
    return 0;
}