#ifndef WIDOK_H
#define WIDOK_H
#include <string>

class widok
{
	public:
	int dwa = 0,trzy = 0,cztery = 0,piec = 0; // statki
	int SA = dwa + trzy + cztery + piec;
	int SB = SA;
	int x,y;
	char z;
	
	void plansza(int);
	void plansza_tworzenie(int);
	void uzupelnianie(int);
	void statki();
	void statki_k(int,int,char);
	void statki_l(int,int,char);
};

#endif

