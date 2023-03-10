#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> leafvec;
vector<int> inputseq;
int currleaf;
int N;

int main(void) {
  cin >> N;
  vector<int> inputseq(N);

  for (int i = 0; i < N; i++){ 
    cin >> currleaf;
    inputseq[i] = currleaf;
  }

  if (inputseq.back() != N+1) {
    cout << "Error\n";
    return 0;
  }
vector<int> NumEdges(N, 0);

for (vector<int>::iterator i = inputseq.begin(); i != inputseq.end(); ++i){ //Räknar Edges för alla noder.

  NumEdges[*i-1] = NumEdges[*i-1] + 1;
}
    
for (int i = 0; i < N; ++i){ //Beräknar vilka som har 0 edges och läger till dessa i kön

  if (!NumEdges[i]){
    cout << i;
    leafvec.push(-i); //Proroty Queue lägger de största elementen först, vi vill ha de minsta först.
  }
  
}
    //Nedanför är för att printa ut

for (vector<int>::iterator i = inputseq.begin(); i != inputseq.end(); ++i){
  //cout << -leafvec.top()+1 << "\n";
  leafvec.pop(); // Skriver ut det översta elementet.

  //cout << NumEdges[*i-1];
  if (!--NumEdges[*i-1]){ 
    //cout << NumEdges[*i-1];
    //cout << "hej" << endl;
    leafvec.push(1-*i);
    //cout << "hej" << endl;
  }
}
  cout << "hej" << endl;
  return 0;

}
