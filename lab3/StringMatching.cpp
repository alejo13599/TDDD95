// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: 
// Time-complexity: 
// Memory-complexity:
// Note: 
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
vector<long long> patternPositions = {};
string pattern{};
string text{};

vector<int> create_prefix_table(string s){
    int n = s.length();
    vector<int> table(n);
    for(int i=1; i<n; i++){
        int j =table[i-1];
        while(j>0 && s[i] != s[j]){
            j = table[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        table[i] = j;
    }
    return table;
}


int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
while(getline(cin, pattern)){
    getline(cin, text);
    vector<int> prefix_table = create_prefix_table(pattern);
    long long textInd = 0;
    long long patternInd = 0;
    while(textInd < text.length()){
        if(pattern[patternInd] == text[textInd]){
            textInd++;
            patternInd++;
        }
        if(patternInd == pattern.length()){
            cout << textInd-patternInd  << " ";
            patternInd = prefix_table[patternInd-1];  
        }
        else if(textInd < text.length() && pattern[patternInd] != text[textInd]){
            if (patternInd != 0){
                patternInd = prefix_table[patternInd-1];  
            }
            else{
                textInd++;
            }
        }
    }
    cout << endl;
}
return 0;
}