/*Victor Hugo Constantino Lozano - 8910903*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

float prefixMediaII(float x[], float a[], float s[], int num_com){
    //enche o vetor x
    for(int i=0; i<num_com; i++){
        x[i]=1;
        s[i]=0;
    }
    for(int i=0; i<num_com; i++){
        s[i]=s[i]+x[i];
        a[i]=s[i]/(i+1);
        }
    return 0;
}


int main (){
    float *x, *a, *s;
    int num_com, continua=1;
    clock_t tempo1, tempo2;
    double tempo_total;

    while (continua == 1){
        cout <<"\nPrefix2\n\n";
        cout <<"Digite o tamanho do vetor:\n";
        cin >>num_com;

        //alocando dinamicamente o espaço
        x = new float[num_com];
        a = new float[num_com];
        s = new float[num_com];

        tempo1=clock();

        prefixMediaII(x, a, s, num_com);

        tempo2=clock();
        tempo_total=difftime(tempo2, tempo1)/CLOCKS_PER_SEC;
        cout <<"Tempo = " << tempo_total<< " \n";

        cout <<"Continuar testando? 1=sim, 2=nao\n";
        cin >> continua;
    }
    return 0;
}
