#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Contadores de comparação e movimento são globais
int cont = 0, mov = 0;
//Inserção Direta
int insertion(int vetor[], int tam){
   int i, j, aux;
   //zerando os contadores caso já exista alguma coisa na memoria
   cont=0;
   mov=0;
      for (i = 1; i <= tam; i++){
         aux = vetor[i];
         j = i - 1;
         while (j >= 0 && aux < vetor[j]) {
            cont++;
            vetor[j+1] = vetor[j];
            j--;
            mov++;
         }

      vetor[j+1] = aux;
      mov++;
      }
   return (*vetor, cont, mov);
}

//Inserção Binaria
int binaria(int vetor[], int tam){
   int i,j,x,m,L,R;
   //zerando os contadores caso já exista alguma coisa na memoria
   cont=0;
   mov=0;
	for(i=2; i<tam; i++){
		x = vetor[i];
		L = 1;
		R = i;
		while(L < R){
			cont++;
         m = floor( (L+R) /2);
			if(vetor[m] <= x){
				cont++;
            L = m + 1;
         }else{
				R = m;
         }
      }
		j = i;
		while(j > R){
         cont++;
			vetor[j] = vetor[j-1];
			j = j-1;
         mov++;
		}
		vetor[R] = x;
      mov++;
	}
	return(*vetor, cont, mov);
}

//Seleção
int selecao(int vetor[], int tam){
   int i,j,x,m;
   //zerando os contadores caso já exista alguma coisa na memoria
   cont=0;
   mov=0;
   for(i=1; i<(tam-1); i++){
		m = i;
		for (j=(i+1); j<tam; j++){
         cont++;
			if(vetor[j] < vetor[m]){
				m = j;
         }
		x = vetor[i];
      mov++;
		vetor[i] = vetor[m];
		mov++;
      vetor[m] = x;
      mov++;
	   }
   }
   return (*vetor, cont, mov);
}

//bubblesort
int bubble(int vetor[], int tam){
   int i,j,x;
   //zerando os contadores caso já exista alguma coisa na memoria
   cont=0;
   mov=0;
   for(i=2;i<tam;i++){
		for(j=(tam-1); j>=i; j--){
         cont++;
			if(vetor[j-1]>vetor[j]){
				x = vetor[j-1];
            mov++;
				vetor[j-1] = vetor[j];
            mov++;
				vetor[j] = x;
            mov++;
			}
		}
	}
   return (*vetor, cont, mov);
}

//Heapsort
// troca o valor de duas variaveis
void troca(int *dado1,int *dado2) {
	int temp;
	temp=*dado1;
   mov++;
	*dado1=*dado2;
	mov++;
   *dado2=temp;
   mov++;
}

// devolve o índice do filho esquerdo no no de indice i
int filho_esq(int i) {
	return 2*i;
}

// devolve o indice do filho direito do no de indice i
int filho_dir(int i) {
	return 2*i+1;
}

// efetua um push down no no de indice i
void pushDown(int i,int heap[],int tam) {
	int ha_esq=0,ha_dir=0;

	if (filho_esq(i)<=tam){
		cont++;
      ha_esq=1;
   }
	if (filho_dir(i)<=tam){
		cont++;
      ha_dir=1;
   }

	if (ha_esq&&!ha_dir) {
		if (heap[i] < heap[filho_esq(i)]) {
         cont++;
			troca(&heap[filho_esq(i)], &heap[i]);
			pushDown(filho_esq(i), heap, tam);
		}
	}
	else
		if (ha_esq&&ha_dir) {
         cont++;
			if ((heap[i] < heap[filho_esq(i)]) || (heap[i] <heap[filho_dir(i)])) {
				cont++;
            if (heap[filho_esq(i)] > heap[filho_dir(i)]) {
					cont++;
               troca(&heap[filho_esq(i)], &heap[i]);
					i = filho_esq(i);
				}
				else {
					troca(&heap[filho_dir(i)], &heap[i]);
					i = filho_dir(i);
				}
			pushDown(i,heap,tam);
			}
		}
}

// funcao para fazer a montagem da heap
void montaHeap(int heap[], int tam) {
	int i;
	for (i=tam/2; i>=1; i--){
		pushDown(i, heap, tam);
   }
}

