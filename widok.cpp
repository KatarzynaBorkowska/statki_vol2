#include "widok.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
char tab[4][30][30];

void widok::statki(){// wybieranie ilosci statkow
	cout << "Ile statkow 2 masztowych? ";
	cin >> dwa;
	cout << "Ile statkow 3 masztowych? ";
	cin >> trzy;
	cout << "Ile statkow 4 masztowych? ";
	cin >> cztery;
	cout << "Ile statkow 5 masztowych? ";
	cin >> piec;
}


void widok::statki_k(int n, int l,char s) // wybieranie miesc dla statkow
{
	system("cls");
   	plansza(n);
	int x,y,i;
	char z;
	cout << "Pierwsze wspolczedne statku o " << l << " masztach wiersz X kolumna: ";
		cin >> x >> y;
		
		if(x < 1 || x > 30 || y < 1 || y > 30){
			cout << "Nie ma takich wymiarow\n";
			Sleep(2000);
			statki_k(n,l,s);
			return ;
		}
		cout << "L - na lewo,\tP - na prawo,\tG - w gore,\tD - w dol\n";
		cin >> z;
	
		if(toupper(z) != 'L' && toupper(z) != 'P' && toupper(z) != 'G' && toupper(z) != 'D')
		{
			cout << "Nie ma takiego kierunku\n";
			Sleep(2000);
			statki_k(n,l,s);
			return ;
		}
	
	
	if((x - l < 0 && toupper(z) == 'G')|| (x + l > 31 && toupper(z) == 'D') || (y - l < 0 && toupper(z) == 'L') || (y + l > 31 && toupper(z) == 'P'))
	{
		cout << "Statki sie nie zmieszcza\n";
		Sleep(2000);
statki_k(n,l,s);		return ;
	}
	
	x--;
	y--;
	if(tab[n][x][y] != '*')
	{
		cout << "Cos juz tam jest\n";
		Sleep(2000);
statki_k(n,l,s);		return ;
	}
		
	// Czy jest tam juz jakis statek
	for(i = 1;i < l;i++)
	{
		if(tab[n][x-i][y] != '*' || tab[n][x+i][y] != '*' || tab[n][x][y+i] != '*' || tab[n][x][y-i] != '*')
		{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
statki_k(n,l,s);			return ;
		}
	}
	
	if(tab[n][x-1][y+1] != '*' || tab[n][x+1][y-1] != '*' || tab[n][x+1][y+1] != '*' || tab[n][x-1][y-1] != '*')
	{
			cout << "Cos juz tam jest\n";
			Sleep(2000);
statki_k(n,l,s);			return ;
	}
	
	// sprawdzam obwod
	
	if(toupper(z) == 'L')
	{
		for(i = -1;i <= l;i++)
		{
			if(x -1 != -1){
			
			if(tab[n][x - 1][y-i] != '*' || tab[n][x + 1][y-i] != '*' )
			{
			statki_l(n,l,s);
			return ;
			}}
		}
		if(tab[n][x][y-l] != '*' || tab[n][x][y+1] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'P')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x - 1][y+i] != '*' || tab[n][x + 1][y+i] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		
			if(tab[n][x][y+l] != '*' || (tab[n][x][y-1] != '*' && (y-1 != -1)))
		{
			statki_l(n,l,s);
			return ;
		}
		
		
	}
	
	if(toupper(z) == 'D')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x+i][y-1] != '*' || tab[n][x +i][y+1] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		if(tab[n][x+l][y] != '*' || tab[n][x-1][y] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'G')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x-i][y-1] != '*' || tab[n][x -i][y+1] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		if(tab[n][x+1][y] != '*' || tab[n][x-l][y] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}

	
	tab[n][x][y] = s;
	for(i = 1;i < l;i++)
	{
		if(toupper(z) == 'G')
			tab[n][x-i][y] = s;
		if(toupper(z) == 'D')
			tab[n][x+i][y] = s;
		if(toupper(z) == 'P')
			tab[n][x][y+i] = s;
		if(toupper(z) == 'L')
			tab[n][x][y-i] = s;
	}
}

