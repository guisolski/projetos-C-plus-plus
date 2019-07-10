#include "biblaureano.h"
void escolherPocicao(int b = 0);
void analisarProximo(int proximo, int m, int n, int b );
void analisarAdjacentes(int m, int n);
int numero[10][2];
int bomba;
char tabela[6][6];
void escolherPocicao(int b )
	{
	b = bomba;
	int m, n;
	while (bomba<10)
			{
			m = randomico()%6;
			n = randomico()%6;
			if (m == numero[0][0] && n == numero[0][1])
				escolherPocicao(bomba);
			else
				analisarProximo(1, m, n, bomba);
			}
	}
void analisarProximo(int proximo, int m, int n, int b )
	{
	int pos = 0;
	if (m==numero[proximo][0] && n==numero[proximo][1])
		escolherPocicao(bomba);
	else
			{
			if (proximo == 9)
					{
					numero[pos][0] = m;
					numero[pos][1] = n;
					tabela[m][n] = 66;
					pos += 1;
					bomba++;
					}
			else
				analisarProximo(proximo+1, m, n, b );
			}
	if (bomba==10)
			{
			for (int j = 0; j<=5; j++)
				for (int k = 0; k<=5; k++)
						{
						if (tabela[j][k] == 66)
							;
						else
							analisarAdjacentes(j,k);
						}
			}
	}
void imprimeTabuleiro()
	{
	int line,k;
	for (line = 0; line <= 12; line++)
			{
			if (line%2 != 0)
					{
					for (k=0; k<=5; k++)
						cout<< "|" <<" "<<tabela[line/2][k]<<" ";
					cout<< "|" <<endl;
					}
			else
				cout<< "-------------------------"<< endl;
			}
	}
void analisarAdjacentes(int m, int n)
	{
	int r,s, adjacente[8][2], numerobomb = 48, position = 0;
	for (r=m-1; r<=m+1; r++)
		for (s=n-1; s<=n+1; s++)
			if (r >=0 && r <= 5 && s >= 0 && s <= 5)
					{
					adjacente[position][0]= r;
					adjacente[position][1]= s;
					if (r==m && s==n);
					else
							{
							if (tabela[r][s]==66)
								numerobomb++;
							position++;
							}
					}
	tabela[m][n] = char(numerobomb);
	}
int main()
	{
	int tamanhoTerminal[2];
	for(int i=0;i<2;i++){
	tamanhoTerminal[i]= readInt("Entre com valor para mudar o tamanhao do termianal ");
	}
	if(tamanhoTerminal[0]<25,tamanhoTerminal[1]<25)cout<<"Entrada Invalida"<<endl;
	else{
	mudaTamanhoTerminal(tamanhoTerminal[0],tamanhoTerminal[1]);
	escolherPocicao();
	imprimeTabuleiro();

	}
	}
