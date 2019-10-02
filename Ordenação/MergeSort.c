#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double time1, timedif;

void merge(int *V, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tam, i, j, k;
    int fim1 = 0, fim2 = 0;

    tam = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(tam * sizeof(int));
    if (temp != NULL)
    {
        for (i = 0; i < tam; i++)
        {
            if (!fim1 && !fim2)
            {
                if (V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }
        for (j = 0, k = inicio; j < tam; j++, k++)
            V[k] = temp[j];
    }
}

void mergeSort(int *V, int inicio, int fim)
{
    int meio;
    time1 = (double)clock();
    time1 = time1 / CLOCKS_PER_SEC;
    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
    timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
}

int main(void)
{
    int a, dados;
    printf("Entre com a quantidade:");
    scanf("%d",&dados);
    int *numeros = (int*)malloc(dados*sizeof(int));
    srand(time(NULL));
    for(int i=0; i<30; i++)
    {
        for (a = 0; a < dados; a++)
        {
            numeros[a]=rand()%100;
        }

        time1 = (double)clock();
        time1 = time1 / CLOCKS_PER_SEC;
        mergeSort(numeros,0, dados); //Função
        timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;

       /* for (a = 0; a < 10; a++)
        {
            printf("\n%d\n", numeros[a]);
        }*/

        printf("\n--------------------------\nTempo da Ordenação: %.3fs\n--------------------------\n", timedif);
    }
    return 0;
}
