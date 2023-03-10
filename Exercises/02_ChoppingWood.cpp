#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include<cmath>
#include<map>

using namespace std;
int main() 
{
int N;
int leaf;
vector<int> degreevector = {};
vector<int> leafvec = {};
multimap<int, int> leafmap; 
vector <tuple<int, int, int>> degreepairs;
cin >> N;

for (int i=0; i < N; i++){
		cin >> leaf;
		leafmap.insert(pair<int, int>(leaf,i));
		leafvec.push_back(leaf);
        //cout << leaf;
	}
return 0;
}