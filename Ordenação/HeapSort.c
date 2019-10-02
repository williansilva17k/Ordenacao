#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time1, timedif;

void criaHeap(int *vet, int i, int f)
{
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            if (vet[j] < vet[j + 1])
            {
                j = j + 1;
            }
        }
        if (aux < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            j = f + 1;
        }
    }
    vet[i] = aux;
}

void heapSort(int *vet, int N)
{
    int i, aux;
    for (i = (N - 1) / 2; i >= 0; i--)
    {
        criaHeap(vet, i, N - 1);
    }
    for (i = N - 1; i >= 1; i--)
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }

}

int main(void){

int a, dados;
    printf("Entre com a quantidade: ");
    scanf("%d", &dados);
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
                heapSort(numeros, dados); //Função
                timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
   /* for (a = 0; a < numeros; a++)
    {
        printf("\n%d\n", numeros[a]);
    }*/

        printf("\n--------------------------\nTempo gasto: %.3fs\n--------------------------\n", timedif);
            }
            return 0;
        }
