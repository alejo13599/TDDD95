// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is: Longest increasing Subsequence, "In a given subsequence, to find a subsequence which is sorted and is as long as possible."
//
// Time-complexity: O(NlogN). The algorithm performs one binary search per element in the sequence, a binary search has the
//time-complexity O(logN) and since it is performed N-times the time-complexity becomes O(NlogN).



#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include<cmath>


using namespace std;

int input;
int N = 0;
int middle = 0;
int k = 0;

void solver(vector<int> inputvec, int N){
    vector<int>Predecessors (N,0); //Vector where each position corresponds to the largest index giving the LIS ending atthat position.
    vector<int>Subseqends (N+1,0); //Vector where each position corresponds to previous index in the LIS-sequence.
    Subseqends[0] = -1;
    int L = 0;
    int newLow = 0;

    for(int i=0; i<N; i++){//Itererar över sekvensen
        int low = 1;
        int high = L+1;
        //Binary Search
        while (low < high){
            middle = low + floor((high-low)/2);

            if (inputvec[Subseqends[middle]] >= inputvec[i]){
                high = middle;
            }
            else{
                low = middle + 1;

            }
        } // END of while
        newLow = low;

        Predecessors[i] = Subseqends[newLow-1];
        Subseqends[newLow] = i;

        //L is updated if we found a new LIS
        if (newLow > L){
            L = newLow;
        }
    
    
    }
    vector<int> svarvec(L, 0);
    cout << L << '\n';
    //Reconstructing LIS based on the Predessors vector.
    k = Subseqends[L];

    for(int j=L-1; j>=0; j--){
        svarvec[j] = k;
        k = Predecessors[k];
    }

    for(int j=0; j<L-1; j++){
        cout << svarvec[j]  << ' ';
    }
    cout << svarvec[L-1]  << ' '; 
}

int main() 
{

while (cin >> N){ 

    vector<int> inputvec(N, 0);
    

    for(int i=0; i<N; i++){  //Readng the input-sequnce
        cin >> inputvec[i];
    }
    solver(inputvec, N);

}   
return 0;
}