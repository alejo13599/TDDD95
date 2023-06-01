#include <iostream>
#include <vector>

std::vector<std::vector<int>> votingVec;
std::vector<std::vector<int> > table;
std::vector<std::vector<int>> AvailMoves = {{1,2,4}, {0,3,5}, {3,0,6}, {2,1,7}, {5,6,0}, {4,7,1}, {7,4,2}, {6,5,3}};
std::vector<std::string> PossibleOutputs = {"NNN", "NNY", "NYN", "NYY", "YNN", "YNY", "YYN", "YYY"};

int Uxuhul(int CurrPriest, int  CurrStone, int numberOfPriests){
    if(CurrPriest == numberOfPriests){
       return CurrStone;
    }
    //Already found the best for that position.
    if(table[CurrPriest][CurrStone] != -1){
        return table[CurrPriest][CurrStone];
    }

    std::vector<int> PossibleMoves = AvailMoves[CurrStone];
    std::vector<int> Outcomes(3,0);
    for(int i=0; i<3; ++i){//# is the number of stones
        Outcomes[i] = Uxuhul(CurrPriest+1, PossibleMoves[i], numberOfPriests);
    }

    int favors1 = votingVec[CurrPriest][Outcomes[0]];
    int favors2 = votingVec[CurrPriest][Outcomes[1]];
    int favors3 = votingVec[CurrPriest][Outcomes[2]];

    if(favors2 >= favors3 && favors1 >= favors3){
        table[CurrPriest][CurrStone] = Outcomes[2];
        return Outcomes[2];
    }
    else if(favors1 >= favors2 && favors3 >= favors2){
        table[CurrPriest][CurrStone] = Outcomes[1];
        return Outcomes[1];
    }
    else {
        table[CurrPriest][CurrStone] = Outcomes[0];
        return Outcomes[0];
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int numberOfCases, numberOfPriests, vote;
    std::cin >> numberOfCases;
    for(int i = 0; i<numberOfCases; ++i){
        std::cin >> numberOfPriests;
        table.assign(numberOfPriests+1, std::vector<int>(8, -1));
        votingVec.assign(numberOfPriests, std::vector<int>(8, -1));

        for(int j = 0; j<numberOfPriests; ++j){
            std::vector<int> tempVec;
            for(int k = 0; k<8; ++k) {
                std::cin >> vote;
                tempVec.push_back(vote);
            }
            votingVec[j] = tempVec;
        }
        int s = Uxuhul(0,0, numberOfPriests);
        std::cout << PossibleOutputs[s] << std::endl;
    }

    return 0;
}
