// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Taking two sequnces of integers representing polynomials and outputing the product of them.
// Time-complexity: Polynomial multiplication normally takes O(n^2)-time but with FFT this can be improved to
// O(nlogn)-time since it uses a combination of divide & conquer and recursion.
// Memory-complexity: O(N) since it saves vectors of length N.
// Note: Can only be used for polynomials up to 10^5.

#include <iostream>
#include <vector>
#include <complex>
#include <algorithm> 

using namespace std;

int NumberOfCases;
int DegreeOfPolynomial;
int Coeff;
using cd = complex<double>;
const double PI = acos(-1);

vector<int> poly1;
vector<int> poly2;

//fft takes a vector and a bool as a input. It calculates the fft or the inverse fft based on the bool.
void fft(vector<cd> & a, bool invert){
    int n = a.size();
    if (n == 1){
        return;
    }
    vector<cd> a0(n / 2), a1(n / 2);
    for(int i = 0; 2*i < n; i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2*PI/n*(invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));

    for (int i = 0; 2 * i < n; i++){
        a[i] = a0[i] + w*a1[i];
        a[i + n/2] = a0[i] - w*a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w = w*wn;
    }


}

//Takes two vectors representeing polynomials as input and calculating the product of them. Returning a vector representing
//the product.
vector<int> multiply(vector<int> const& a, vector<int> const& b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size()){
        n <<= 1;
    }
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; i++){
        fa[i] = fa[i]*fb[i];
    }
    fft(fa, true);
    vector<int> result(n);

    for (int i = 0; i < n; i++){
        result[i] = round(fa[i].real());
    }
    return result;
}

//creatingPolynomials takes 2 inputs, coeff and a int i which is 0 or 1 depending on polynomial coeff should be in.
void creatingPolynomials(int Coeff, int i){
    if(i==0){
        poly1.push_back(Coeff); 
    }
    else{
        poly2.push_back(Coeff);   
    }
}

int main() 
{
//To make the input faster
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> NumberOfCases;

int i=0;
while(cin >> DegreeOfPolynomial){
    for(int j=0; j<=DegreeOfPolynomial; j++){
        cin >> Coeff;
        creatingPolynomials(Coeff, i);
    }
    i=i+1;
}
    vector<int> z;
    z = multiply(poly1, poly2);
    cout << (poly1.size()-1)+(poly2.size()-1) << "\n";
    for (int k = 0; k<=(poly1.size()-1)+(poly2.size()-1); k++){
    cout << z[k] << " ";
    }
    
return 0;
}
