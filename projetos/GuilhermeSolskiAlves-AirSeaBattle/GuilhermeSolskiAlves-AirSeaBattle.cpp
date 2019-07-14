#include "biblaureano.h"
///Introdução
inline void Introducao();
///Imprime o mapa, sempre usar gotoXY(1,1)para ele não decer
inline void ImprimeMapa();
///Retorna o Canhão, a imagem
class
	{
	public:
		vector<Imagem> Canhao = retornaImagens("GuilhermeSolski.txt");
		vector<Imagem> Canhao2 = retornaImagens("GuilhermeSolski.txt");
	} Imagens;

///Programa :)
int main()
	{
	///Inicio do Game
	Introducao();
	espera(1000),limparTela();
	///Busca imagens dos inimigos
	Imagem Barco(retornaConteudoArquivo("Barco.txt"));
	Imagem Sapo(retornaConteudoArquivo("Frog.txt"));
	Imagem Morcego(retornaConteudoArquivo("Morcego.txt"));
	Imagem Rosto (retornaConteudoArquivo("Rosto.txt"));
	vector<Imagem> Heli=retornaImagens("heli.txt");
	vector<Imagem> Tank = retornaImagens("tank.txt");
	vector<Imagem>Cavalo= retornaImagens("CavaloMarinho.txt");
	vector<Imagem>Peixe = retornaImagens("Peixe.txt");
	///Busca Imagem gerais
	Imagem ImagemTiro(retornaConteudoArquivo("tiro.txt")),ImagemTiro2(retornaConteudoArquivo("tiro.txt"));
	Imagem Menu(retornaConteudoArquivo("Menu.txt"));
	vector<Imagem>TituloMenu=retornaImagens("TituloMenu.txt");
	///Variaves numericas gerais
	int VetorDeImagem=0, X=1,TiroX=X,TiroY=23,pontos1=0,VetorDeImagem2=0,X2=95,TiroX2=X2,TiroY2=23,pontos2=0,Barra=77,opcao,opcao2;
	///Variavel numericas dos inimigos
	int HeliY=randomico(1,8),HeliX,HeliSorTEIO=randomico(1,4),TankY=randomico(10,20),TankX,TankSorteio=randomico(1,4);
	int BarcoY= randomico(10,17), BarcoX, BarcoSorteio=randomico(1,4),RostoY = randomico(1,15),RostoX,RostoSorteio= randomico(1,4);
	int CavaloMarinhoY= 10, CavaloMarinhoX,CavaloMarinhoSorteio=randomico(1,4);
	int PeixeY=randomico(1,20), PeixeX, PeixeSorteio=randomico(1,4),MorcegoY=randomico(10,15),MorcegoX,MorcegoSorteio=randomico(1,4);
	int SapoY=randomico(1,5), SapoX,SapoSorteio= randomico(1.4);
	int HeliPocicao=HeliSorTEIO%2, TankPocicao= TankSorteio%2, CavaloPocicao= CavaloMarinhoSorteio%2;
	///Para verificar a tecla
	char Teclado;
	///Variveis bool
	bool Tiro=true,HeliEsquerda,Tiro2,QuantidadeDeInimigos;
	///Muda as cores dos personagens
	for(int i=0; i<2; i++)
			{
			Heli[i].mudaCor(BLACK);
			Barco.mudaCor(RED);
			Tank[i].mudaCor(GREEN);
			}
	for(int i=0; i<3; i++)
			{
			Imagens.Canhao[i].mudaCor(YELLOW,YELLOW);
			Imagens.Canhao2[i].mudaCor(RED,RED);
			}
	///Menu Inicial
	limparTela(),mudaTamanhoTerminal(120,20);
	Tank[0].imprime(1,18),Tank[1].imprime(107,18),Heli[2].imprime(8,10),Heli[2].imprime(100,10),Heli[0].imprime(95,2),Heli[1].imprime(20,2),TituloMenu[0].imprime(25,4);
	string opcoes []= { "Jogar" , "Ajuda" , "Exit" };
	opcao = mostraMenuH (49,15,opcoes,3,WHITE,BLUE);
	///Ajuda
	if(opcao==2)
			{
			///Limpa Coisas Anteriores,e muda o tamanho do terminal
			desligaCursor(true),noecho(true),mudaTamanhoTerminal(88,35);
			///Muda a cor e Imprime a Ajuda
			Menu.mudaCor(BLUE);
			limparTela();
			Menu.imprime(1,1);
			///Vai para o jogo
			while(true)
					{
					if (kbhit())
							{
							espera(50),opcao = 1;
							break;
							}
					}
			}
	///Jogo
	if(opcao==1)
			{
			///Menu de dificuldade
			limparTela(),mudaTamanhoTerminal(120,20);
			Tank[0].imprime(1,18),Tank[1].imprime(107,18),Heli[2].imprime(8,10),Heli[2].imprime(100,10),Heli[0].imprime(95,2),Heli[1].imprime(20,2),TituloMenu[0].imprime(25,4);
			string  opcoes2 [] = {"Facil" , "Hard"};
			opcao2 = mostraMenuH (49,15,opcoes2,2,WHITE,BLUE);
			if(opcao2==1)
					{
					///maximo 5 inimigos na tela
					QuantidadeDeInimigos=true;
					}
			if(opcao2==2)
					{
					///maximo 10 inimigos na tela
					QuantidadeDeInimigos=false;
					}
			///Configurações iniciais
			desligaCursor(true);
			noecho(true);
			mudaTamanhoTerminal(100,30);
			limparTela();
			///Imprime Coisas Iniciais
			Imagens.Canhao[VetorDeImagem].imprime(1,24);
			Imagens.Canhao2[VetorDeImagem2].imprime(94,24);
			ImprimeMapa();
			while(true)
					{
					///Verifica se inimigos não vão imprimir na mesma linha
					if(BarcoY==TankY)TankY=randomico(10,20);
					if(BarcoY==HeliY)BarcoY=randomico(10,17);
					if(CavaloMarinhoSorteio==BarcoSorteio)BarcoSorteio=randomico(1,4);
					if(CavaloMarinhoSorteio==TankSorteio)CavaloMarinhoSorteio=randomico(1,4);
					espera(50);
					///Mostras os Pontos
					gotoXY(50,30),cout<<"|";
					gotoXY(22,30),cout<<pontos1<<"|";
					gotoXY(pontos1+24,30),mudaCor255(142,142),cout<<"*";
					gotoXY(77,30),mudaCor255(98),cout<<"|"<<pontos2;
					gotoXY(Barra-1,30),mudaCor255(98,98),cout<<"*";
					///acaba o jogo
					if(pontos1==25||pontos2==25)
							{
							limparTela();
							mudaTamanhoTerminal(120,20);
							mudaCor255(0);
							opcao=3;
							break;
							}
					if(QuantidadeDeInimigos==true) ///Movimenta Inimigos
							{
							///Heli
							if(HeliSorTEIO%2==0)
									{
									HeliX=0;
									}
							if(HeliSorTEIO%2!=1)
									{
									HeliX=94;
									}
							///Tank
							if(TankSorteio%2==0)
									{
									TankX=0;
									}
							if(TankSorteio%2!=0)
									{
									TankX=86;
									}
							///barco
							if(BarcoSorteio%2==0)
									{
									BarcoX=0;
									}
							if(BarcoSorteio%2!=0)
									{
									BarcoX=94;
									}
							///Rosto
							if(RostoSorteio%2==0)
									{
									RostoX=0;
									}
							if(RostoSorteio%2!=0)
									{
									RostoX=92;
									}
							///CavaloMarinho
							if(CavaloMarinhoSorteio%2==0)
									{
									CavaloMarinhoX=0;
									}
							if(CavaloMarinhoSorteio%2!=0)
									{
									CavaloMarinhoX=94;
									}
							///Imprime todo os Inimigos
							Tank[TankPocicao].imprime(TankX,TankY),Tank[TankPocicao].limpa(),TankX--;
							Heli[HeliPocicao].imprime(HeliX,HeliY),Heli[HeliPocicao].limpa(),HeliX--,
							     Rosto.imprime(RostoX,RostoY),Rosto.limpa(),RostoX--;
							Barco.imprime(BarcoX,BarcoY),Barco.limpa(),BarcoX--;
							Cavalo[CavaloPocicao].imprime(CavaloMarinhoX,CavaloMarinhoY),Cavalo[CavaloPocicao].limpa(),CavaloMarinhoX--;

							espera(50);
							Barco.imprime(BarcoX,BarcoY);
							Rosto.imprime(RostoX,RostoY);
							Cavalo[CavaloPocicao].imprime(CavaloMarinhoX,CavaloMarinhoY);
							Heli[HeliPocicao].imprime(HeliX,HeliY);
							Tank[TankPocicao].imprime(TankX,TankY);
							}
					if(QuantidadeDeInimigos==false)
							{

							///Heli
							if(HeliSorTEIO%2==0)
									{
									HeliX=94;
									}
							if(HeliSorTEIO%2!=1)
									{
									HeliX=94;
									}
							///Tank
							if(TankSorteio%2==0)
									{
									TankX=86;
									}
							if(TankSorteio%2!=0)
									{
									TankX=86;
									}
							///barco
							if(BarcoSorteio%2==0)
									{
									BarcoX=94;
									}
							if(BarcoSorteio%2!=0)
									{
									BarcoX=94;
									}
							///Rosto
							if(RostoSorteio%2==0)
									{
									RostoX=0;
									}
							if(RostoSorteio%2!=0)
									{
									RostoX=92;
									}
							///CavaloMarinho
							if(CavaloMarinhoSorteio%2==0)
									{
									CavaloMarinhoX=94;
									}
							if(CavaloMarinhoSorteio%2!=0)
									{
									CavaloMarinhoX=94;
									}
							if(SapoSorteio%2==0)
									{
									SapoX=0;
									}
							if(SapoSorteio%2!=0)
									{
									SapoX=94;
									}
							///Imprime todo os Inimigos
							Tank[TankPocicao].imprime(TankX,TankY),Tank[TankPocicao].limpa(),TankX--;
							Heli[HeliPocicao].imprime(HeliX,HeliY),Heli[HeliPocicao].limpa(),HeliX--,
							Rosto.imprime(RostoX,RostoY),Rosto.limpa(),RostoX--;
							Barco.imprime(BarcoX,BarcoY),Barco.limpa(),BarcoX--;
							Cavalo[CavaloPocicao].imprime(CavaloMarinhoX,CavaloMarinhoY),Cavalo[CavaloPocicao].limpa(),CavaloMarinhoX--;
							Sapo.imprime(SapoX,SapoY), Sapo.limpa(), SapoX--;

							espera(50);
							Barco.imprime(BarcoX,BarcoY);
							Rosto.imprime(RostoX,RostoY);
							Cavalo[CavaloPocicao].imprime(CavaloMarinhoX,CavaloMarinhoY);
							Heli[HeliPocicao].imprime(HeliX,HeliY);
							Tank[TankPocicao].imprime(TankX,TankY);
							Sapo.imprime(SapoX,SapoY);
							}
					///Movimenta os canhão,atraves de teclas
					if(kbhit())
							{
							Teclado=getch();
							Imagens.Canhao[VetorDeImagem].limpa();
							Imagens.Canhao2[VetorDeImagem2].limpa();
							if(Teclado=='s'||Teclado=='S')VetorDeImagem--;
							if(Teclado=='w'||Teclado=='W')VetorDeImagem++;
							if(Teclado=='a'||Teclado=='A')X--;
							if(Teclado=='d'||Teclado=='D')X++;
							if(Tiro==true)
									{
									if(Teclado=='x'||Teclado=='X'||Teclado==' ')TiroX=X,Tiro=false;
									}
							Imagens.Canhao[VetorDeImagem].imprime(X,24);
							if(Teclado=='2')VetorDeImagem2--;
							if(Teclado=='8')VetorDeImagem2++;
							if(Teclado=='4')X2--;
							if(Teclado=='6')X2++;
							if(Tiro2==true)
									{
									if(Teclado=='0'||Teclado==',')TiroX2=X2,Tiro2=false;
									}
							Imagens.Canhao2[VetorDeImagem2].imprime(X2,24);
							}
					///Verifica a Pocição do vector de imagem
					if(VetorDeImagem>=3)VetorDeImagem=2;
					if(VetorDeImagem==-1)VetorDeImagem=0;
					if(VetorDeImagem2>=3)VetorDeImagem2=2;
					if(VetorDeImagem2==-1)VetorDeImagem2=0;
					///Move o tiro
					if(Tiro==false||Tiro!=true)
							{
							if(VetorDeImagem==0)espera(50),ImagemTiro.limpa(),TiroY--,ImagemTiro.imprime(TiroX+3,TiroY);
							if(VetorDeImagem==1)espera(50),ImagemTiro.limpa(),TiroY--,TiroX++,ImagemTiro.imprime(TiroX+5,TiroY);
							if(VetorDeImagem==2)espera(50),ImagemTiro.limpa(),TiroY--,TiroX--,ImagemTiro.imprime(TiroX,TiroY);
							}
					if(Tiro2==false||Tiro2!=true)
							{
							if(VetorDeImagem2==0)espera(50),ImagemTiro2.limpa(),TiroY2--,ImagemTiro2.imprime(TiroX2+3,TiroY2);
							if(VetorDeImagem2==1)espera(50),ImagemTiro2.limpa(),TiroY2--,TiroX2++,ImagemTiro2.imprime(TiroX2+5,TiroY2);
							if(VetorDeImagem2==2)espera(50),ImagemTiro2.limpa(),TiroY2--,TiroX2--,ImagemTiro2.imprime(TiroX2,TiroY2);
							}
					///Verifica se o tirou passou da tela
					if(TiroY==1)Tiro=true,ImagemTiro.limpa(),gotoXY(1,1),ImprimeMapa(),TiroX = X,TiroY = 23;
					if(TiroY2==1)Tiro2=true,ImagemTiro2.limpa(),gotoXY(1,1),ImprimeMapa(),TiroX2= X,TiroY2 = 23;

					///Verifica se os Inimigos sairam da Tela
					if(HeliX>95)HeliX=1,ImprimeMapa();
					if(HeliX<0)HeliX=94,ImprimeMapa();
					if(BarcoX>95)BarcoX=1,ImprimeMapa();
					if(BarcoX<0)BarcoX=94,ImprimeMapa();
					if(TankX>95)TankX=1,ImprimeMapa();
					if(TankX<0)TankX=94,ImprimeMapa();

					///Verifica se o canhão vai sair da tela, e se eles colidiram
					if(X==1)X++;
					if(X==94)X--;
					if(X2==1)X2++;
					if(X2==94)X2--;
					if(X2+7==X||X+7==X2)X2++,X--;
					///Colisão do tiro do canhao com inimigos
					if(HeliSorTEIO%2==0)
							{
							for(int i=0; i<6; i++)
									{
									for(int a=0; a<2; a++)
											{
											if(TiroX==HeliX+i && TiroY==HeliY+a)gotoXY(1,1),ImprimeMapa(),Tiro=true,TiroX = X,TiroY = 23,ImagemTiro.limpa(), pontos1++;
											if(TiroX2==HeliX+i && TiroY2==HeliY+a)gotoXY(1,1),ImprimeMapa(),Tiro2=true,TiroX2 = X2,TiroY2=23,ImagemTiro2.limpa(),Barra--, pontos2++;
											}
									}
							}
					if(HeliSorTEIO%2!=0)
							{
							for(int i=0; i<6; i++)
									{
									for(int a=0; a<2; a++)
											{
											if(TiroX==HeliX-i && TiroY==HeliY-a)gotoXY(1,1),ImprimeMapa(),Tiro=true,TiroX = X,TiroY = 23,ImagemTiro.limpa(), pontos1++;
											if(TiroX2==HeliX-i && TiroY2==HeliY-a)gotoXY(1,1),ImprimeMapa(),Tiro2=true,TiroX2 = X2,TiroY2=23,ImagemTiro2.limpa(),Barra--,pontos2++;
											}
									}
							}
					if(TankSorteio%2==0||TankSorteio%2!=0)
							{
							for(int i=0; i<11; i++)
									{
									for(int a=0; a<3; a++)
											{
											if(TiroX==TankX+i && TiroY==TankY+a)gotoXY(1,1),ImprimeMapa(),Tiro=true,TiroX = X,TiroY = 23,ImagemTiro.limpa(), pontos1++;
											if(TiroX2==TankX+i && TiroY2==TankY+a)gotoXY(1,1),ImprimeMapa(),Tiro2=true,TiroX2 = X2,TiroY2=23,ImagemTiro2.limpa(),Barra--,pontos2++;

											}
									}
							}
					if(BarcoSorteio%2==0)
							{
							for(int i=0; i<6; i++)
									{
									for(int a=0; a<6; a++)
											{
											if(TiroX==BarcoX+i && TiroY==BarcoY+a)gotoXY(1,1),ImprimeMapa(),Tiro=true,TiroX = X,TiroY = 23,ImagemTiro.limpa(), pontos1++;
											if(TiroX2==BarcoX+i && TiroY2==BarcoY+a)gotoXY(1,1),ImprimeMapa(),Tiro2=true,TiroX2 = X2,TiroY2=23,ImagemTiro2.limpa(),Barra--,pontos2++;
											}
									}
							}
					if(BarcoSorteio%2!=0)
							{
							for(int i=0; i<6; i++)
									{
									for(int a=0; a<6; a++)
											{
											if(TiroX==BarcoX-i && TiroY==BarcoY+a)gotoXY(1,1),ImprimeMapa(),Tiro=true,TiroX = X,TiroY = 23,ImagemTiro.limpa(), pontos1++;
											if(TiroX2==BarcoX-i && TiroY2==BarcoY+a)gotoXY(1,1),ImprimeMapa(),Tiro2=true,TiroX2 = X2,TiroY2=23,ImagemTiro2.limpa(),Barra--,pontos2++;
											}
									}
							}
					}
			}
	///Exit
	if(opcao==3)
			{
			limparTela();
			Tank[1].imprime(1,18),Tank[0].imprime(107,18),Heli[2].imprime(8,10),Heli[2].imprime(100,10);
			Heli[1].imprime(95,2),Heli[0].imprime(20,2),TituloMenu[1].imprime(25,4);
			espera(2000);
			limparTela();
			mudaTamanhoTerminal(50,20);
			gotoXY(15,8),cout<<"GAME OVER"<<endl<<endl;
			return 0;
			}
	}
