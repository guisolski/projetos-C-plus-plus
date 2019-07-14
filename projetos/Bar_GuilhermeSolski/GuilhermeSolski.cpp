#include "biblaureano.h"
int main()
{
    noecho(true);
    desligaCursor(true);

    string alvo = retornaConteudoArquivo("GuilhermeSolski.txt");
    string dardo = retornaConteudoArquivo("GuilhermeSolski2.txt");
    string opcoes [ ] = { "Fácil " , " Médio " , " Difícil " , " Impossível ", "Exit" } ;
    int opcao = mostraMenuH ( 10 , 10 , opcoes , 5, WHITE , GREEN) ;

    Imagem alvo1 (alvo,18,5);
    alvo1.setLimites(30,5,50,10);
    Imagem dardo1 (dardo,34,20);
    dardo1.setLimites(0,0,50,20);
    alvo1.imprime();

    int movDardo = 0;
    int pontos = 0;
    int tentativas = 3;
    int t = 0;

    while(true)
    {
        if(opcao == 1)
        {
            t = 2000;
        }
        if(opcao == 2)
        {
            t = 1500;
        }
        if(opcao == 3)
        {
            t = 1000;
        }
        if(opcao == 4)
        {
            t = 500;
        }
        if(opcao == 5)
        {
            limparTela();
            cout<<"Game Over. ";
            break;
        }
        limparTela();


        dardo1.imprime();

        while (true)
        {

            alvo1.limpa();
            dardo1.limpa();
            int movAlvo = randomico(1,4);
            if (kbhit())
            {

                char tecla = getch();

                if (tecla == 'f' || tecla == 'F')
                {
                    movDardo = 1;

                }
                if (tecla == 'a')
                {
                    dardo1.decrementaX();
                }
                if (tecla == 'd')
                {
                    dardo1.incrementaX();
                }
            }

            dardo1.imprime();

            if (movAlvo == 1)
            {
                alvo1.limpa();
                alvo1.decrementaX();
                alvo1.decrementaX();

                alvo1.imprime();
                espera(t);

            }
            if (movAlvo == 2)
            {
                alvo1.limpa();
                alvo1.incrementaX();
                alvo1.incrementaX();

                alvo1.imprime();
                espera(t);

            }
            if (movAlvo == 3)
            {
                alvo1.limpa();
                alvo1.decrementaY();
                alvo1.decrementaY();

                alvo1.imprime();
                espera(t);

            }

            if (movAlvo == 4)
            {
                alvo1.limpa();
                alvo1.incrementaY();
                alvo1.incrementaY();

                alvo1.imprime();
                espera(t);

            }

            if (movDardo == 1)
            {
                dardo1.limpa();
                dardo1.decrementaY();
                dardo1.decrementaY();
                dardo1.imprime();
            }

            if(dardo1.colisao(alvo1))
            {
                tentativas--;
                if (dardo1.getX() == alvo1.getX()||dardo1.getX() == alvo1.getX() + 1||dardo1.getX() == alvo1.getX() + 2||dardo1.getX() == alvo1.getX() + 8||dardo1.getX() == alvo1.getX() + 9||dardo1.getX() == alvo1.getX() + 10||dardo1.getX() == alvo1.getX() + 11)
                {
                    pontos += 10;
                }
                if (dardo1.getX() == alvo1.getX() + 3||dardo1.getX() == alvo1.getX() +6||dardo1.getX() == alvo1.getX() + 7 )
                {
                    pontos += 20;
                }

                if (dardo1.getX() == alvo1.getX() + 4||dardo1.getX() == alvo1.getX() + 5)
                {
                    pontos += 50;

                }
                dardo1.limpa();
                espera(100);
                dardo1.imprime(35,20);
                movDardo = 0;
            }

            gotoXY(63,1), cout << "pontos : " << pontos << endl;
            gotoXY(1,1),cout<<"Tentativas: "<<tentativas;
            if(tentativas == 0)
            {
            espera(500);
                limparTela();
            cout<<"Game Over. ";
                return 0;

            }

        }

    }
}