// funcao para fazer a desmontagem da heap
void desmontaHeap(int heap[], int tam) {
	int i;
	for (i=1; i<=tam; i++) {
		troca(&heap[1], &heap[tam]);
      mov++;
		tam--;
		pushDown(1, heap, tam);
	}
}

void heap (int vetor[], int tam){
   //zerando os contadores caso já exista alguma coisa na memoria
   cont=0;
   mov=0;
   montaHeap(vetor, tam);
	desmontaHeap(vetor, tam);
}

//Fusão
int fusao(int vetor[], int tam, int vetor2[], int tam2, int fus[], int tam_fus){
   int i = 0;
   int j = 0;
   int k = 0;
   while( (i<tam) && (j<tam2) ){
		k++;
		if (vetor[i] < vetor2[j]){
         cont++;
			fus[k-1] = vetor[i];
			mov++;
         i++;
		}
		else{
			fus[k-1] = vetor2[j];
         mov++;
			j++;
		}
	}

	while (i<tam){
		k++;
		fus[k-1] = vetor[i];
		mov++;
      i++;
	}

	while(j<tam2){
		k++;
	   fus[k-1] = vetor2[j];
		mov++;
      j++;
	}
   return (*fus);
}

//Quicksort
int partition( int vetor[], int l, int r) {
   int pivo, i, j, t;
   pivo = vetor[l];
   i = l;
   j = r+1;
		
   while(1){
		do{
			i++;
         cont++;
      }
      while( vetor[i] <= pivo && i <= r );
		do{
			j--;
         cont++;
      }
      while( vetor[j] > pivo );
		if( i >= j ){
         cont++;
			break;
      }
		t = vetor[i];
      mov++;
		vetor[i] = vetor[j];
      mov++;
		vetor[j] = t;
      mov++;
   }
   t = vetor[l];
   mov++;
   vetor[l] = vetor[j];
   mov++;
   vetor[j] = t;
   mov++;
   return j;
}

int quick(int vetor[], int l, int r){     //l e r são as pontas do vetor 
   int j;
	if( l < r ) {
		j = partition( vetor, l, r);
		quick( vetor, l, j-1);
		quick( vetor, j+1, r);
   }
   return (*vetor);
}

int main(){
   int tam, tam2, tam_fus, i, menu = 9;
   int *vetor, *vetor2, *fus; 

   //alocando o vetor
   cout << "Insira o tamanho do vetor: (tamanho >= 5) \n";
   cin >> tam;
   vetor = new int[tam];
   //obtendo os dados a serem organizados
   cout << "Digite os elementos do vetor: \n";
   for (i = 1; i<=tam; i++){
      cin >> vetor[i];
   }

   //menu
   while (menu!=0){
   cout << "Selecione um algoritimo de ordenacao: \n";
   cout << "1: Insercao Direta \n";
   cout << "2: Insercao Binaria \n";
   cout << "3: Selecao \n";
   cout << "4: Bubblesort \n";
   cout << "5: Heapsort \n";
   cout << "6: Fusao \n";
   cout << "7: Quicksort \n";
   cout << "0: Sair \n";
   cin >> menu;
      switch (menu){
         case 1:
            insertion(vetor, tam);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;

         case 2:
            binaria(vetor, tam);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;

         case 3:
            selecao(vetor, tam);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;

         case 4:
            bubble(vetor, tam);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;

         case 5:
            heap(vetor, tam);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;

         case 6:
            cout << "Fusão usa 2 vetores";
            //alocando o vetor
            cout << "Insira o tamanho do segundo vetor: (tamanho >= 5) \n";
            cin >> tam2;
            vetor2 = new int[tam2];
            //obtendo os dados a serem organizados
            cout << "Digite os elementos do vetor: \n";
            for (i = 1; i<=tam2; i++){
               cin >> vetor2[i];
            }

            //alocando o vetor de resposta
            tam_fus=tam+tam2;
            fus = new int[tam_fus];

            fusao(vetor, tam, vetor2, tam2, fus, tam_fus);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;

         case 7:
            quick(vetor, 1, tam);
            for (i = 0; i<=tam; i++){
               cout << vetor[i] << " ";
            }
            cout << "Numero de comparações: " << cont << "\n";
            cout << "Numero de movimentos: " << mov << "\n";
         break;
      }
   }
   return 0;
}