///Imprime o mapa, sempre usar gotoXY(1,1)para ele não decer
inline void ImprimeMapa()
	{
	Imagem Chao(retornaConteudoArquivo("GuilhermeSolskiChao.txt"));
	for(int i=0; i<300; i++)mudaCor255(18,18),cout<<"#";
	for(int i=300; i<600; i++)mudaCor255(19,19),cout<<"#";
	for(int i=600; i<900; i++)mudaCor255(20,20),cout<<"#";
	for(int i=900; i<1200; i++)mudaCor255(21,21),cout<<"#";
	for(int i=1200; i<1500; i++)mudaCor255(25,25),cout<<"#";
	for(int i=1500; i<1800; i++)mudaCor255(26,26),cout<<"#";
	for(int i=1800; i<2300; i++)mudaCor255(27,27),cout<<"#";
	Chao.mudaCor(BLACK,BLACK),Chao.imprime(1,29);
	}
///Introção
inline void Introducao()
	{
	desligaCursor(true),noecho(true),mudaTamanhoTerminal(120,20);
	vector<Imagem> Introducao = retornaImagens("Titulo.txt");
	Introducao[0].mudaCor(GREEN),Introducao[2].mudaCor(BLUE);
	Introducao[0].imprime(1,1);
	espera(1000);
	Introducao[0].limpa();
	Introducao[1].imprime(2,2);
	espera(1000);
	Introducao[1].limpa();
	Introducao[2].imprime(3,3);
	}
