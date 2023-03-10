#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include<cmath>
#include <map>

using namespace std;
int main() 
{
	unsigned long long int M; //Antalet godisar jag har
	unsigned long long int N; //Antalet barn
	unsigned long long int antalonskade = 0; //Antalet totala godisar
	unsigned long long int value;
	multimap<unsigned long long int, unsigned long long int> mp;
	cin >> M >> N;
	
	for (unsigned long long int i=0; i < N; i++){
		cin >> value;
		//cout << "help";
		mp.insert(std::pair<unsigned long long int,unsigned long long int>(value,value));
		antalonskade = antalonskade + value;
		
	}
	
	//cout << "Antal onskade:" << antalonskade << "\n";
	//cout <<"M:"<< M << " N:" << N << "\n";
	unsigned long long int ilska = 0;
	// Ska räkna ut hur sura de är.
	unsigned long long int antalsaknas = antalonskade - M;
	unsigned long long int antalOver = antalsaknas%N;
	unsigned long long int antalperperson = antalsaknas/N;
	
	if (antalOver > 0){
		antalperperson = antalperperson +1;
	}
	
	for (unsigned long long int j=0; j<=antalperperson; j++){
		
			if ((j)*mp.count(j) > antalsaknas){
				antalsaknas = antalsaknas - (j-1)*mp.count(j);
				ilska = ilska + mp.count(j)*pow(j-1,2);
				//cout << "help"  << j << "\n";
				if (j==1){
					ilska = ilska + antalsaknas;
					antalOver=0;
				}
			}
			else{
				antalsaknas = antalsaknas - (j)*mp.count(j);
				ilska = ilska + mp.count(j)*pow(j,2);
				//cout << "help" << j << "\n";
			}

			if (mp.count(j) > 0)
			{
				N=N-mp.count(j);
			}
		
	}
	if (N > 0){
	antalperperson = antalsaknas/N;
	antalOver = antalsaknas%N;
	}
	//cout << N << "N \n";
	//cout << antalsaknas << "over \n";
	//cout << ilska << " ilska" <<" \n";
	//cout << antalperperson << "antalperperson \n";
	cout << N*pow(antalperperson,2) + antalOver*pow(antalperperson+1,2) - antalOver*pow(antalperperson,2) + ilska << "\n";
	//cout << mp.count(5) << "\n";
return 0;
}
