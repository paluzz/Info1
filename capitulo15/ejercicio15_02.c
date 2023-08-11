#include <stdio.h>
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int x, y;
    printf("ingrese x: ");
    scanf("%d", &x);
    printf("ingrese y: ");
    scanf("%d", &y);

    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;
}