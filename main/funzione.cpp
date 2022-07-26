#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const float pi=3.1415926;

float coordinata(float a, float b,int tipo, float esponente);
float angolo(int x, float y);
bool discontinuita(float esp);

float coordinata(float a, float b,int tipo,float esponente){

	float y;

	switch(tipo){

		case 1: 

			y = a+b;

			return y;
		break;

		case 2: 
			if(esponente<0){
				esponente = esponente * -1;
				y = (1/(pow(a,esponente)))+b;
				return y;
			}
			else{
				y = a+b;

				return y;
			}

			

			
		break;
	}

	return y;

}

float angolo(int x,float y){
	float angGradi;
	angGradi = (atan(y/x))*180/pi;

	return angGradi;
}

bool discontinuita(float esp){
	if(esp <= -1){
		cout<<"La funzione ha un punto di discontinuità ad:\n x=0\n";
		return true;
	}

	else return false;
	
}

int main(){

	/*  1. Inserire la funzione di primo grado (retta) 
		2. Passa per l'origine? 
		3. Possibili punti di discontinuità
		4. Trovare 2 punti dove passa la retta 
		5. Angolo che forma la retta	*/

	bool check = true;
	int tipologia;
	string strA, strC, strB, strTipologia, strEsponente;
	float a,b,c,esponente;


	cout<<"Inserisci la tipologia di funzione:\n 1. Retta\n 2. Primo grado\n 3. Secondo grado\n 4. Irrazionali"<<"\n";
	while(check){
		try{
			cin>>strTipologia;
			tipologia = stoi(strTipologia);
			if(tipologia<1||tipologia>4){
				cout<<"Valore inserito non riconosciuto\n";
			}
			else check= false;
			
		}
		catch(invalid_argument e){
			cout<<"Valore inserito non riconosciuto\n";
		}
		
		
	}

	check = true;
	


	switch(tipologia){

		case 1:
			while(check){
				try{
					cout<<"Inserisci M"<<"\n";
					cin>>strA;
					cout<<"Inserisci Q"<<"\n";
					cin>>strC;

					a = stoi(strA);
					c = stoi(strC);

					check = false;	
				}
				
				catch(invalid_argument e){
					cout<<"Formato non valido"<<"\n";
					check = true;

				}

			}	
			if(c>0){
				cout<<"y = "<<a<<"x+"<<c<<"\n";
			}
			else cout<<"y = "<<a<<"x"<<c<<"\n";
			
			
			if(a==0)
			 	cout<<"E' una retta orizzontale con y="<<c<<"\n";
			if(c==0){

				cout<<"La funzione passa per l'origine"<<"\n";
			}


			cout<<"La retta ha coordinate A(0,"<<coordinata(0,c,tipologia,1)<<")"<<" e B(1,"<<coordinata(a,c,tipologia,1)<<")"<<"\n";
			cout<<"La retta forma un angolo di "<<angolo(1,coordinata(a,c,tipologia,1))<<"° rispetto all'origine"<<"\n";

		break;

		case 2:	
			while(check){
				try{
					cout<<"Inserisci il valore di A\n";
					cin>>strA;
					a = stoi(strA);

					cout<<"Inserisci l'esponente di A\n";
					cin>>strEsponente;
					esponente = stoi(strEsponente);

					while(esponente>1||esponente<-1){
						cout<<"La funzione deve essere di primo grado!\n";
						cin>>strEsponente;
						esponente = stoi(strEsponente);
						
					}

					cout<<"Inserisci il valore di B\n";
					cin>>strB;
					b = stoi(strB);


					check = false;
				}
				catch(invalid_argument e){
					cout<<"Valore non riconosciuto\n";
				}
			}

			if(esponente>0){
				if(b>0){
					cout<<"y = "<<a<<"x+"<<b<<"\n";
				
				}
				else if(b==0){
					cout<<"y = "<<a<<"x\n";
				}
				else cout<<"y = "<<a<<"x"<<b<<"\n";

		
			}
			else{
				if(b>0){
					cout<<"y = (1/"<<a<<"x)+"<<b<<"\n";

				}
				else if(b==0){
					cout<<"y = 1/"<<a<<"x\n";
				}
				else cout<<"y = (1/"<<a<<"x)"<<b<<"\n";
			}

			

			if(discontinuita(esponente) == false){
				cout<<"La funzione ha coordinate A(0,"<<coordinata(0,b,tipologia,esponente)<<")"<<" e B(2,"<<coordinata(a,b,tipologia,esponente)<<")\n";
			}
			else{
				cout<<"La funzione ha coordinate A(1,"<<coordinata(a,b,tipologia,esponente)<<")"<<" e B(2,"<<coordinata(2*a,b,tipologia,esponente)<<")\n";
			}


			break;


			


	}


	

	return 0;



}