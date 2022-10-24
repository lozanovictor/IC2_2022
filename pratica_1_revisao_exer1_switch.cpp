// Victor Hugo Constantino Lozano - 8910903
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

//struct estudante
struct estudante{
    int num_usp;	            //inteiro com o numero usp
    float nota1;		        //float com a nota1
    float nota2;                //float com a nota2
    float media;                //float com a media
};


int main (){

    int i=1, n, x, m, pesquisa, menu=3;
    float media=0, aux=0;
    estudante* A = nullptr;

    cout << "Cadastro de alunos\n";
    /*menu*/
    while(menu != 0){
        cout << "\nMenu:\n";
        cout << "1: Entrar dados \n" ;
        cout << "2: Mostrar dados \n" ;
        cout << "3: Medias \n";
        cout << "0: Sair \n" ;
        cout << "Digite a opcao desejada \n" ;
        cin >> menu;

        switch (menu){
        case 1:
            cout <<"\nEntrada de dados \n" ;
            cout <<"Digite a quantidade de alunos: \n" ;
            cin >> i;
            i=i-1;      //array se inicia no zero, então a quantidade entrada pelo usuario tem que ser ajustada
            A = new estudante[i];

            for (x=0; x<=i; x++){
                cout <<"Digite o numero USP: \n" ;
                cin >> A[x].num_usp;
                cout <<"\n Digite a primeira nota: \n" ;
                cin >> A[x].nota1;
                cout << "\n Digite a segunda nota: \n" ;
                cin >> A[x].nota2;
                A[x].media = (A[x].nota1+A[x].nota2)/2;
                }
        break;

        case 2:
                cout <<"Busca de dados\n" ;
                cout <<"Digite o numero USP para a pesquisa:\n" ;
                cin >> pesquisa;
                for (m=0; m<=i; m++){
                    if (pesquisa == A[m].num_usp){
                        cout <<"Numero USP: " << A[m].num_usp << " \n";
                        cout <<"Primeira nota: " << A[m].nota1 << " \n";
                        cout <<"Segunda nota: " << A[m].nota2 << " \n";
                        cout <<"Media final: " << A[m].media << " \n";
                        }
                    }
        break;

        case 3:
               cout << "Medias \n";
                for (x=0; x<=i; x++){
                    media = media+A[x].media;
                    }
                    media = media/x;
                    cout << "A media da turma e: " << media << " \n";
                    cout << "Desvio padrao \n";
                        for (x=0; x<=i; x++){
                            aux = aux + pow(A[x].media - media, 2);
                        }
                        aux = sqrt(aux/x);
                        cout << "Desvio padrao das medias e: " << aux << " \n";
        break;

        case 0:
            cout <<"\n Saindo..." ;
            delete[] A;             //Limpa, limpa, limpa
        break;

        }
    }
    return 0;
}
