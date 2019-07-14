#include "biblaureano.h"
class Elevador
	{
	private :
		vector<int>QuantidadePessoa;
		vector<int>Andar;
	public:
		int Pessoa= 0;
		int AndarAtual;///Começa no terreo =0.
		int TotalDeAndares=30; ///Excluindo o terrio.
		int TotalDePessoas;
		int _capacidade=10;
		void MetodoConstrutor()///Passa todos o Valores do Elevador, Define Todos os Valores
			{
			AndarAtual=0;
			TotalDeAndares=30;
			_capacidade=10;
			}
		void Entra()///Coloca Mais pessoas
			{
			if(QuantidadePessoa.size()<= _capacidade)
					{
					QuantidadePessoa.push_back(Pessoa);
					}
			if(QuantidadePessoa.size()>10)
					{
					QuantidadePessoa.erase(QuantidadePessoa.begin());
					cout<<"Não tem mais espaço no elevador"<<endl;
					}
			}
		void Sai()
			{
			if(QuantidadePessoa.size()>0)
					{
					QuantidadePessoa.erase(QuantidadePessoa.begin());
					}
			if(QuantidadePessoa.size()==0)
					{
					cout<<"Não tem pessoas suficiente para tirar"<<endl;
					}
			}
		void Sobe()
			{
			if(Andar.size()< TotalDeAndares)
					{
					Andar.push_back(AndarAtual);
					}
			else
					{
					cout<<"Já estamos no ultimo andar"<<endl;
					}
			}
		void Desce()
			{
			if(Andar.size()>0)
					{
					Andar.erase(Andar.begin());
					}
			else
					{
					cout<<"Já estamos terrio"<<endl;
					}
			}
		void TodosOsDados()
			{
			cout<<"Andar atual: "<<Andar.size()<<endl;
			cout<<"Quatidades de pessoas no elevedador: "<<QuantidadePessoa.size()<<endl;
			cout<<"Seu elevador ainda comporta: "<<_capacidade - QuantidadePessoa.size()<<endl;
			}
	};
int main()
	{
	Elevador A;
	A.Sobe(),A.Entra();
	A.Desce(),A.Entra();
	A.Sobe(),A.Sai(),A.Sai();
	A.Desce(),A.Entra();
	for(int i; i<6; i++)
			{
			A.Sobe();
			}
	A.Sai();
	for(int i =0; i<10; i++)
			{
			A.Entra();
			}
	for(int i; i<6; i++)
			{
			A.Desce();
			}
				for(int i =0; i<10; i++)
			{
			A.Sai();
			}
	A.TodosOsDados();
	}
