/** MASTERMIND (SENHA) **/
#include "biblaureano.h"

inline void Tabela();
inline void ganhouPerdeu(bool resultado);
inline void instrucoes();
inline void carregamento();
int main()
	{
	while (true)
			{
			///menu
			desligaCursor(true);
			noecho(true);

			mudaTamanhoTerminal(110,19);
			mudaCor255(16,16);
			limparTela();
			Imagem Menu(retornaConteudoArquivo("GuilhermeSolskiMenu.txt"),1,1);
			Menu.mudaCor(GREEN,GREEN),Menu.imprime();
			string opcoes[] = {"JOGAR","INSTRUCÕES","SAIR"};
			int opcao = mostraMenuV(42,10,opcoes,3,RED,GREEN);
			if (opcao == 2)
					{
					instrucoes();
					}
			if (opcao == 3)
					{
					limparTela();
					break;
					}
			limparTela(),carregamento();
			///ajustando a tela
			mudaTamanhoTerminal(72,36);
			mudaCor255(16,16);
			limparTela();
			///tabela
			Tabela();
			///sorteando as cores
			int senha[4],random = randomico(1,7);
			for (int  i = 0; i < 4; i++)
					{
					for (int j = 0; j < 4; j ++)
							{
							if(random == senha[j])
									{
									random = randomico(1,7);
									j = 0;
									}
							}
					senha[i] = random;
					random = randomico(1,8);
					}
			///gameplay
			int cores = 1;
			gotoXY(5,5);
			mudaCor255(cores,cores);
			cout<<"    ";
			vector<int> coresUsudas;
			char botao;
			int acertos = 0;
			for (int linha = 5; linha <= 33; linha+=3)
					{
					for(int col = 5; col < 40; col+=9)
							{
							botao = ';';
							while(botao != ' ')
									{
									///MudarCorJogador
									if(kbhit())
											{
											botao = getch();
											if(botao == K_UP)
													{
													cores++;
													if (cores > 8)
															{
															cores = 1;
															}
													mudaCor255(cores,cores);
													gotoXY(col,linha);
													cout << "    ";
													}
											if(botao == K_DOWN)
													{
													cores--;
													if (cores < 1)
															{
															cores = 8;
															}
													mudaCor255(cores,cores);
													gotoXY(col,linha);
													cout << "    ";
													}
											}
									}
							coresUsudas.push_back(cores);
							}
					///conferindo
					for(int i = 0; i < 4; i++)
							{
							if (coresUsudas[i] == senha[i])
									{
									gotoXY(41+(i*4),linha);
									mudaCor255(8,8);
									cout << " ";
									acertos++;
									}
							else
									{
									for(int j = 0; j < 4; j++)
											{
											if (coresUsudas[i] == senha[j])
													{
													gotoXY(41+(i*4),linha);
													mudaCor255(231,231);
													cout << " ";
													}
											}
									}
							}
					if (acertos == 4)
							{
							ganhouPerdeu(true);
							break;

							}
					acertos = 0;
					coresUsudas.clear();
					}
			if (acertos < 4)
					{
					ganhouPerdeu(false);

					}
			}

	}
inline void Tabela()
	{
	limparTela();
	Imagem sTabela( retornaConteudoArquivo("GuilhermeSolskiLinhas.txt"),1,1);
	sTabela.mudaCor(BLUE);
	sTabela.imprime();
	mudaCor255(231,16);
	gotoXY(19,3);
	cout << "----MASTERMIND----";
	for(int linha = 5; linha <= 33; linha+= 3)
			{
			mudaCor255(1,16);
			gotoXY(4,linha);
			cout << "[    ]   [    ]   [    ]   [    ]   {_} {_} {_} {_}";
			for(int color = 10; color < 40; color+= 9)
					{
					mudaCor(BLACK,BLACK);
					gotoXY(color,linha);
					cout << "---";
					}
			}
	}
inline void ganhouPerdeu(bool resultado)
	{
	limparTela();
	mudaTamanhoTerminal(90,25);
	mudaCor255(16,16);
	limparTela();
	mudaCor255(46,16);
	if(resultado == true)
			{
			cout << retornaConteudoArquivo("GuilhermeSolskiGanhou.txt");
			for(int i = 0; i ==0;)
					{
					if (kbhit()) i++;
					}
			}
	else
			{
			cout << retornaConteudoArquivo("GUilhermeSolskiGameOver.txt");
			for(int i = 0; i ==0;)
					{
					if (kbhit()) i++;
					}
			}
	}
inline void instrucoes()
	{
	limparTela();
	mudaTamanhoTerminal(70,17);
	mudaCor255(16,16);
	limparTela();
	mudaCor255(231,16);
	cout<<" _____________________________________________________________"
	    <<"\n|                     INSTRUCOES                              |"
	    <<"\n|controles;                                                   |"
	    <<"\n|setas(cima,baixo): altera a cor a ser jogada;                |"

	    <<"\n|espaço: seleciona a cor;                                     |"
	    <<"\n|     	                                                        |"
	    <<"\n|objetivo:                                                    |"
	    <<"\n|voce deve descobrir a combinação de cores em ate 10          |"
	    <<"\n|tentativas para isso voce usara como informação os pinos     |"
	    <<"\n|                                                             |"
	    <<"\n|                                                             |"
	    <<"\n|cores dos pinos:                                             |"
	    <<"\n|branco: cor certa no lugar errado;                           |"
	    <<"\n|preto: cor certa no lugar certo;                             |"
	    <<"\n|_____________________________________________________________|"
	    <<"\nPRRECIONE QUALQUER TECLA PARA JOGAR";
	for(int i = 0; i ==0;)
			{
			if (kbhit()) i++;
			}
	}
inline void carregamento()
	{
	limparTela();
	cout<<"Carregando Cores: ";
	for(int a=0; a<51; ++a)
			{
			gotoXY(a,9),cout<<"-";
			gotoXY(a,11),cout<<"-";
			gotoXY(51,10),cout<<"|";
			}
	for (int i = 0; i <51; ++i)
			{

			gotoXY(1,10);
			mudaCor(YELLOW,YELLOW),cout<<"*";
			for (int j = 0; j < i; ++j)
					{
					cout<<"*";
					espera(10);
					}
			}
	return;
	}

