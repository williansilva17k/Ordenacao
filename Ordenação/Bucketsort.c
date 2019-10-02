        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>
        #include <math.h>

        #define TAM 1000000

        struct balde
        {
            int qtd;
            int vl[TAM];
        };


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

        void bucketSort(int *v,int n)
        {
            int i,j,maior,menor,nbaldes,pos;
            struct balde *bd;
            maior=menor=v[0];

            for(i=1; i<n; i++)
            {
                if(v[i]>maior)
                {
                    maior = v[i];
                }
                if(v[i]<menor)
                {
                    menor = v[i];
                }
            }

            nbaldes = (maior-menor) / TAM + 1;

            bd = (struct balde *)malloc(nbaldes * sizeof(struct balde));

            for(i=0; i<nbaldes; i++)
            {
                bd[i].qtd=0;
            }

            for(i=0; i<n; i++)
            {
                pos=(v[i]-menor)/TAM;
                bd[pos].vl[bd[pos].qtd]=v[i];
                bd[pos].qtd++;
            }
            pos = 0;
            for(i=0; i<nbaldes; i++)
            {
                bubble(bd[i].vl,bd[i].qtd);
                for(j=0; j<bd[i].qtd; j++)
                {
                    v[pos] = bd[i].vl[j];
                    pos++;
                }
            }
            free(bd);
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
                bucketSort(numeros, dados); //Função
                timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;




                /* for (a = 0; a < 10; a++)
                 {
                     printf("\n%d\n", array[a]);
                 }*/

                printf("\n--------------------------\nTempo gasto: %.3fs\n--------------------------\n", timedif);
            }
            return 0;
        }
