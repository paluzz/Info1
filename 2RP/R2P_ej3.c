#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int odlaw(char *dibujo, char *wally)
{
    FILE *fp;
    int pos = -1, i = 0, distancia1, distancia2;
    char dib[100];
    char *q, *p, *s;

    fp = fopen(dibujo, "r");
    if (fp == NULL)
    {
        printf("error apertura\n");
        return -1;
    }

    // obtener dibujo
    while (!feof(fp))
    {
        fscanf(fp, "%s", dib);
    }

    // buscamos a wally
    q = strchr(dib, wally[i]);
    if (q != NULL)
    {
        i++;
        p = strchr(dib, wally[i]);
        if (p != NULL)
        {
            i++;
            s = strchr(dib, wally[i]);
            if (s != NULL)
            {
                distancia1 = (int)(p - q);
                distancia2 = (int)(s - p);

                if ((distancia1 == 2) && (distancia2 == 2))
                {
                    pos = (int)(q - dib);
                }
            }
        }
    }

    fclose(fp);
    return pos;
}

int main()
{
    char wally[] = "WLY";
    int r;

    r = odlaw("dibujo.txt", wally);
    if (r < 0)
    {
        printf("odlaw se volvio loco\n");
    }
    else
    {
        printf("Wally se encuentra en %d\n", r);
    }

    return 0;
}
