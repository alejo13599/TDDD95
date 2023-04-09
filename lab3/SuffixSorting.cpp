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
string text{};
vector<int> sorted_shifts;
int q;
int numberofqueries;
class SuffixArray{

private:
    static vector<int> sorting(string const& s){
        int n = s.size();
        int ascii = 256; //Using the whole ASCII-alphabet since i dont know which charcaters coud be used.
        vector<int> permutation(n);
        vector<int> equivalence(n); //A vector keeping track of identical suffixes. If two indexes have the same number, the suffixes are identical in the current iteration.
        vector<int> count(max(ascii, n), 0);

        for(int i=0; i<n; i++){
            count[s[i]]++;
        }
        for(int i=1; i<ascii; i++){
            count[i] += count[i-1];
        }
        for (int i = 0; i < n; i++){
            permutation[--count[s[i]]] = i;
        }

        equivalence[permutation[0]] = 0;
        int classes = 1; //Classes is the number of different elements we have in the equvialence vector
        for (int i = 1; i < n; i++){
            if(s[permutation[i]] != s[permutation[i-1]]){
                classes += 1;
            }
            equivalence[permutation[i]] = classes-1;
        }
        vector<int> temp_perm(n);
        vector<int> temp_equ(n);
        //Goes through
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                temp_perm[i] = permutation[i] - (1 << h);
                if (temp_perm[i] < 0)
                    temp_perm[i] += n;
            }
            fill(count.begin(), count.begin() + classes, 0);
            for (int i = 0; i < n; i++){
                count[equivalence[temp_perm[i]]] += 1;
            }
            for (int i = 1; i < classes; i++){
                count[i] += count[i-1];
            }
            for (int i = n-1; i >= 0; i--){
                permutation[--count[equivalence[temp_perm[i]]]] = temp_perm[i];
            }
            temp_equ[permutation[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {equivalence[permutation[i]], equivalence[(permutation[i] + (1 << h)) % n]};
                pair<int, int> prev = {equivalence[permutation[i-1]], equivalence[(permutation[i-1] + (1 << h)) % n]};
                if (cur != prev){
                    classes += 1;
                }
            temp_equ[permutation[i]] = classes - 1;
            }
            equivalence.swap(temp_equ);
        }
        return permutation;
    }
public:
    //Adds char(0) to the end of the string to be able to to sort with cyclic shifts.
    void construct_suffix_array(string s) {
        s += char(0);
        sorted_shifts = sorting(s);
        sorted_shifts.erase(sorted_shifts.begin()); //The first element in the vector will be the element only containg the stopping character
                                                        //and it is therfore removed.
    }
    int getSuffix(int i){
        return sorted_shifts[i];
    }

};
int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
while(getline(cin, text)){
    SuffixArray suffarr;
    suffarr.construct_suffix_array(text);
    cin >> numberofqueries;

    for(int i=0; i<numberofqueries; i++){
        cin >> q;
        cout << suffarr.getSuffix(q)<< " ";
    }
    cout << endl;
    getline(cin, text); 
}
return 0;
}