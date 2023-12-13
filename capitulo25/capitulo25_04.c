#include <stdio.h>

int leerNibble(int palabra, int nibble)
{
    // Asegurarse de que el valor de 'nibble' esté en el rango correcto (0-7)
    if (nibble < 0 || nibble > 7)
    {
        printf("Error: El valor de 'nibble' debe estar en el rango de 0 a 7.\n");
        return -1; // Valor de retorno indicando un error
    }

    // Desplazar el nibble deseado a la posición más baja y eliminar los bits superiores
    int nibbleLeido = (palabra >> (4 * nibble)) & 0xF;

    return nibbleLeido;
}

int main()
{
    // Ejemplo de uso
    int palabra = 0x12345678; // Un valor de ejemplo (0x12345678 en hexadecimal)
    int nibbleIndex = 2;      // El tercer nibble (índice 2) de la palabra

    int resultado = leerNibble(palabra, nibbleIndex);

    if (resultado != -1)
    {
        printf("El nibble en la posición %d es: %X\n", nibbleIndex, resultado);
    }

    return 0;
}
