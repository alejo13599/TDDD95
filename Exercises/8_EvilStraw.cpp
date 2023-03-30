#include <iostream>
#include <vector>
#include <cmath>
#include <string> 
using namespace std;
string theString;
int NumberOfCases, swaps, NumberofOdd, OddLetterPos = 0;
char OddLetter;
vector<int> letterCount(26,0);
int main() 
{
cin >> NumberOfCases;
for(int i = 0; i<NumberOfCases; i++){
    int swaps = 0;
    letterCount.assign(27,0);
    NumberofOdd = 0;
    cin >> theString;
    for(int j=0; j<theString.size(); j++){letterCount[theString[j] - 'a'] += 1;}
    for(int j=0; j<=26; j++){
        if(letterCount[j]%2 > 0){
            NumberofOdd += 1;
            OddLetter = j + 'a';
        }
    }
    if(NumberofOdd > 1)
    {cout << "impossible " << endl;continue;}
    for(int j = 0; j<theString.size()/2+1; j++){
        char currentletter = theString[j];
        for(int k=theString.size()-j-1; k>=0; k--){
            if(currentletter == OddLetter && theString[k] == OddLetter && NumberofOdd==1 && letterCount[OddLetter - 'a'] == 1){
                OddLetterPos = k;
                theString.erase(k, 1);
                currentletter = theString[j];
                k=theString.size()-j;
                letterCount[OddLetter - 'a'] -= 1;
                continue;
            }
            if(theString[k] == currentletter && k != j){
                if(currentletter == OddLetter){letterCount[OddLetter - 'a'] -= 2;}
                
                if(k == theString.size()-1-j){break;}
                else{
                    int Diff = (theString.size()-1 -j)- k;
                    Diff = abs(Diff);
                    swaps += Diff;
                    for(int l=0; l<Diff; l++){swap(theString[k+l], theString[k+l+1]);}                    
                    break;
                }          
            }
        }
    }
    if(NumberofOdd == 1){cout << swaps  + theString.size()/2-OddLetterPos << endl;}
    else{cout << swaps << endl;};
}
return 0;}