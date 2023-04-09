#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
int number;
int Newnumber;
int NumberOfCases;
int datanumber;
string text;
bool happy = false;
bool prime = false;
int k = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> NumberOfCases;
    for(int i=0; i<NumberOfCases; i++){
        prime = true;
        happy = false;
        k = 0;
        cin >> datanumber >> number;
        //Testing if prime
        if(number <= 1){
            prime = false;
        }
        for(int j=2; j*j<=number; j++){
            if(number%j == 0){
                prime = false;
                break;
            }
        }
        text = to_string(number);
        while((Newnumber != number && prime) && k<1000){
            Newnumber = 0;
            for(int j=0; j < text.length(); j++){
                Newnumber += (text[j]-'0')*(text[j]-'0');
            }
            //cout << Newnumber << endl;
            if(Newnumber == 1){
                happy = true;
                break;
            }
            k += 1;
            text = to_string(Newnumber);
        }
    cout << datanumber << " " << number << " ";
    if(happy){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;      
    }
    }
return 0;
}