#include <stdio.h>

int escribirBit(int palabra, int bit, int datoBit)
{
    if (datoBit == 0)
    {
        // Limpiar el bit en la posición indicada
        palabra &= ~(1 << bit);
    }
    else if (datoBit == 1)
    {
        // Establecer el bit en la posición indicada
        palabra |= (1 << bit);
    }

    return palabra;
}

int escribirNibble(int palabra, int nibble, int datoNibble)
{
    // Limpiar el nibble en la posición indicada
    palabra &= ~(0xF << (nibble * 4));
    // Establecer el nuevo valor del nibble
    palabra |= (datoNibble << (nibble * 4));

    return palabra;
}

int escribirByte(int palabra, int byte, int datoByte)
{
    // Limpiar el byte en la posición indicada
    palabra &= ~(0xFF << (byte * 8));
    // Establecer el nuevo valor del byte
    palabra |= (datoByte << (byte * 8));

    return palabra;
}

int main()
{
    int palabra = 0x12345678;

    // Ejemplo de uso
    palabra = escribirBit(palabra, 3, 1);      // Establecer el bit 3 a 1
    palabra = escribirNibble(palabra, 1, 0xA); // Establecer el nibble 1 a 0xA
    palabra = escribirByte(palabra, 2, 0xF);   // Establecer el byte 2 a 0xFF

    printf("Palabra modificada: 0x%08X\n", palabra);

    return 0;
}
