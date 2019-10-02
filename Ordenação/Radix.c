#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double time1, timedif;

void radixsort(int vetor[], int tamanho)
{
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++)
    {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior/exp > 0)
    {
        int bucket[10] = { 0 };
        for (i = 0; i < tamanho; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tamanho - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tamanho; i++)
            vetor[i] = b[i];
        exp *= 10;
    }

    free(b);
}


int main(void)
{
    int a, dados;
    printf("Entre com a quantidade:");
    scanf("%d",&dados);
    srand(time(NULL));
    int *numeros = (int*)malloc(dados*sizeof(int));
    srand(time(NULL));
    for(int i=0; i<30; i++)
    {
        for (a = 0; a < dados; a++)
        {
            numeros[a]=rand();
        }

        time1 = (double)clock();
        time1 = time1 / CLOCKS_PER_SEC;
        radixsort(numeros, dados); //Função
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




        for (a = 0; a < dados; a++)
        {
            printf("\n%d\n", numeros[a]);
        }

        printf("\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n",i+1, timedif);
    }
    return 0;
}
