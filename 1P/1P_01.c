#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misionImposible(char *dataPtr)
{
    int l = strlen(dataPtr), i, k;
    char abc[] = "abcdefghijklmnopqrstuvwxyz";
    int abcl = strlen(abc);
    char codif[] = "bkmulwtaijvchdnxfozyqpresg";
    char *cifrado = (char *)malloc(sizeof(char) * (l + 1));
    if (cifrado == NULL)
    {
        return NULL;
    }
    strcpy(cifrado, dataPtr);
    for (i = 0; i < l; i++)
    {
        for (k = 0; k < abcl; k++)
        {

            if (dataPtr[i] == codif[k])
            {
                // transformamos a texto
                cifrado[i] = abc[k];
            }
        }
    }
    return cifrado;
}
int main(void)
{
    char mensaje[] = "dn zbklz mnhn lz lzn hbotl, sn zns lc fql pb bai b onhxlozl lc bchb. s dn lzyns wqlob ul cqtbo, yq lzybz wqlob ul cqtbo, ynun lc hbcuiyn zizylhb lzyb wqlob ul cqtbo, fqilolz cb ploubu ?? yq dn xqlulz hbdljbo cb ploubu xnofql mqbdun zl clpbdyb cb hbdn xbob ynmbo cb mbob ul cn fql wql yq hljno bhitn s lz qd hndynd ul kbzqob, qdn dn zbkl fql abmlo... ncpiubcn hbotl, lzyn lz lc kbooin maidn!!";

    printf("mensaje: %s\n", misionImposible(mensaje));

    return 0;
}
