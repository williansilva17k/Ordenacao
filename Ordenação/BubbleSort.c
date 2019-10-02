#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double time1, timedif;

void bubble(int *v,int tam)
        {
            int i,j,temp,aux;
            if(tam)
                for(j=0; j<tam-1; j++)
                {
                    aux=0;
                    for(i=0; i<tam-1; i++)
                    {
                        if(v[i+1]<v[i])
                        {
                            temp=v[i];
                            v[i]=v[i+1];
                            v[i+1]=temp;
                            aux=1;
                        }
                    }
                    if(!aux)
                        break;
                }
        }


int main(void){

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
                bubble(numeros, dados);
                timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




                 /*for (a = 0; a < 10; a++)
                 {
                     printf("\n%d\n", numeros[a]);
                 }*/

                printf("\n--------------------------\nTempo gasto: %.3fs\n--------------------------\n", timedif);
            }
            return 0;
        }
