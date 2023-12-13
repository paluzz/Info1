#include <stdio.h>

int leerByte(int palabra, int byte)
{
    // Desplaza el byte deseado a la posición más baja y aplica una máscara para obtener solo ese byte.
    int valorByte = (palabra >> (8 * byte)) & 0xFF;
    return valorByte;
}

int main()
{
    int palabra = 0x12345678; // Ejemplo de valor de palabra (puedes cambiarlo según tus necesidades)
    int byte = 2;             // Ejemplo de número de byte (puedes cambiarlo según tus necesidades)

    // Llama a la función leerByte y muestra el resultado.
    int resultado = leerByte(palabra, byte);
    printf("El valor del byte %d en 0x%X es: 0x%X\n", byte, palabra, resultado);

    return 0;
}