void widok::statki_l(int n,int l, char s){ //losowanie miesc dla statkow
	int i;
	
	string a = "";
	a += s;
		
		char liczba[] = {'L','P','G','D'};
		
		x = (rand()%30) + 1;
		
		y = (rand()%30) + 1;
		i = (rand()%3) + 0;
		z = liczba[i];
	
	if((x - l < 0 && toupper(z) == 'G')|| (x + l > 31 && toupper(z) == 'D') || (y - l < 0 && toupper(z) == 'L') || (y + l > 31 && toupper(z) == 'P'))
	{
		statki_l(n,l,s);
		return ;
	}
	
	x--;
	y--;
	if(tab[n][x][y] != '*')
	{
		statki_l(n,l,s);
		return ;
	}
		
	// Czy jest tam juz jakis statek
	for(i = 1;i < l;i++)
	{
		if(tab[n][x-i][y] != '*' || tab[n][x+i][y] != '*' || tab[n][x][y+i] != '*' || tab[n][x][y-i] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(tab[n][x-1][y+1] != '*' || tab[n][x+1][y-1] != '*' || tab[n][x+1][y+1] != '*' || tab[n][x-1][y-1] != '*')
	{
			statki_l(n,l,s);
			return ;
	}
	
	// sprawdzam obwod
	
	if(toupper(z) == 'L')
	{
		for(i = -1;i <= l;i++)
		{
			if(x -1 != -1){
			
			if(tab[n][x - 1][y-i] != '*' || tab[n][x + 1][y-i] != '*' )
			{
			statki_l(n,l,s);
			return ;
			}}
		}
		if(tab[n][x][y-l] != '*' || tab[n][x][y+1] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'P')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x - 1][y+i] != '*' || tab[n][x + 1][y+i] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		
			if(tab[n][x][y+l] != '*' || (tab[n][x][y-1] != '*' && (y-1 != -1)))
		{
			statki_l(n,l,s);
			return ;
		}
		
		
	}
	
	if(toupper(z) == 'D')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x+i][y-1] != '*' || tab[n][x +i][y+1] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		if(tab[n][x+l][y] != '*' || tab[n][x-1][y] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}
	
	if(toupper(z) == 'G')
	{
		for(i = -1;i <= l;i++)
		{
			if(tab[n][x-i][y-1] != '*' || tab[n][x -i][y+1] != '*')
			{
			statki_l(n,l,s);
			return ;
			}
		}
		if(tab[n][x+1][y] != '*' || tab[n][x-l][y] != '*')
		{
			statki_l(n,l,s);
			return ;
		}
	}

	
	tab[n][x][y] = s;
	for(i = 1;i < l;i++)
	{
		if(toupper(z) == 'G')
			tab[n][x-i][y] = s;
		if(toupper(z) == 'D')
			tab[n][x+i][y] = s;
		if(toupper(z) == 'P')
			tab[n][x][y+i] = s;
		if(toupper(z) == 'L')
			tab[n][x][y-i] = s;
	}
	//plansza(n);
}


void widok::uzupelnianie(int n) // statkami
{
	int i,w;
	
	cout << "Jezeli chcesz wprowadzic dane z klawiatury podaj 1,\njezeli chcesz je wylosowac podaj 2\n";
	cin >> w;

	for(i = 0;i < dwa;i++)
	{
		if(w == 1)
			statki_k(n,2,'2');
		else
			statki_l(n,2,'2');	
	}
	for(i = 0;i < trzy;i++)
	{
		if(w == 1)
			statki_k(n,3,'3');
		else
			statki_l(n,3,'3');		
	}
	for(i = 0;i < cztery;i++)
	{
		if(w == 1)
			statki_k(n,4,'4');
		else
			statki_l(n,4,'4');			
	}
	for(i = 0;i < piec;i++)
	{
		if(w == 1)
			statki_k(n,5,'5');
		else
			statki_l(n,5,'5');		
	}
	
   	plansza(n);
   	Sleep(5000);
}


void widok::plansza(int n)// wysruk planszy
{
	int i, j;
            
    if(n == 0)
    	cout << "A";
    else
    	cout << "B";
    cout << "  ";
    for (i = 1;i < 31;i++) {
        cout << i << " ";
        if (i < 10)
            cout << " ";
    }
    cout << "\n";

    for (i = 0;i < 30;i++)
    {
        cout << i + 1 << " ";
        if (i < 9)
            cout << " ";
        for (j = 0;j < 30;j++)
            cout << tab[n][i][j] << "  ";
        cout << endl;
    }
    
}

void widok::plansza_tworzenie(int n)
{
    int i, j;
    for (i = 0;i < 30;i++)
        for (j = 0;j < 30;j++)
            tab[n][i][j] =  '*';
   
}

