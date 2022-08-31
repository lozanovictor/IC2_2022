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

    int i, n, x, m, pesquisa, menu=3;
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

        if (menu == 1){
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
                A[x].media=(A[x].nota1+A[x].nota2)/2;
                }
        }
        else{
            if (menu == 2){
                cout <<"Busca de dados\n" ;
                cout <<"Digite o numero USP para a pesquisa:\n" ;
                cin >> pesquisa;
                for (m=0; m<=i; m++){
                    if (pesquisa == A[m].num_usp){
                        cout <<"Numero USP: \n" << A[m].num_usp ;
                        cout <<"Primeira nota: \n" << A[m].nota1 ;
                        cout <<"Segunda nota: \n" << A[m].nota2 ;
                        cout <<"Media final: \n" << A[m].media ;
                        }
                        else{
                            cout << "Nao encontrado! \n";
                        }
                    }
                }
                else{
                    if (menu == 3){
                       cout << "Medias \n";
                            for (x=0; x<=i; x++){
                                media = media+A[x].media;
                            }
                            media = media/x;
                            cout << "A media da turma e: \n" << media;
                            cout << "Desvio padrao \n";
                            for (x=0; x<=i; x++){
                                aux = aux + pow(A[x].media - media, 2);
                            }
                            aux = sqrt(aux/x);
                            cout << "Desvio padrao das medias e: " << aux;
                        }
                        else{
                            if (menu == 0) {
                                cout <<"\n Saindo..." ;
                                delete[] A;             //Limpa, limpa, limpa
                                }
                            else{
                                cout <<"\nOpcao invalida, tente novamente: \n" ;
                                cin >> menu;
                            }
                        }
                    }
                }
            }
    return 0;
}
