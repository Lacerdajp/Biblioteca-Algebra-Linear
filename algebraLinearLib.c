#include<stdio.h>
// #include <algebraLinearLib.h>
#include<math.h>
void incluirVetor(int tamanho,double vetor[tamanho]){

 for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor de %d do vetor: ",i+1);
        scanf("%lf",&vetor[i]); 
    }
}
void imprimirVetor(int tamanho,double vetor[tamanho]){
     printf("O vetor final e :(");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%.6lf ",vetor[i]);
    }
    printf(")\n");
}
void duplicarVetor(int tamanho, double vetor[tamanho],double vetorDuplicado[tamanho]){
    for (int i = 0; i < tamanho; i++)
    {
        vetorDuplicado[i]=vetor[i];
    }
}
double buscaMaiorValorVetor(int tamanho,double vetor[tamanho]){
    double maior=vetor[0];
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i]>maior)
        {
            maior=vetor[i];
        }
        
    }
    return maior;
}
void produtoMatrizVetor(int tamanho,int linha,int coluna,double matriz[linha][coluna],double vetor[tamanho],double produto[tamanho]){
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            for (int k = 0; k < coluna; k++)
            {
                produto[i]=vetor[i]+matriz[j][k];
            }
            
        }
        
    }
    
}

void duplicarMatriz(int linha,int coluna,double matriz[linha][coluna],double matrizDuplicada[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matrizDuplicada[i][j]=matriz[i][j];
        }
        
    }
    
}
void zerarMatriz(int linha, int coluna, double matriz[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            matriz[i][j]=0;
        }
        
    }
    
}
void incluirMatriz(int linha,int coluna,double matriz[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        
        printf(" Digite os %d valores da linha %d,respectivamente : ",coluna,i);
        for (int  j = 0; j < coluna; j++)
        {
            scanf("%lf",&matriz[i][j]);   
            
        }
        
    }
}
void imprimirMatriz(int linha,int coluna,double matriz[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        for (int  j = 0; j < coluna; j++)
        {
            printf("%10.2lf ",matriz[i][j]);   
        }
        printf("\n");
        
    }
}
void adicionaVetorMatrizLinha(int linhasTotal,int colunasTotal,int linha, double matriz[linhasTotal][colunasTotal],double vetor[colunasTotal]){
    for (int i = 0; i < colunasTotal; i++)
    {
        matriz[linha][i]=vetor[i];
    }
    
}
void calcularTransposta(int linhas, int colunas,double matriz[linhas][colunas], double mT[linhas][colunas] )
{

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            mT[j][i] = matriz[i][j];
        }
    }
}
int isSimetrica(int linha, int coluna,double matriz[linha][coluna])
{
    double mT[linha][coluna];
    zerarMatriz(mT, linha, coluna);
    if (linha != coluna)
    {
        return 1;
    }
    else
    {
        calcularTransposta(matriz, mT, linha, coluna);
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                if (mT[i][j] != matriz[i][j])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
double triangulacaoDeterminante(int tamanho, double matriz[tamanho][tamanho]){
    double ajusteSinal=1;
    double max;
    int maxIndex;
    double temp;
    double f;
    double det=1;
    double matrizTriangularizada[tamanho][tamanho];
    duplicarMatriz(tamanho,tamanho,matriz,matrizTriangularizada);
    for (int k = 0; k < tamanho-1; k++)
    {
        max= abs(matrizTriangularizada[k][k]);
        maxIndex= k;
        for (int i = k+1; i < tamanho; i++)
        {
            if (max< abs(matrizTriangularizada[i][k]))
            {
                max=abs(matrizTriangularizada[i][k]);
                maxIndex=i;
            }
        }
        if (maxIndex!=k)
        {
            ajusteSinal=ajusteSinal*(-1);
            for (int  j = 0; j < tamanho; j++)
            {
                temp=matrizTriangularizada[k][j];
                matrizTriangularizada[k][j]=matrizTriangularizada[maxIndex][j];
                matrizTriangularizada[maxIndex][j]=temp;
            }
        }
        if (matrizTriangularizada[k][k]==0)
        {
            return 0;
        }
        else
        {
            for (int m = k+1; m < tamanho; m++)
            {
                f=-1*matrizTriangularizada[m][k]/matrizTriangularizada[k][k];
                matrizTriangularizada[m][k]=0;
                for (int l = k+1; l < tamanho; l++)
                {
                    matrizTriangularizada[m][l]=matrizTriangularizada[m][l]+f*matrizTriangularizada[k][l];
                } 
            }
        }
    }

    for (int z = 0; z < tamanho; z++)
    {
        det=det*matrizTriangularizada[z][z];
    }
    return ajusteSinal*det;
    
}
void metodoGaussJacobi(int tamanho,double matriz[tamanho][tamanho],double vetorB[tamanho],int iteracao,double valoresX[tamanho] ){
    
    double matrizX[iteracao][tamanho];
    zerarMatriz(iteracao,tamanho,matrizX);
    if (triangulacaoDeterminante(tamanho,matriz)!=0)
    {
    for (int i = 0; i < iteracao; i++)
    {   
        adicionaVetorMatrizLinha(iteracao,tamanho,i,matrizX,valoresX);
        for (int linha = 0; linha < tamanho; linha++)
        {
            valoresX[linha]=vetorB[linha];
            
            for (int coluna = 0; coluna < tamanho; coluna++)
            {
                if (linha!=coluna)
                {
                    valoresX[linha]=valoresX[linha]-matriz[linha][coluna]*matrizX[i][coluna];
                    
                }
                
            }
            valoresX[linha]=valoresX[linha]/matriz[linha][linha];
           
        }
    }
    }
    else
    {
        printf("impossivel calcular pelo metodo de gauss, pois o determinante da matriz e igual a 0");
    }
    
    
}
void metodoGaussSeidel(int tamanho,double matriz[tamanho][tamanho],double vetorB[tamanho],int iteracao,double valoresX[tamanho]){
 double matrizX[iteracao][tamanho];
    zerarMatriz(iteracao,tamanho,matrizX);
    if (triangulacaoDeterminante(tamanho,matriz)!=0)
    {
    for (int i = 0; i < iteracao; i++)
    {   
        adicionaVetorMatrizLinha(iteracao,tamanho,i,matrizX,valoresX);
        for (int linha = 0; linha < tamanho; linha++)
        {
            valoresX[linha]=vetorB[linha];
            
            for (int coluna = 0; coluna < tamanho; coluna++)
            {
                if (linha<coluna)
                {
                    valoresX[linha]=valoresX[linha]-matriz[linha][coluna]*matrizX[i][coluna];
                    
                }else if (linha>coluna)
                {
                    valoresX[linha]=valoresX[linha]-matriz[linha][coluna]*valoresX[coluna];
                }
            }
            valoresX[linha]=valoresX[linha]/matriz[linha][linha];
           
        }
    }
    }
    else
    {
        printf("impossivel calcular pelo metodo de gauss, pois o determinante da matriz e igual a 0");
    }
    
    
}
void metodoSOR(int tamanho,double matriz[tamanho][tamanho],double vetorB[tamanho],int iteracao,double valoresX[tamanho],double omega){
double matrizX[iteracao][tamanho];
    zerarMatriz(iteracao,tamanho,matrizX);
    if (triangulacaoDeterminante(tamanho,matriz)!=0)
    {
    for (int i = 0; i < iteracao; i++)
    {   
        adicionaVetorMatrizLinha(iteracao,tamanho,i,matrizX,valoresX);
        for (int linha = 0; linha < tamanho; linha++)
        {
            valoresX[linha]=vetorB[linha];
            
            for (int coluna = 0; coluna < tamanho; coluna++)
            {
                if (linha<coluna)
                {
                    valoresX[linha]=valoresX[linha]-matriz[linha][coluna]*matrizX[i][coluna];
                    
                }else if (linha>coluna)
                {
                    valoresX[linha]=valoresX[linha]-matriz[linha][coluna]*valoresX[coluna];
                }
            }
            valoresX[linha]=(omega*valoresX[linha]/matriz[linha][linha])+(1-omega)*matrizX[i][linha];
           
        }
        imprimirVetor(tamanho,valoresX);
    }
    }
    else
    {
        printf("impossivel calcular pelo metodo de gauss, pois o determinante da matriz e igual a 0");
    }
    
    
}
void metodoGradiente(int tamanho,double matriz[tamanho][tamanho],double vetorB[tamanho],int iteracao,double valoresX[tamanho],double omega){
    if (isSimetrica(tamanho,tamanho,matriz)!=0)
    {
        printf("Matriz nao Simetrica");
    }
    else{
        double r[tamanho];
        produtoMatrizVetor(tamanho,tamanho,tamanho,matriz,vetorB,r);
        duplicarVetor(tamanho,r,valoresX);

    }
}


int main(){
    int coluna=0,linha=0;
    int tamanho=0;
    // scanf("%d",&coluna);
    // scanf("%d",&linha);
    scanf("%d",&tamanho);
    coluna=linha=tamanho;
    double matriz[linha][coluna];
    double vetor[tamanho];
    double vetor2[tamanho];
    double valor=0;
    incluirMatriz(linha,coluna, matriz);
    incluirVetor(tamanho,vetor);
    incluirVetor(tamanho,vetor2);
    metodoSOR(tamanho,matriz,vetor,3,vetor2,0.5);
    imprimirVetor(tamanho,vetor2);
    return 0;
}