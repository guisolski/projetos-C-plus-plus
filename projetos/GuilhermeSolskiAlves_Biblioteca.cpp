#include <math.h>
#include <iostream>
#define PI 3.14159265
using namespace std;
double grausParaRadiano (double anguloGraus) ///volta o angulo de graus para radiano
{

    return (anguloGraus * PI / 180);
}
double radianosParaGraus (double anguloRadiano) ///volta radianos em graus
{

    return (anguloRadiano / PI * 180);
}
double calculaSeno (double anguloGraus) /// retorna o seno
{

    return sin (anguloGraus);
}
double calculaCosseno (double anguloGraus) /// retorna o cosseno
{

    return cos (anguloGraus);
}
double calculaTangente (double anguloGraus) /// retorna a tangente
{

    return tan (anguloGraus);
}
double calculaArcoSeno (double seno) ///retorna o arco seno
{

    return asin (seno) * 180 / PI;
}
double calculaArcoCosseno (double cosseno) /// retorna o arco cosseno
{

    return acos (cosseno) * 180 / PI;
}
double calculaArcoTangente (double tangente) ///retorna o arco tangente
{
    return atan (tangente) * 180 / PI;
}
void DecompoeVetorBi(float modulo,float angulo) ///pega o modulo e angulo de um vetor e retorna Vx e Vy
{
    float cosenoDoAngulo =cos(angulo);
    int Vy= modulo * cosenoDoAngulo;
    int Vx= Vy* cosenoDoAngulo;
    return;
}
float CalculoModuloVetor(float vetor[3]) ///pega Vx e Vy e Vz e retorna o modulo
{
    float media=sqrt((vetor[0]*vetor[0])+(vetor[1]*vetor[1])+(vetor[2]*vetor[1]));
    return media;
}
float CalculoTangenteVetorHorizontalBi(float vetor[2]) /// retorna o a tangente com o vetor na horizontal
{
    float tangente= vetor[0]/vetor[1];
    return tangente;
}
float CalculoProdutoEscalar(float vetorA[3], float vetorB[3]) ///retorna o proguto escalar entre dois vetores
{
    int valorTotal=vetorA[0]*vetorB[1]+vetorA[0]*vetorB[2]+vetorA[1]*vetorB[0]+vetorA[1]*vetorB[2]+vetorA[2]*vetorB[0]+vetorA[2]*vetorB[1];
    return valorTotal;
}
void CalculoProdutoVetorial(float vetorA[3], float vetorB[3]) ///retorna o produto vetorial de dois vetores
{
    float resultanteI = (vetorA[1]*vetorB[2])-(vetorA[2]*vetorB[1]);
    float resultanteJ = (vetorA[2]*vetorB[0])-(vetorA[0]*vetorB[2]);
    float resultanteK = (vetorA[0]*vetorB[1])-(vetorB[0]*vetorA[1]);
    return;
}
void CalculoSomaESubtracaoVetor(float vetorA[3], float vetorB[3],bool subtracao) ///retorna a soma e ou a subtração de dois vetores
{
    if(subtracao == true)
    {
        int i = (vetorA[0]+vetorB[0]),j = (vetorA[1]+vetorB[1]);
        int k = (vetorA[2]+vetorB[2]);
        cout<<i<<j<<k;
        return;
    }
    else
    {
        int i = (vetorA[0]+vetorB[0]),j = (vetorA[1]+vetorB[1]);
        int k = (vetorA[2]+vetorB[2]);
        cout<<i<<j<<k;
        return;
    }
}
float CalculoAnguloEntreDoisVetores(float vetorA[3], float vetorB[3]) ///retorna o angulo entre dois vetores,A e B
{
    float moduloA=sqrt((vetorA[0]*vetorA[0])+(vetorA[1]*vetorA[1])+(vetorA[2]*vetorA[1]));
    float moduloB=sqrt((vetorB[0]*vetorB[0])+(vetorB[1]*vetorB[1])+(vetorB[2]*vetorB[1]));
    float resultado = cos(moduloA*moduloB);
    return resultado;
}
void CalculoSomaMatrizes(float matrizA[3][3], float matrizB[3][3]) ///retorna a soma entre duas matrizes
{
    int matriz1A = (matrizA[0][0] + matrizA[0][1] + matrizA[0][2]);
    int matriz1B = (matrizB[0][0] + matrizB[0][1] + matrizB[0][2]);
    int resultado1 = matriz1A + matriz1B;
    int matriz2A = (matrizA[1][0] + matrizA[1][1] + matrizA[1][2]);
    int matriz2B = (matrizB[1][0] + matrizB[1][1] + matrizB[1][2]);
    int resultado2 = matriz2A + matriz2B;
    int matriz3A = (matrizA[2][0] + matrizA[2][1] + matrizA[2][2]);
    int matriz3B = (matrizB[2][0] + matrizB[2][1] + matrizB[2][2]);
    int resultado3 = matriz3A + matriz3B;
    return;
}
void CalculoTranspostaMatriz(float matriz[3][3]) ///tranporta um matriz para um outra, retornado tranportaMatriz
{
    float tranportaMatriz[3][3];
    for(int a=0; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            matriz[a][b] = tranportaMatriz[a][b];
        }
    }
    cout<<tranportaMatriz;
    return;
}
float CalculoDeterminanteMatriz(float matriz[3][3]) ///retorna a determinante de uma matriz
{
    int diagonal = (matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[0][2]*matriz[1][0]*matriz[2][1]);
    int diagona2 = (matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[2][1]*matriz[1][2]*matriz[1][2])+(matriz[2][2]*matriz[1][0]*matriz[0][1]);
    int determinte= diagonal+diagona2;
    return determinte;
}
void CalculoProdutoMatrizes(float matrizA[3][3], float matrizB[3][3]) ///realiza o produto entre duas matriz
{
    int linha1a = ((matrizA[0][0] * matrizB[0][0]) + (matrizA[1][0] * matrizB[0][1]) + (matrizA[2][0] * matrizB[0][2]));
    int linha1b = ((matrizA[0][0] * matrizB[1][0]) + (matrizA[1][0] * matrizB[1][1]) + (matrizA[2][0] * matrizB[1][2]));
    int linha1c = ((matrizA[0][0] * matrizB[2][0]) + (matrizA[1][0] * matrizB[2][1]) + (matrizA[2][0] * matrizB[2][2]));
    int linha2a = ((matrizA[0][1] * matrizB[0][0]) + (matrizA[1][1] * matrizB[0][1]) + (matrizA[2][1] * matrizB[0][2]));
    int linha2b = ((matrizA[0][1] * matrizB[1][0]) + (matrizA[1][1] * matrizB[1][1]) + (matrizA[2][1] * matrizB[1][2]));
    int linha2c = ((matrizA[0][1] * matrizB[2][0]) + (matrizA[1][1] * matrizB[2][1]) + (matrizA[2][1] * matrizB[2][2]));
    int linha3a = ((matrizA[0][2] * matrizB[0][0]) + (matrizA[1][2] * matrizB[0][1]) + (matrizA[2][2] * matrizB[0][2]));
    int linha3b = ((matrizA[0][2] * matrizB[1][0]) + (matrizA[1][1] * matrizB[1][1]) + (matrizA[2][2] * matrizB[1][2]));
    int linha3c = ((matrizA[0][2] * matrizB[2][0]) + (matrizA[1][1] * matrizB[2][1]) + (matrizA[2][2] * matrizB[2][2]));
    return;
}
void CalculoMatrizInversa(float matriz[3][3])
{
}
///Pesquisa do cauculo de matriz inversa
/**Encontrar a matriz inversa de uma matriz conhecida é um processo que envolve multiplicação da igualdade da matrizes. Vejamos como ocorre este processo partindo da definição de uma matriz inversa.
Portanto, para encontrar a inversa de uma matriz dada, deveremos resolver a igualdade de matrizes (A.X = In). No caso em que sejam dadas duas matrizes e que seja pedido para verificar se uma matriz é a inversa da
outra, deve se efetuar-se a multiplicação destas duas matrizes. Se o resultado desta operação for a matriz identidade, afirmaremos que se trata de uma matriz inversa.
*/

