#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long cont = 0;
double time1, timedif;
double conta[30];

void Insercao_sort(int arr[10000000], int tam){

    time1 = (double) clock();
    time1 = time1 / CLOCKS_PER_SEC;
        int i, j, aux;
            for(i = 1; i < tam; i++){
                aux = arr[i];
                j = i - 1;
                    while((j >= 0) && (aux < arr[j])){
                        arr[j + 1] = arr[j];
                        j--;
                        cont++;
                    }
                    arr[j + 1] = aux;
            }
timedif = (((double) clock()) / CLOCKS_PER_SEC) - time1;
//printf(" %.3f xdxd\n", timedif); >> caso queria ver um por um.
}
void main(){
int z, a, dados, i;
printf("Entre com a quantidade: ");
scanf("%d", &dados);
srand(time(NULL));

for(z = 0; z < 30; z++){

    int *num = (int*)malloc(dados*sizeof(int));

        for(a = 0; a < dados; a++){
            num[a] = rand();
        }
        Insercao_sort(num, dados);
        conta[z] = timedif;
}
            for(int a = 0; a < 30; a++){
                printf("\n--------------------------\nTempo gasto %.3f", conta[a]);
    }
}
