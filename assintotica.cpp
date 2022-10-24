/*Victor Hugo Constantino Lozano - 8910903*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
using namespace std;

float transposta (float **A, float **sup, int tam){
    for(int i=0; i<tam; i++){
            for (int j=0; j<tam; j++){
                sup[i][j]=A[j][i];
            }
    }
    return **sup;
}

float multiplicacao (float **A, float **B, float **sup, int tam){
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            for(int x=0; x<tam; x++){
                sup[i][j]=A[i][x]*B[x][j];
            }
        }
    }
    return **sup;
}

float traco (float **B, float **sup, int tam){
    for (int i=0; i<tam; i++){
        sup[i][i]+=B[i][i];
    }
    return **sup;
}

int main() {
    float **A, **B, **sup;
    int tam, i, j, menu=0;


    cout << "Menu\n";
    cout << "Digite a dimensao da matriz quadrada:\n";
    cin >> tam;

    //alocando dinamicamente o espaço das matrizes
    //alocando as linhas
    *A = new float[tam];
    //alocando as colunas
    for (i=0; i<tam; i++){
       A[i] = new float[tam];
    }
    *B = new float[tam];
    for (i=0; i<tam; i++){
       B[i] = new float[tam];
    }
    *sup = new float[tam];
    for (i=0; i<tam; i++){
       sup[i] = new float[tam];
    }

    //enchendo as matrizes com numeros aleatorios de 0 a 5
    for (i=0; i<=tam; i++){
        for(j=0; j<=tam; j++){
            A[i][j] = rand() % 6;
            B[i][j] = rand() % 6;
            sup[i][j] = 0;
        }
    }

    //menu
    cout << "Selecione uma operação:\n";
    cout << "1 - Transposta\n";
    cout << "2 - Multiplicação \n";
    cout << "3 - Traço\n";
    cout << "4 - Sair\n";
    cin >> menu;

    while(menu!=4){

        if (menu == 1){
            transposta(A, sup, tam);
            for (i=0; i<=tam; i++){
                for(j=0; j<=tam; j++){
                    cout << A[i][j] << " ";
                }
                cout << "\n";
            }
        } else{
            if (menu == 2){
                multiplicacao(A, B, sup, tam);
                for (i=0; i<=tam; i++){
                    for(j=0; j<=tam; j++){
                        cout << sup[i][j] << " ";
                    }
                    cout << "\n";
                }
            }else{
                if (menu == 3){
                    traco(B, sup, tam);
                    for (i=0; i<=tam; i++){
                        for(j=0; j<=tam; j++){
                            cout << sup[i][j] << " ";
                        }
                        cout << "\n";
                    }
                }else{
                    menu=4;
                    return(menu);
                }

            }
        }
        cout << "Selecione uma operação:\n";
        cout << "1 - Transposta\n";
        cout << "2 - Multiplicação \n";
        cout << "3 - Traço\n";
        cout << "4 - Sair\n";
        cin >> menu;

    }
    return 0;
}
