#include "widok.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
    widok S;
 	S.statki();
    // tworzenie planszy A
    S.plansza_tworzenie(0);// widzi swoja gracz A
    S.plansza_tworzenie(1);  // ta widzi gracz B
    S.uzupelnianie(0);
    S.plansza(0);
    Sleep(2000);
    system("cls");
    cout << "Oddaj plansze przeciwnikowi\n";
    Sleep(5000);
    cout << "\n";
    system("cls");
    
    // tworzenie planszy B
    S.plansza_tworzenie(2); // widzi swoja gracz B
    S.plansza_tworzenie(3); // ta widzi gracz A
    S.uzupelnianie(2);		
    S.plansza(2);
    
    S.plansza(0);
    
    
    // gra dopoki SA lub SB beda rowne 0
    while(S.SA != 0 || S.SB != 0)
    {
    	S.SA--;
    	S.SB -= 2;
	}


    return 0;
}

