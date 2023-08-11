#include <string.h>
#define TRUE 1
#define FALSE 0

//------------------------------------------------------------------//
// FUNCIONES VECTORES ----------------------------------------------//

void imprimirVector(int v[], int longitud)
{

    int i = 0;
    while (i < longitud)
    {
        printf("%d ", v[i]);
        i++;
    }
    printf("\n");
}

// operaciones con vectores
void sumaVectorial(double* vec1, double* vec2, double* res) { 
 int i; 
 for (i=0; i<3; i++) 
 res[i]=vec1[i]+vec2[i]; 
 
} 
void restaVectorial(double* vec1, double* vec2, double* res) { 
 int i; 
 for (i=0; i<3; i++) 
 res[i]=vec1[i]-vec2[i]; 
 
} 
void productoVectorial(double* vec1, double* vec2, double* vectorial) { 
 vectorial[0] = vec1[1]*vec2[2]-vec2[1]*vec1[2]; 
 vectorial[1] = vec1[2]*vec2[0]-vec2[2]*vec1[0]; 
 vectorial[2] = vec1[0]*vec2[1]-vec2[0]*vec1[1]; 

} 
double productoEscalar(double* vec1, double* vec2) { 
 double escalar = 0.0; 
 int i; 
 for (i=0; i<3; i++) 
 escalar+=vec1[i]*vec2[i]; 
 return (escalar); 
}

double moduloVector(double* vec,int Rn)
{
	double modulo = 0;
	for(int i = 0; i < Rn; i++)
	{
		modulo += (vec[i] * vec[i]);
	}
    return sqrt(modulo);
}
// comprueba si tres vectores R2 son LI y devuelve los valores alfa y beta
// LI 0 , LD: SCI 1, SI -1
int linealmenteIndependiente(double *a,double *b,double *c,double *alfa,double *beta)
{
	int sistema;
	double det;
	det = a[0] * b[1] - a[1] * b[0];
	// LI:
	if (det != 0.0)
	{
		//Sistema Compatible Determinado
		sistema = 0;
		*alfa = (c[0] * b[1] - c[1] * b[0]) / det;
        *beta = (c[1] * a[0] - c[0] * a[1]) / det;
	}
	// LD:
	else
	{
		//Sistema Compatible Indeterminado // inf soluciones	
		if (a[0] * c[1] == c[0] * a[1])
        {
			sistema = 1;
            *alfa = (a[0] * c[0]) / (a[0] * a[0] + a[1] * a[1]);
            *beta = (a[1] * c[0]) / (a[0] * a[0] + a[1] * a[1]);       
        }
        // Sistema Indeterminado // Sin solucion
        else
        {
        	sistema = -1;
        	*alfa = 0;
        	*beta = 0;
        }
        
		
	}
	return sistema;
}

// creamos matriz R3x3 a partir de 3 vectores de R3
double** crearMatriz(double *a,double*b,double *c)
{
	double **mat;
	// asignamos memoria para la matriz 3x3
	mat = (double **)malloc(3*sizeof(double*)); 
	for (int i=0;i<3;i++)
	{ 
		mat[i] = (double*)malloc(3*sizeof(int));
	}
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			mat[0][j] = a[j];
			mat[1][j] = b[j];
			mat[2][j] = c[j];
		}
	}
	return mat;
}
double determinante3x3(double** matriz)
{
double determinante;
determinante = matriz[0][0]*matriz[1][1]*matriz[2][2]; 
 determinante += matriz[0][1]*matriz[1][2]*matriz[2][0]; 
 determinante += matriz[1][0]*matriz[2][1]*matriz[0][2]; 
 determinante -= matriz[0][2]*matriz[1][1]*matriz[2][0]; 
 determinante -= matriz[0][1]*matriz[1][0]*matriz[2][2]; 
 determinante -= matriz[0][0]*matriz[2][1]*matriz[1][2];
 
 return determinante; 
}
// devuelve el valor minimo de un vector
double minimo(double *valores, int num)
{
    int i;
    double min;
    min = valores[0];
    for (i = 1; i < num; i++)
        if (valores[i] < min)
            min = valores[i];
    return (min);
}
// devuelve el valor maximo de un vector
double maximo(double *valores, int num)
{
    int i;
    double max;
    max = valores[0];
    for (i = 1; i < num; i++)
        if (valores[i] > max)
            max = valores[i];
    return (max);
}

