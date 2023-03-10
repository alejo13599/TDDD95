#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <string>

using namespace std;

int NumberOfCases;
int NumberOfTeams;
string x;
double y;
unsigned int set1;
unsigned int set2;
unsigned int setind1;
unsigned int setind2;
char oper;
vector<int> parent;
vector<int> rankvec;
vector<pair<int,string>> IslandVector = {};


//Taking an int as input reoresenting a node and returning the parent to that node.

int main() {
//To make the input faster
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> NumberOfCases;

for(long long int i=0; i<NumberOfCases; i++){
    long long int badness = 0;
    double total = 0;
    vector<pair<int,string>> IslandVector = {};

    cin >> NumberOfTeams;
    for(int i=0; i<NumberOfTeams; i++){
        cin >> x >> y;
        IslandVector.push_back(make_pair(y,x));
    }
    sort(IslandVector.begin(), IslandVector.end());
        for(int i=0; i<NumberOfTeams; i++){
        badness = badness + abs((IslandVector[i].first - (i+1)));
    }
    cout << badness << endl;

}
return 0;
}