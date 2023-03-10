#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;
int main() 
{
	double N;
    double magnN;
    long double maxdivider;
    long double pkandidat;
    long double p = 1;
 while (cin >> N){  
    p = 1;
    if (N == 0){
        return 0;
    }
    magnN = fabs(N);
    maxdivider = sqrt(magnN);
    for(long long int i = 2; i<=maxdivider; i++){
        pkandidat = log(magnN)/log(i);
        //cout << pkandidat << " ";
        //cout << pkandidat - floor(pkandidat) << " ";
        if (pkandidat > 1 && (pkandidat - floor(pkandidat) )<1e-10 ){
            if(magnN == N ){
                p = pkandidat;
                //cout << int(pkandidat)%2 << " magnN" << magnN << "\n" ;
            break;
            }
            else if(magnN != N && int(pkandidat)%2 != 0){
                p = pkandidat;
                break;
            }
        }
    }
    cout << p << "\n";
 }
return 0;
}