///Nova Biblioteca
float MovimentoUniformeRetilino(float tempo, float velocidade[3], float  pocicaoInicial[3],float PociaoFinal[3])///Culcula o MRU(movimento retilinio);
{
    float vetorDaVelocidadePeloTempo[3];
    for(int i; i<3; i++)
    {
        vetorDaVelocidadePeloTempo[i] =velocidade[i]*tempo;
    }
    for(int a; a<3; a++)
    {
        PociaoFinal[a]= vetorDaVelocidadePeloTempo[a]+pocicaoInicial[a];
    }
    return PociaoFinal[3];
}
float MovimentoUniformenteVairiavelRetilino(float tempo, float velocidade[3], float  pocicaoInicial[3],float PociaoFinal[3],float aceleracao[3])///Culcula o MRUV(movimento variavel retilinio);
{
    float vetorDaVelocidadePeloTempo[3];
    for(int i; i<3; i++)
    {
        vetorDaVelocidadePeloTempo[i] =velocidade[i]*tempo;
    }
    for(int a; a<3; a++)
    {
        PociaoFinal[a]= vetorDaVelocidadePeloTempo[a]+pocicaoInicial[a]+(0,5*aceleracao[a]*(tempo*tempo))/2;
    }
    return PociaoFinal[3];
}

int main()
{
}
