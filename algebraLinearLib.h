#ifdef ALGEBRA_LINEAR_H
#define ALGEBRA_LINEAR_H

/*essa função é feita para incluir valores,de tipo double, a um vetor de um tamanho n.
Deve-se passar como parametros o  tamanho do vetor, de tipo inteiro,e um vetor(double).
Ele solicitará que vc digite os valores a ser adicionados no vetor, de acordo com o tamanho passado
Obs: Essa função altera o vetor via ponteiro, logo não há necessidade de um retorno */
void incluirVetor(int tamanho,double vetor[tamanho]);
/*Essa função é utilizada para imprimir os valores armazenados dentro de um vetor de tipo double.
Deve-se passar como parametros o tamanho do vetor,de tipo inteiro, e um vetor de tipo double.
Ele irá imprimir no console  os valores que estão armazenados no vetor.
OBS;Essa função não altera valores logo nao tem retornos.
*/
void imprimirVetor(int tamanho,double vetor[tamanho]);
/*
Essa função passa os valores de um vetor para outro vetor, os dois de tipo double.
Deve-se passar como parametros o  tamanho do vetor, de tipo inteiro,e um vetor de tipo double cujo
não será alterado, e um outro vetor de tipo double, que os valores serão atribuidos do primeiro vetor.
OBS:  Essa função altera o vetor via ponteiro, logo não há necessidade de um retorno
*/
void duplicarVetor(int tamanho, double vetor[tamanho],double vetorDuplicado[tamanho]);


double buscaMaiorValorVetor(int tamanho,double vetor[tamanho]);

void duplicarMatriz(int linha,int coluna,double matriz[linha][coluna],double matrizDuplicada[linha][coluna]);

void zerarMatriz(int linha, int coluna, double matriz[linha][coluna]);

void incluirMatriz(int linha,int coluna,double matriz[linha][coluna]);

void imprimirMatriz(int linha,int coluna,double matriz[linha][coluna]);

void adicionaVetorMatrizLinha(int linhasTotal,int colunasTotal,int linha, double matriz[linhasTotal][colunasTotal],double vetor[colunasTotal]);

double triangulacaoDeterminante(int tamanho, double matriz[tamanho][tamanho]);

void metodoGaussJacobi(int tamanho,double matriz[tamanho][tamanho],double vetorB[tamanho],int iteracao,double valoresX[tamanho] );
#endif