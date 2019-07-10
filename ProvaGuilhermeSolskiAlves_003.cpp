#include "biblaureano.h"
int main()
	{
	desligaCursor(true), noecho(true);
	string Sponto = "*";
	Imagem Ponto (Sponto);
	int y = randomico(2,23), x = randomico(2,78), Movimentacao = randomico(1,8);
	Ponto.imprime(x,y);
	while(true)
			{
			Ponto.limpa();

			if(x<=1||x>=79)Movimentacao = randomico(2,5);
			if(y<=1||y>=24)Movimentacao = randomico(2,5);

			if(Movimentacao == 1)x++;
			if(Movimentacao == 2)x++,y--;
			if(Movimentacao == 3)x++,y++;
			if(Movimentacao == 6)x--;
			if(Movimentacao == 4)x--,y++;
			if(Movimentacao == 5)x--,y++;
			if(Movimentacao == 7)y++;
			if(Movimentacao == 8)y--;

			Ponto.imprime(x,y),espera(95);
			}
	}
