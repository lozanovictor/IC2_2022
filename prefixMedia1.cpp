/*Victor Hugo Constantino Lozano - 8910903*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

float prefixMediaI (float x[], float a[], int num_com){
    //enche o vetor x
    for(int i=0; i<num_com; i++){
        x[i]=1;
    }

    for(int i=0; i<num_com; i++){
        a[i]=0;
        for(int j=0; j<i; j++){
                a[j]=a[j]+x[j];
            }
        a[i]=a[i]/(i+1);
    }
    return 0;
}

int main (){
    float *x, *a;
    int num_com, continua=1;
    clock_t tempo1, tempo2;
    double tempo_total;

    //while pra poder testar varias vezes sem ter que resetar o programa
    while (continua == 1){
        cout <<"\n prefix1\n\n";
        cout <<"Digite o tamanho do vetor:\n";
        cin >> num_com;
        //alocando dinamicamente o espaço
        x = new float[num_com];
        a = new float[num_com];

        //começa o timer, chama a função e termina o timer
        tempo1=clock();

        prefixMediaI(x, a, num_com);

        tempo2=clock();

        tempo_total = difftime(tempo2, tempo1)/CLOCKS_PER_SEC;
        cout <<"Tempo = " << tempo_total << " \n";

        cout <<"Continuar testando? 1=sim, 2=nao\n";
        cin >> continua;
    }
    return 0;
}
