#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
vector<char> stringAt;
int variables;
int clauses;
int NumberOfCases;
string text;
int possible, jumps, extra = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> NumberOfCases;
    cout << NumberOfCases << endl;
    for(int i=0; i<NumberOfCases; i++)
    {
    cin >> variables >> clauses;
    //cout << variables << clauses;
    //cout << variables << clauses << endl;
        for(int j=0; j<=clauses; j++){
            getline(cin, text);
            string part;
            stringstream ss(text);
            while(getline(ss, part, ' ')){
                if(part != "v"){
                    cout << part << " ";
                }
            }
        cout << endl;
        }
    //cout << endl;
    }
return 0;
}