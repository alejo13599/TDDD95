#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <string> 
using namespace std;

int chartoint(char file){
    if(file == 'a'){
        return 0;
    }
    if(file == 'b'){
        return 1;
    }
    if(file == 'c'){
        return 2;
    }
    if(file == 'd'){
        return 3;
    }
    if(file == 'e'){
        return 4;
    }
    if(file == 'f'){
        return 5;
    }
    if(file == 'g'){
        return 6;
    }
    if(file == 'h'){
        return 7;
    }
    return 0;
}

char inttochar(int rank){
    if(rank == 0){
        return 'a';
    }
    if(rank == 1){
        return 'b';
    }
    if(rank == 2){
        return 'c';
    }
    if(rank == 3){
        return 'd';
    }
    if(rank == 4){
        return 'e';
    }
    if(rank == 5){
        return 'f';
    }
    if(rank == 6){
        return 'g';
    }
    if(rank == 7){
        return 'h';
    }
    return 0;
}

int main() 
{
int H;
string W;
int NumberOfCases = 0;
queue<pair<int,int>> squarequeue;

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> NumberOfCases;
for(int k = 0; k<NumberOfCases; k++){
    int maxjumps = 0;
    cin >> W;
    vector<vector<int> > been(8, vector<int>(8, -1));
    int file = chartoint(W[0]);

    been[W[1]-'0'-1][file] = 0;
    squarequeue.push({W[1]-'0'-1,file});           
    // test.first är rank, test.second är file.
    while (!squarequeue.empty()){
        pair<int,int>test = squarequeue.front();
        //2 UPP, 1 VANSTER. [2, -1]
        if(test.first+2 < 8 && test.second-1 >= 0){
            if(been[test.first+2][test.second-1] == -1){
                squarequeue.push({test.first+2,test.second-1});
                been[test.first+2][test.second-1] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first+2][test.second-1]);
            }
        }
        //2 UPP, 1 HOGER [2, 1]
        if(test.first+2 < 8 && test.second+1 < 8){
            if(been[test.first+2][test.second+1] == -1){
                squarequeue.push({test.first+2, test.second+1});
                been[test.first+2][test.second+1] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first+2][test.second+1]);
            }
        }
        //2 NER, 1 VANSTER [-2, -1]
        if(test.first-2 >= 0 && test.second-1 >= 0){
            if(been[test.first-2][test.second-1] == -1){
                squarequeue.push({test.first-2, test.second-1});
                been[test.first-2][test.second-1] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first-2][test.second-1]);
            }  
        }
        //2 NER, 1 HOGER [-2, 1]
        if(test.first-2 >= 0 && test.second+1 < 8){
            if(been[test.first-2][test.second+1] == -1){
                squarequeue.push({test.first-2, test.second+1});
                been[test.first-2][test.second+1] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first-2][test.second+1]);
            }         
        }
        //1 UPP, 2 VANSTER. [1, -2]
        if(test.first+1 < 8 && test.second-2 >= 0){
            if(been[test.first+1][test.second-2] == -1){
                squarequeue.push({test.first+1, test.second-2});
                been[test.first+1][test.second-2] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first+1][test.second-2]);
            }        
        }
        //1 UPP, 2 HOGER. [1, 2]
        if(test.first+1 < 8 && test.second+2 < 8){
            if(been[test.first+1][test.second+2] == -1){
                squarequeue.push({test.first+1, test.second+2});
                been[test.first+1][test.second+2] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first+1][test.second+2]);
            }          
        }   
        //1 NER, 2 VANSTER [-1, -2]
        if(test.first-1 >= 0 && test.second-2 >= 0){
            if(been[test.first-1][test.second-2] == -1){
                squarequeue.push({test.first-1, test.second-2});
                been[test.first-1][test.second-2] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first-1][test.second-2]);
            }              
        }
        //1 NER, 2 HOGER [-1, 2]
        if(test.first-1 >= 0 && test.second+2 < 8){
            if(been[test.first-1][test.second+2] == -1){
                squarequeue.push({test.first-1, test.second+2});
                been[test.first-1][test.second+2] = been[test.first][test.second] + 1;
                maxjumps = max(maxjumps, been[test.first-1][test.second+2]);
            }        
            
        }      
        squarequeue.pop();  
            
    }

    cout << maxjumps << " ";
    for (int i=7; i>=0; i--){
        for (int j=0; j<8; j++){   
            if(been[i][j] == maxjumps){
                //cout << "i: " << i << endl;
                cout << inttochar(j) << i+1 << " ";
            } 
        }
    }
    cout << "\n";
}
return 0;
}