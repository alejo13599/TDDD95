#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

int main() 
{
    long long L = 0;
    long long D = 0;
	long long N = 0; //Fåglar som redan sitter där
	unsigned long long int index = 0;
	double nuvarandestart;//Start för intervallet
	double nuvarandeslut;//Slut för intervallet
	string input;
    vector<long long> birdvector = {}; //Vector with the correct-intervall indexes
    long long Dcovered = 6;
    long long birdpos = 0;
    long long svar = 0;


cin >> L >> D >> N;
birdvector.assign(0,N);
for (long i=0; i<N; ++i){
    cin >> birdpos;
    birdvector.push_back(birdpos);

}
sort(birdvector.begin(), birdvector.end());

//Får inte sitta mer än 6cm från stolparna. 12 cm totalt
if (N == 0){
    svar = (L-12)/D+1;
    cout << svar;
    return 0;
}
else{
    for (long j=0; j<N; ++j){
        while (birdvector[j] - Dcovered >= D){
            svar = svar + 1;
            Dcovered = Dcovered + D;
        }
        Dcovered = birdvector[j] + D;
    }
    //cout << svar << "\n";
    //cout << Dcovered << " " << D << "\n";
    if(Dcovered <= L-6){
        svar= svar +1;
    }
    //cout << svar << "\n";
    // cout << L << " " << Dcovered << " " << D << "\n";
    int svar2 = floor((L-Dcovered-6)/D);
    if (svar2 > 0){
    svar = svar + svar2;
    }

}

    cout << svar;

return 0;
}
