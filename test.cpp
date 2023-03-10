#include <iomanip>
#include <list>
#include<cmath>
#include<iostream>
#include <algorithm>

using namespace std;
int main() 
{
	unsigned long long int M; //Antalet godisar jag har
	unsigned long long int N; //Antalet barn
	unsigned long long int antalonskade = 0; //Antalet totala godisar
	unsigned long long int value;
	list<unsigned long long int> lst;
	list<unsigned long long int>::iterator it;
	cin >> M >> N;
	unsigned long long int barnkvar = 0;
	unsigned long long int j = 0;
	unsigned long long int ilska = 0;
	unsigned long long int  godistill = 0;

	for (unsigned long long int i=0; i < N; i++){
		cin >> value;
		lst.push_back(value);
		antalonskade = antalonskade + value;
	}

lst.sort();
unsigned long long int antalkvar = antalonskade-M;

for (it=lst.begin(); it!=lst.end(); ++it){
    //std::cout << ' ' << *it;
	barnkvar = N-j;
	if (barnkvar > 0){
	godistill = min(*it,antalkvar/barnkvar);
	ilska = ilska + godistill*godistill;
	
	//std::cout << antalkvar/barnkvar << ' ';
	antalkvar = antalkvar - godistill;
	}
	j = j +1;
}
std::cout << ilska;
return 0;
}