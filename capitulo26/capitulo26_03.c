#include <stdio.h>

void decimalToBinaryRecursive(int num, int binaryArray[], int size, int index)
{
    // Caso base: el número llegó a cero o se alcanzó el final del array
    if (num == 0 || index < 0)
    {
        return;
    }

    // Algoritmo recursivo: divide el número por 2 y llama a la función con el nuevo número y el siguiente índice
    decimalToBinaryRecursive(num / 2, binaryArray, size, index - 1);

    // Almacena el residuo en el array
    binaryArray[index] = num % 2;
}

int main()
{
    int dato = 42; // Ejemplo de dato entero (puedes cambiarlo según tus necesidades)
    int size = 8;  // Tamaño del array para almacenar la representación binaria (puedes ajustarlo según tus necesidades)
    int binaryArray[size];

    // Llama a la función recursiva para convertir a binario
    decimalToBinaryRecursive(dato, binaryArray, size, size - 1);

    // Muestra el resultado
    printf("Representación binaria de %d: ", dato);
    for (int i = 0; i < size; ++i)
    {
        printf("%d", binaryArray[i]);
    }
    printf("\n");

    return 0;
}