// comprueba si a esta dentro del rango
int rango(int a, int b, int c)
{
    int t;
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    return (a >= b && a <= c) ? a : FALSE;
}

float rangof(float a, float b, float c)
{
    float t;
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    return (a >= b && a <= c) ? a : FALSE;
}
// devuelve puntero al centro del vector
int *medioVector(int *dataPtr, int dataLong)
{
    int *p;

    p = dataPtr + (dataLong / 2);

    return p;
}
// Comprueba si un numero pertenece al vector
int numberInVector(int input, int v[])
{
    int contador = 0;
    for (int i = 0; i < strlen(v); i++)
    {
        if (v[i] == input)
        {
            contador++;
        }
    }
    return contador > 1 ? input : 0;
}

int factorial(int n)
{
    int resultado = 1;
    if (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            resultado *= i;
        }
    }
    else if (n == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = 0;
    }

    return resultado;
}

int esPrimo(int n)
{
    int primo = 1;
    if (n <= 0)
    {
        primo = -1;
    }
    else if (n == 1)
    {
        primo = 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if ((n % i) == 0)
            {
                primo = 0;
                break;
            }
        }
    }

    return primo;
}
// requiere: esPrimo
// devuelve vector dinamico con todos los primos hasta el limite n
int *calcularPrimos(int n, int *cant)
{
    if (n <= 1)
    {
        return 0;
    }
    int contador = 0;
    int *primo, *primoRllc;
    primo = (int *)malloc(sizeof(int));
    if (primo == 0)
    {
        return 0;
    }

    for (int i = 0; i <= n; i++)
    {
        if (1 == esPrimo(i))
        {
            primo[contador] = i;
            contador++;
            primoRllc = (int *)realloc(primo, sizeof(int *) * (contador));
            primo = primoRllc;
        }
    }
    *cant = contador;
    return primo;
}
// calcula promedio
float promediof(float *dataPtr, int dataCant)
{
    float p = 0;
    int i;
    for (i = 0; i < dataCant; i++)
    {
        // sumar todos los valores
        // dividirlo cantidad total
        p += *(dataPtr + i);
    }

    return (p / dataCant);
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
// devuelve puntero a la posicion del numero maximo
int *myMax(int *dataPtr, int dataCant)
{
    int *p, temp;
    p = dataPtr;
    temp = dataPtr[0];

    for (int i = 0; i < dataCant; i++)
    {
        if (*(dataPtr + i) > temp)
        {
            temp = *(dataPtr + i);
            *p = i;
        }
    }
    return p;
}
// devuelve puntero a la posicion del numero minimo
int *myMin(int *dataPtr, int dataCant)
{
    int *p, temp;
    p = dataPtr;
    temp = dataPtr[0];

    for (int i = 0; i < dataCant; i++)
    {
        if (*(dataPtr + i) < temp)
        {
            temp = *(dataPtr + i);
            *p = i;
        }
    }
    return p;
}
// vector creciente: 1 / decreciente : -1 / desordenado: 0
int orden(int *dataPtr, int dataCant)
{
    int status, creciente = 1, decreciente = 1;

    for (int i = 1; i < dataCant; i++)
    {
        if (*(dataPtr + i - 1) > *(dataPtr + i))
        {
            creciente = 0;
        }

        else if (*(dataPtr + i - 1) < *(dataPtr + i))
        {
            decreciente = 0;
        }
    }

    if (creciente)
    {
        status = 1;
    }
    else if (decreciente)
    {
        status = -1;
    }
    else
    {
        status = 0;
    }
    return status;
}


//--------------------------------------------------------------------------------//
//  FUNCIONES SUPERFICIES   ----------------------------------------------------------//
float areaCirculo(float radio)
{
    return (3.1415927 * radio * radio);
}
float perimetroCirculo(float radio)
{
    return (2 * 3.1415927 * radio);
}
float volumenCirculo(float radio)
{
    return (0.75 * 3.1415927 * radio * radio * radio);
}

//--------------------------------------------------------------------------------//
//  FUNCIONES NUMERICAS    ----------------------------------------------------------//

char *imprimirBinario(int n)
{
    // solo positivos
    if (n < 0)
    {
        return NULL;
    }
    int longitud = 0, i = 0, j;
    int *v = (int *)malloc(sizeof(int));
    int *a = NULL;
    char *bin = NULL;

    if (v == NULL)
    {
        return NULL;
    }

    while (n > 0)
    {
        // convertimos a binario
        v[i] = n % 2;
        n /= 2;
        longitud++;
        i++;
        a = (int *)realloc(v, sizeof(v) * i + 1);
        if (a != NULL)
        {
            v = a;
        }
    }
    // agregamos primer valor
    v[i] = n;
    bin = (char *)malloc(sizeof(char) * longitud);
    // invertimos el vector y lo convertimos a char
    for (i = 0, j = longitud - 1; i < longitud; i++, j--)
    {
        bin[i] = v[j] + '0';
    }
    bin[i] = '\0';

    return bin;
}
int rangoHexa(char *dataPtr)
{
    int l = strlen(dataPtr), contador = 0;
    for (int i = 0; i < l; i++)
    {
        if ((dataPtr[i] >= '0' && dataPtr[i] <= '9') || (dataPtr[i] >= 'A' && dataPtr[i] <= 'F'))
        {
            contador++;
        }
    }
    return (contador == l) ? 1 : -1;
}
int hexaToDec(char *dataPtr)
{
    int l = strlen(dataPtr);
    int dec[4];
    int resultado = 0;
    if (l != 4)
    {
        return (-2);
    }
    if (rangoHexa(dataPtr) != 1)
    {
        return (-1);
    }
    else
    {
        for (int i = 0, j = l - 1; i < l; i++, j--)
        {
            if (dataPtr[i] >= '0' && dataPtr[i] <= '9')
            {
                dec[i] = dataPtr[i] - '0';
            }
            else
            {
                dec[i] = (dataPtr[i] - 'A') + 10;
            }
            resultado += dec[i] * pow(16, j);
        }
    }

    return resultado;
}

//--------------------------------------------------------------------------------//
//  FUNCIONES STRING    ----------------------------------------------------------//

// reemplaza todas las ocurrencias de un caracter por otro
void strReplace(char v[], char old, char new)
{
    for (int i = 0; i < strlen(v); i++)
    {
        if (v[i] == old)
        {
            v[i] = new;
        }
    }
}
// devuelve cantidad de caracter dentro de string
int strCount(char v[], char c)
{
    int contador = 0;
    for (int i = 0; i < strlen(v); i++)
    {
        if (v[i] == c)
        {
            contador++;
        }
    }
    return contador;
}
// termina con el string endStr -> 1
int endsWith(char *str, char *endStr)
{
    int longStr = strlen(str);
    int longEnd = strlen(endStr);
    int i, j = 0;
    char aux[longEnd];

    for (i = (longStr - longEnd); i <= longStr; i++, j++)
    {
        *(aux + j) = *(str + i);
    }

    return (strcmp(aux, endStr) == 0) ? 1 : 0;
}
// comienza con el string startStr-> 1
int startsWith(char *str, char *endStr)
{
    int longitud = strlen(endStr);
    int i, j = 0;
    char aux[longitud];

    for (i = 0; i < longitud; i++, j++)
    {
        *(aux + j) = *(str + i);
    }
    aux[longitud] = '\0';

    return (strcmp(aux, endStr) == 0) ? 1 : 0;
}
// extrae una porción del string pasado como parámetro
int subStr(char *str, int pos, int len, char *strRes)
{
    int i, j;
    int longitud = strlen(str);

    for (i = 0; i < len; i++)
    {
        j = pos + i;
        *(strRes + i) = *(str + j);
    }

    strRes[len] = '\0';

    return (pos < longitud && len > 0) ? TRUE : FALSE;
}
// elimina todas las ocurrencias de un carácter pasado como parámetro
int trim(char *str, char chr, char *strRes)
{
    int i, j = 0, cantidad = 0;
    int longitud = strlen(str);

    for (i = 0; i < longitud; i++, j++)
    {
        // copiamos el string
        if (*(str + i) != chr)
        {
            *(strRes + j) = *(str + i);
        }
        else
        {
            j--;
            cantidad++;
        }
    }
    j = (longitud - cantidad);
    strRes[j] = '\0';

    // si existe chr en str -> cantidad, else -1
    return (strchr(str, chr) != NULL) ? cantidad : -1;
}
// agrega al final del string el carácter pasado como parámetro
int padRigth(char *str, int len, char chr)
{
    int longitud = strlen(str);
    int i, contador = 0;

    if (longitud < len)
    {
        // insertamos el caracter
        for (i = longitud; i < len; i++)
        {
            *(str + i) = chr;
            contador++;
        }

        *(str + i) = '\0';
    }
    return contador;
}
// agrega al comienzo del string el carácter pasado como parámetro
int padLeft(char *str, int len, char chr)
{
    int longitud = strlen(str);
    int final = (len - longitud);
    int i, contador = 0;
    char aux[longitud];

    if (longitud < len)
    {
        // guardamos el original
        if (longitud > 0)
        {
            strcpy(aux, str);
        }

        // insertamos el caracter
        for (i = 0; i < final; i++)
        {
            *(str + i) = chr;
            contador++;
        }
        *(str + i) = '\0';

        // pegamos el original encima del \0
        if (longitud > 0)
        {
            strcat(str, aux);
        }
    }
    return contador;
}
// agrega un string en la posición indicada en otro string
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
// reemplaza todas las ocurrencias de un string en otro
int replaceStr(char *str, char *strBuscar, char *strNueva)
{
    int longitud = strlen(str), contador = 0, i;
    int longBuscar = strlen(strBuscar);
    int longNueva = strlen(strNueva);
    char aux[longitud], *p;
    p = strstr(str, strBuscar);

    while (p != NULL)
    {
        // guardamos el string despues de la palabra buscada
        for (i = 0; *(p + i + longBuscar) != '\0'; i++)
        {
            *(aux + i) = *(p + i + longBuscar);
        }
        aux[i] = '\0';
        // reemplazamos la palbra deseada
        for (i = 0; i < longNueva; i++)
        {
            *(p + i) = *(strNueva + i);
        }
        // le pegamos el string guardado anteriormente
        for (i = 0; *(aux + i) != '\0'; i++)
        {
            *(p + i + longNueva) = *(aux + i);
        }

        p[i + longNueva] = '\0';
        contador++;

        p = strstr(str, strBuscar);
    }

    return contador;
}
// ordena texto alfabeticamente
void ordenDesc(char v[], int dataCant)
{
    char temp;
    for (int i = 0; i < (dataCant - 1); i++)
    {
        for (int j = i + 1; j < dataCant; j++)
        {
            if (v[i] > v[j])
            {
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    }
}
// ordena texto de mayor a menor
void ordenAsc(char v[], int dataCant)
{
    char temp;
    for (int i = 0; i < (dataCant - 1); i++)
    {
        for (int j = i + 1; j < dataCant; j++)
        {
            if (v[i] < v[j])
            {
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    }
}
// compara texto alfabeticamente, a < b: 1 / a > b : 0
int ordenAlfabetico(char a[], char b[])
{
    int status = 1, size;
    int longA = strlen(a), longB = strlen(b);

    if (longA < longB)
    {
        size = longA;
    }
    else
    {
        size = longB;
    }

    for (int i = 0; i < size; i++)
    {
        if (a[i] < b[i])
        {
            status = 1;
            i = size;
        }
        else if (a[i] > b[i])
        {
            status = 0;
            i = size;
        }
    }
    return status;
}
// string: 1 / numero: 2 / false: 0
int validaString(char *dataPtr)
{
    int esNum = 1, esStr = 1, i = 0, status;

    while (*(dataPtr + i) != '\0')
    {
        // si algun caracter no es numero, apagamos la bandera
        if (!(*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9'))
        {
            esNum = 0;
        }
        // si algun caracter no es string, apagamos la bandera
        else if (!(*(dataPtr + i) >= 'a' && *(dataPtr + i) <= 'z') || !(*(dataPtr + i) >= 'A' && *(dataPtr + i) <= 'Z'))
        {
            esStr = 0;
        }
        i++;
    }

    if (esStr == 1)
    {
        status = 1;
    }
    else if (esNum == 1)
    {
        status = 2;
    }
    else
    {
        status = 0;
    }

    return status;
}
// texto a mayuscula
void toUpperCase(char v[])
{
    int i = 0;
    while (v[i] != '\0')
    {
        if (v[i] >= 'a' && v[i] <= 'z')
        {
            v[i] += ('A' - 'a');
        }
        i++;
    }
}
// texto a minuscula
void toLowerCase(char v[])
{
    int i = 0;
    while (v[i] != '\0')
    {
        if (v[i] >= 'A' && v[i] <= 'Z')
        {
            v[i] += ('a' - 'A');
        }
        i++;
    }
}
// Invierte el string pasado como argumento
void inverse(char *str)
{
    if (str == NULL) {
        printf("Error: el string es NULL.\n");
        return;
    }
    int i, j, l = strlen(str);
    char *aux = malloc(sizeof(char) * l + 1);

    for (i = 0, j = (l - 1); i < l; i++, j--)
    {
        *(aux + i) = *(str + j);
    }
    *(aux + i) = '\0';
    strcpy(str, aux);
    free(aux);
    
}
// invierte un string sin mutarlo
char *inverseCpy(char *dest, const char *source)
{
    // string vacio
    if (source == NULL || *source == '\0')
    {
        return NULL;
    }

    int l = strlen(source);
    // comprobamos si destino es puntero a NULL
    if (dest == NULL)
    {
        dest = (char *)malloc(sizeof(char) * l);
        if (dest == NULL)
        {
            printf("Memory allocation failed.\n");
            return NULL;
        }
    }

    // invertimos string
    for (int i = 0, j = (l - 1); i < l; i++, j--)
    {
        *(dest + i) = *(source + j);
    }
    *(dest + l) = '\0';

    return dest;
}

// convierte texto a numeros
int strtoInt(char *dataPtr)
{
    int n = 0, i = 0, largo, exponente;
    if (validaString(dataPtr) == 2)
    {
        largo = strlen(dataPtr);
        exponente = largo - 1;

        for (i = 0; i < largo; i++)
        {
            n += (*(dataPtr + i) - '0') * (pow(10, exponente));
            exponente--;
        }
    }
    else
    {
        return -1;
    }

    return n;
}
// cuenta la ocurrencia de cada carácter (histograma) de un string
void contarCaracteres(char *dataPtr, int *dataCntPtr)
{
    int c = 0, i, l = strlen(dataPtr);

    for (i = 0; i < l; i++)
    {
        c = *(dataPtr + i);
        *(dataCntPtr + c) = *(dataCntPtr + c) + 1;
    }
}

int esLetra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int esNum(char c)
{
    return (c >= '0' && c <= '9');
}
// analiza cantidad de palabras y caracteres en un texto, 0 si contiene solo char y symbol
int analizaString(char *dataPtr, int *palabrasCant, int *caracteresCant)
{
    if (dataPtr == NULL || palabrasCant == NULL || caracteresCant == NULL)
    {
        return -1;
    }

    int palabras = 0;
    int caracteres = strlen(dataPtr);
    int i = 0, status = 0, letra = 0, simbolo = 0;

    while (*(dataPtr + i) != '\0')
    {
        if (esNum(dataPtr[i]))
        {
            status = -1;
        }
        if (esLetra(dataPtr[i]))
        {
            letra++;
        }
        if (ispunct(dataPtr[i]))
        {
            simbolo++;
        }

        if (isspace(*(dataPtr + i)) || ispunct(*(dataPtr + i)))
        {
            if (esLetra(dataPtr[i - 1]))
            {
                palabras++;
            }
        }
        i++;
    }
    if ((!ispunct(dataPtr[caracteres - 1]) && palabras != 0))
    {
        palabras++;
    }

    *palabrasCant = palabras;
    *caracteresCant = caracteres;

    if (letra == 0 || simbolo == 0)
    {
        status = -1;
    }
    return status;
}
// retorna: -2 si es una palabra corta, 0 palindromo, -1 no palindromo
// requiere trim() y toLowerCase()
int detectorPalindromo(char *palabraPtr)
{
    if (palabraPtr != NULL)
    {
        int l = strlen(palabraPtr);
        int status, flag = 1, i, j;
        char strRes[256];

        if (l < 2)
        {
            return (-2);
        }
        else
        {
            i = trim(palabraPtr, ' ', strRes); // borramos espacios, el return 'i' no nos sirve en este caso

            toLowerCase(strRes); // primero pasamos a minuscula para comparar
            l = strlen(strRes);
            for (i = 0, j = l - 1; i < (l / 2); i++, j--)
            {
                if (strRes[i] != strRes[j])
                {
                    return (-1);
                }
                else
                {
                    status = 0;
                }
            }
        }
        if (status == 0)
        {
            return 0;
        }
    }
}
// convierte string en vector
void convertirEntero(char *c, int *n)
{
    for (int i = 0; *(c + i) != '\0'; i++)
    {
        n[i] = c[i] - '0';
    }
}
// valida longitud + simbolo + mayusc + minusc + numero
int validarPassword(char *dataPtr)
{
    int l = strlen(dataPtr), i, mayor = 0, menor = 0, simflag = 0, numeros = 0;
    char simbolo[] = "+-*/._!=?¿¡=()[]{}&$# ";
    char *p = NULL;
    // CARACTERES
    if (l < 8)
    {
        return -1;
    }
    // ESPACIOS
    for (i = 0; i < l; i++)
    {
        if (*(dataPtr + i) == ' ')
        {
            return (-2);
        }
    }

    // MAYUSC Y MINUSC
    for (i = 0; i < l; i++)
    {
        if (*(dataPtr + i) >= 'A' && *(dataPtr + i) <= 'Z')
        {
            mayor = 1;
        }
        else if (*(dataPtr + i) >= 'a' && *(dataPtr + i) <= 'z')
        {
            menor = 1;
        }
    }
    if (!(mayor == 1 && menor == 1))
    {
        return (-3);
    }

    // SIMBOLOS
    for (i = 0; i < l; i++)
    {
        p = strchr(simbolo, *(dataPtr + i));
        if (p != NULL)
        {
            simflag = 1;
        }
    }
    if (simflag == 0)
    {
        return (-4);
    }
    // NUMEROS
    for (i = 0; i < l; i++)
    {
        if (*(dataPtr + i) >= '0' && *(dataPtr + i) <= '9')
        {
            numeros = 1;
        }
    }
    if ((numeros != 1))
    {
        return (-5);
    }

    return 1;
}
// codifica string en morse, acepta letras y numeros
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
// decodifica morse, solo acepta codigo de letras
int decodificadorMorse(char *morse, char *texto)
{
    char *morseChar[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", '\0'};
    char abecedario[] = "abcdefghijklmnopqrstuvwxyz";
    char aux[5];
    int i, j, k, z;

    for (i = 0, j = 0, z = 0; morse[i] != '\0'; i++)
    {
        // guardamos parcialmente el string
        if (morse[i] != ' ')
        {
            aux[j] = morse[i];
            j++;
        }
        else
        {
            // si encontramos espacio terminamos el string
            aux[j] = '\0';
            // obtenemos la posicion "k" en el string del codigo morse
            for (k = 0; k < 26; k++)
            {
                if (strcmp(aux, morseChar[k]) == 0)
                {
                    // transformamos a texto
                    texto[z] = abecedario[k];
                }
            }
            z++;
            // reiniciamos vector aux
            j = 0;
            aux[j] = '\0';
        }
    }

    // verificamos si el ultimo caracter termina en espacio
    // para no olvidarnos de convertirlo
    if (morse[i - 1] != ' ')
    {
        aux[j] = '\0';
        for (k = 0; k < 26; k++)
        {
            if (strcmp(aux, morseChar[k]) == 0)
            {
                // transformamos a texto
                texto[z] = abecedario[k];
            }
        }
        z++;
    }

    texto[z] = '\0';

    return 0;
}
