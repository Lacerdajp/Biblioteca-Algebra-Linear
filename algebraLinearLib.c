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
void incluirVetorArquivo(int tamanho,double vetor[tamanho],FILE* fp){

 for (int i = 0; i < tamanho; i++)
    {
         printf("Valor de %d do vetor: ",i+1);
        fscanf(fp,"%lf",&vetor[i]); 
        printf("%.2lf\n",vetor[i]);
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
void zerarVetor(int tamanho,double vetor[tamanho]){
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i]=0;
    }
    
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
        for (int j = 0; j < linha; j++)
        {
            for (int k = 0; k < coluna; k++)
            {
                
                
              produto[j]= k==0? (vetor[k]*matriz[j][k]):(vetor[k]*matriz[j][k])+produto[j];
            }
            
        }
    
}
void subtracaoVetores(int tamanho,double vetor1[tamanho],double vetor2[tamanho],double resultado[tamanho]){
    for (int i = 0; i < tamanho; i++)
    {
        resultado[i]=vetor1[i]-vetor2[i];
    }
    
}
void somaVetores(int tamanho,double vetor1[tamanho],double vetor2[tamanho],double resultado[tamanho]){
    for (int i = 0; i < tamanho; i++)
    {
        resultado[i]=vetor1[i]+vetor2[i];
    }
    
}
double produtoEscalar(int tamanho,double vetor1[tamanho],double vetor2[tamanho]){
    double valor=0;
    for (int i = 0; i < tamanho; i++)
    {
        valor=(vetor1[i]*vetor2[i])+valor;
    }
    return valor;
    
}
double magnitude(int n, double a[n])
{
    double somatorio = 0;
    for (int i = 0; i < n; i++)
    {
        somatorio = somatorio + (a[i] * a[i]);
    }
    return sqrt(somatorio);
}
void produtoVetorEscalar(int tamanho, double vetor1[tamanho],double escalar,double resultado[tamanho]){
    for (int i = 0; i < tamanho; i++)
    {
        resultado[i]=vetor1[i]*escalar;
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
void incluirMatrizArquivo(int linha,int coluna,double matriz[linha][coluna],FILE*fp){
    for (int i = 0; i < linha; i++)
    {
        
        printf(" Digite os %d valor""es da linha %d,respectivamente : ",coluna,i);
        for (int  j = 0; j < coluna; j++)
        {
            // scanf("%lf",&matriz[i][j]);   
            fscanf(fp,"%lf",&matriz[i][j]);
            printf("%.2lf ",matriz[i][j]);
        }
        printf("\n");
        
    }
}
void incluirMatriz(int linha,int coluna,double matriz[linha][coluna]){
    for (int i = 0; i < linha; i++)
    {
        
        printf(" Digite os %d valor""es da linha %d,respectivamente : ",coluna,i);
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
    if (linha != coluna)
    {
        return 1;
    }
    else
    {
         
        calcularTransposta(linha, coluna,matriz, mT);
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
        max= fabs(matrizTriangularizada[k][k]);
        maxIndex= k;
        for (int i = k+1; i < tamanho; i++)
        {
            if (max< fabs(matrizTriangularizada[i][k]))
            {
                max=fabs(matrizTriangularizada[i][k]);
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
        double d[tamanho];
        double alfa=0;
        produtoMatrizVetor(tamanho,tamanho,tamanho,matriz,valoresX,r);
        subtracaoVetores(tamanho,vetorB,r,r);
        duplicarVetor(tamanho,r,d);
        for (int i = 0; i < iteracao&&magnitude(tamanho,r)>omega; i++)
        {
            alfa=0;
            double Ad[tamanho];
            double temp[tamanho];
            double proximoR[tamanho];
            zerarVetor(tamanho,Ad);
            produtoMatrizVetor(tamanho,tamanho,tamanho,matriz,d,Ad);
            alfa=produtoEscalar(tamanho,r,d)/produtoEscalar(tamanho,d,Ad);
            produtoVetorEscalar(tamanho,d,alfa,temp);
            somaVetores(tamanho,valoresX,temp,valoresX);
            produtoVetorEscalar(tamanho,Ad,alfa,temp);
            subtracaoVetores(tamanho,r,temp,proximoR);
            alfa=produtoEscalar(tamanho,proximoR,proximoR)/produtoEscalar(tamanho,r,r);
            produtoVetorEscalar(tamanho,d,alfa,temp);
            somaVetores(tamanho,proximoR,temp,d);
            
            duplicarVetor(tamanho,proximoR,r);
            free(proximoR);
            free(temp);
            free(Ad);
        }
        
        
    }
}


int main(){
    int coluna=0,linha=0;
    int tamanho=0;
    FILE* fp=fopen("teste.txt","r");
    // scanf("%d",&coluna);
    // scanf("%d",&linha);
    fscanf(fp,"%d",&tamanho);
    printf("%d",tamanho);
    coluna=linha=tamanho;
    double matriz[linha][coluna];
    double vetor[tamanho];
    double vetor2[tamanho];
    double valor=0;
    incluirMatrizArquivo(linha,coluna, matriz,fp);
    incluirVetorArquivo(tamanho,vetor,fp);
    incluirVetorArquivo(tamanho,vetor2,fp);
    fclose(fp);
    metodoGradiente(tamanho,matriz,vetor,2,vetor2,0.01);
    imprimirVetor(tamanho,vetor2);
    return 0;
}
