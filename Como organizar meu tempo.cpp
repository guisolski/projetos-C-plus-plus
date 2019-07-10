#include "biblaureano.h"
int main()
{
int tempo = readInt("Quanto tempo voce tem para estudar?(em minutos) ");
int disciplinas = readInt("Qual o numero de disciplinas que voce tem? ");
int estudo = (tempo / (disciplinas + 1))  ;
int descanso = (tempo / disciplinas) ;
cout << "o tempo calculado para cada disciplina é de " << estudo << " minutos." << endl;
cout << "voce tem tempo para descanso de " << descanso << endl;
}



