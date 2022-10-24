/*Victor Hugo Constantino Lozano - 8910903*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main (){
    float *x, *a, *s;
    int i, j, num_com;
    clock_t tempo1, tempo2;
    double tempo_total;

    printf("Digite o tamanho do vetor:\n");
    cin >>"%d", &num_com);

    //alocando dinamicamente o espaço
    x = (float *) malloc(num_com * sizeof(float));
    a = (float *) malloc(num_com * sizeof(float));
    s = (float *) malloc(num_com * sizeof(float));

    //enche o vetor x
    for(i=0; i<num_com; i++){
        x[i]=1;
        s[i]=0;
    }

    tempo1=clock();

    for(i=0; i<num_com; i++){
        s[i]=s[i]+x[i];
        a[i]=s[i]/(i+1);
        }
    tempo2=clock();
    tempo_total=difftime(tempo2, tempo1)/CLOCKS_PER_SEC;
    printf("Tempo = %g \n", tempo_total);
    return 0;
}
