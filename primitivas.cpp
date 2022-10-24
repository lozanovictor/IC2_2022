/*Victor Hugo Constantino Lozano - 8910903*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int procura (int *v, int x){
    for (int j=0; j<=sizeof(v); j++){
        if (v[j]==x){
            return x;
        }else{
        if (j>sizeof(v)){
            return (-1);
            }
        }
    }
}

int main (){
    int *v;
    int tam, i, q, retorno;

    cout <<"Digite o tamanho do vetor:\n";
    cin >> tam;

    //alocando dinamicamente o espaço do vetor
    v = new int[tam];

    cout <<"Insira os valores do vetor de inteiros\n";
    for(i=0; i<tam; i++){
        cin >> v[i];
    }

    cout <<"Digite um termo para a busca no vetor\n";
    cin >> q;
    retorno = procura(v, q);

    if (retorno>=0){
        cout <<"O numero buscado esta na posicao: \n" << retorno;
    } else {
        cout <<"O numero buscado nao esta no vetor\n";
    }

 return 0;
}
