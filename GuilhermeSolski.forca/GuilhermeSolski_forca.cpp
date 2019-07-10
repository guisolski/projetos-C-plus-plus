#include "biblaureano.h"
inline int entrada (int opcao);
inline string entradaPalavras();
int main ()
{

    Imagem morrendo1(retornaConteudoArquivo("GuilhermeSolski1.txt"),15,15),morrendo2(retornaConteudoArquivo("GuilhermeSolski2.txt"),15,15);
    Imagem morrendo3(retornaConteudoArquivo("GuilhermeSolski3.txt"),15,15),morrendo4(retornaConteudoArquivo("GuilhermeSolski4.txt"),15,15);
    Imagem morrendo5(retornaConteudoArquivo("GuilhermeSolski5.txt"),15,15),morrendo6(retornaConteudoArquivo("GuilhermeSolski6.txt"),15,15);
    Imagem morrendo7(retornaConteudoArquivo("GuilhermeSolski7.txt"),15,15),gameOver(retornaConteudoArquivo("GuilhermeSolski10.txt"),10,10);
    Imagem venceu(retornaConteudoArquivo("GuilhermeSolski9.txt"),10,10), inicio(retornaConteudoArquivo("GuilhermeSolski8.txt"),20,5);

    inicio.imprime();
    string opcoes [] = {" Normal ", " Tormento ", " Inferno ", " Nightmare ", " Sair"} ;
    int opcao = mostraMenuV (1,10, opcoes, 5, BLUE, GREEN);

    string palavra = entradaPalavras(),imprecaoDasTentativas,imprecaoDeUnderline(palavra.size(),'_'),trocaLetra=palavra;
    char entradaLetras;
    int tentativas = entrada(opcao),tamanhoDaP = palavra.size(),acertos = 0;

    limparTela();
    mudaCor(WHITE);

    gotoXY(10,10),cout<<imprecaoDeUnderline;

do{
if(opcao==5)break;
if(tentativas==6)morrendo1.imprime();
if(tentativas==5)morrendo1.limpa(),morrendo2.imprime();

if(tentativas==4)morrendo2.limpa(),morrendo3.imprime();

if(tentativas==3)morrendo3.limpa(),morrendo4.imprime();

if(tentativas==2)morrendo4.limpa(),morrendo5.imprime();

if(tentativas==1)morrendo5.limpa(),morrendo6.imprime();

if(tentativas==0)morrendo6.limpa(),morrendo7.imprime();

    gotoXY(1,3),cout<<"Tentativas restantes: "<<tentativas;
    gotoXY(1,2),entradaLetras = readChar("Entre com uma letra: ");
if(palavra.find(entradaLetras)!= string :: npos) gotoXY(1,5),cout<< "esta presente";
    else gotoXY(1,5),cout<< "Não esta presente ",--tentativas;

    imprecaoDasTentativas= entradaLetras;
        gotoXY(tentativas,4),cout<<imprecaoDasTentativas;


if(!entradaLetras!=entradaLetras){
for(int verifica = 0; verifica < tamanhoDaP; verifica++){
    if(!acertos <= tamanhoDaP){
        if(palavra[verifica] == entradaLetras){
            gotoXY(10+verifica, 10);
            cout << entradaLetras;
            gotoXY(10, 8);
            acertos++;

        }
    }
    }
}
if (acertos == tamanhoDaP){
    espera(500),limparTela();
    venceu.imprime();
    espera(500),venceu.limpa();
}
if(tentativas==0){
    espera(500),limparTela();
    gameOver.imprime();
    espera(500),gameOver.limpa();
    gotoXY(1,1),cout<<"A palavra era: "<<palavra;
    espera(500);
    }
}
while( opcao != 5);
    }
inline int entrada(int opcao){
if (opcao == 1) return 6;
if (opcao == 2) return 4;
if (opcao == 3) return 2;
if (opcao == 4) return 1;
}
inline string entradaPalavras(){
    string palavras = retornaConteudoArquivo ("forca.txt");
    string palavraSecreta = palavraAleatoria ( palavras ) ;
    return palavraSecreta;
}
