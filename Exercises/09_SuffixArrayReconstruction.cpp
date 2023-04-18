#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
vector<char> stringAt;
int stringLength;
int Suffixes;
int number;
int NumberOfCases;
string text;
int possible, jumps, extra = 0;

int main() {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cin >> NumberOfCases;
for(int i=0; i<NumberOfCases; i++){cin >> stringLength >> Suffixes;
    possible = 0;
    stringAt.assign(stringLength+1,'?');
    for(int j=0; j<Suffixes; j++){
        cin >> number;
        getline(cin, text);
        jumps=0;

        for(int k=number; k<=stringLength+extra; k++){
            if((k-1+jumps) < stringLength){
                if(text[k-number+1] == '*'){
                    jumps = (stringLength-number+1)-(text.length()-1);
                    if(jumps<0){extra=-jumps;}
                    continue;
                }
                if(stringAt[k-1+jumps] == '?' && text[k-number+1] != '*'){
                    stringAt[k-1+jumps] =  text[k-number+1];
                }
                else if(stringAt[k-1+jumps] != text[k-number+1] && text[k-number+1] != '*'){
                    possible = 1;
                }
            }
        }
    }
    for(int j=0; j<stringLength; j++){
        if(stringAt[j] == '?'){
            possible = 1;
            break;
        }
    }
    if(possible == 1)
    {cout << "IMPOSSIBLE ";}
    else{
        for(int k=0; k<stringLength; k++){
            cout << stringAt[k];
        }
    }
    cout << endl;
}
return 0;
}