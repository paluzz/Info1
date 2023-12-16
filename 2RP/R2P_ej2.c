#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// funcion hecha en clase
int insertStr(char *strDest, int pos, char *strOrg)
{
    int longDest = strlen(strDest);
    int longOrg = strlen(strOrg);
    int longFinal = (longDest + longOrg);
    int i;
    char aux[longFinal];

    if (pos <= longDest)
    {
        // guardamos el original y le clavamos el \0
        strcpy(aux, strDest);
        *(aux + pos) = '\0';

        // pegamos el string en el \0
        strcat(aux, strOrg);

        // copiamos el resto
        for (i = (pos + longOrg); i < (longFinal); i++, pos++)
        {
            *(aux + i) = *(strDest + pos);
        }
        aux[longFinal] = '\0';

        // devolvemos strDest modificado
        strcpy(strDest, aux);
    }

    // longitud inicial y final son distintas? -> TRUE, else FALSE;
    return (longDest != strlen(strDest)) ? longOrg : 0;
}
char *ofuscador(char *archivo, int cantMax)
{
    // comprobamos que la entrada exista
    if (archivo == NULL)
    {
        printf("nombre archivo invalido\n");
        return NULL;
    }

    FILE *fp, *fpo;
    char *a, *e, *i, *o, *u;
    int r, random, distModif = 0;
    char texto[1024], *aux, *q = NULL, *s;

    // vector A
    random = rand() % cantMax;
    a = (char *)malloc(sizeof(char) * (random));
    memset(a, 'a', random);
    a[random] = '\0';

    // vector E
    random = rand() % cantMax;
    e = (char *)malloc(sizeof(char) * random);
    memset(e, 'e', random);
    e[random] = '\0';

    // vector I
    random = rand() % cantMax;
    i = (char *)malloc(sizeof(char) * random);
    memset(i, 'i', random);
    i[random] = '\0';

    // vector O
    random = rand() % cantMax;
    o = (char *)malloc(sizeof(char) * random);
    memset(o, 'o', random);
    o[random] = '\0';

    // vector U
    random = rand() % cantMax;
    u = (char *)malloc(sizeof(char) * random);
    memset(u, 'u', random);
    u[random] = '\0';

    // abrimos archivo entrada
    fp = fopen(archivo, "r");

    if (fp == NULL)
    {
        printf("Error apertura\n");
        return NULL;
    }

    // creamos archivo salida
    fpo = fopen("encriptado.txt", "w");

    if (fpo == NULL)
    {
        printf("Error apertura\n");
        return NULL;
    }

    // leemos el archivo entrada

    s = fgets(texto, 1024, fp);
    if (s == NULL)
    {
        printf("Error lectura\n");
        return NULL;
    }

    // pedimos memoria para el aux

    aux = (char *)malloc(sizeof(char) * (1024));
    if (aux == NULL)
    {
        printf("Error memoria\n");
    }

    strcpy(aux, texto);

    // Hacemos las modificaciones al texto original
    // vector A
    q = strchr(texto, 'a');
    while (q != NULL)
    {
        r = (int)(q - texto);
        insertStr(aux, r + distModif, a);

        distModif += strlen(a);

        q = strchr(q + 1, 'a');
    }

    // reiniciamos valores
    q = NULL;
    distModif = 0;
    strcpy(texto, aux);

    // vector E
    q = strchr(texto, 'e');
    while (q != NULL)
    {
        r = (int)(q - texto);
        insertStr(aux, r + distModif, e);

        distModif += strlen(e);

        q = strchr(q + 1, 'e');
    }
    // reiniciamos valores
    q = NULL;
    distModif = 0;
    strcpy(texto, aux);
    // vector I
    q = strchr(texto, 'i');
    while (q != NULL)
    {
        r = (int)(q - texto);
        insertStr(aux, r + distModif, i);

        distModif += strlen(i);

        q = strchr(q + 1, 'i');
    }
    // reiniciamos valores
    q = NULL;
    distModif = 0;
    strcpy(texto, aux);

    // vector O
    q = strchr(texto, 'o');
    while (q != NULL)
    {
        r = (int)(q - texto);
        insertStr(aux, r + distModif, o);

        distModif += strlen(o);

        q = strchr(q + 1, 'o');
    }
    // reiniciamos valores
    q = NULL;
    distModif = 0;
    strcpy(texto, aux);

    // vector U
    q = strchr(texto, 'u');
    while (q != NULL)
    {
        r = (int)(q - texto);
        insertStr(aux, r + distModif, u);

        distModif += strlen(u);

        q = strchr(q + 1, 'u');
    }
    strcpy(texto, aux);
    // guardamos en el archivo salida

    r = fprintf(fpo, "%s", texto);
    if (r < 0)
    {
        printf("Error escritura\n");
        return NULL;
    }
    else
    {
        printf("Texto encriptado exitosamente\n");
    }

    // cerramos archivos
    fclose(fp);
    fclose(fpo);

    // libermoas memoria
    free(a);
    free(e);
    free(i);
    free(o);
    free(u);

    // aqui no entendi si devolver el string ofuscado o que xq era un char*
    return aux;
}
int main()
{
    char *r;
    r = ofuscador("entrada.txt", 8);
    printf("texto encriptado: '%s'\n", r);
    free(r);

    return 0;
}
