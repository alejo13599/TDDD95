#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int NumberOfCases;
int NumberOfTeams;
string x;
double y;

int main() {
    cin >> NumberOfCases;
    for(long long int i=0; i<NumberOfCases; i++){
        long long int badness = 0;
        vector<int> PrefVector = {};
        cin >> NumberOfTeams;
        for(int i=0; i<NumberOfTeams; i++){
            cin >> x >> y;
            PrefVector.push_back(y);
        }

        sort(PrefVector.begin(), PrefVector.end());
        for(int j=0; j<NumberOfTeams; j++){
            badness += abs((PrefVector[j] - (j+1)));
        }
        cout << badness << endl;
    }    
return 0;
}