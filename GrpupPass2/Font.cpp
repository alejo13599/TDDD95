// Author: Alexander Josefsson
// Liuid: Alejo135
// Problem is:
// Time-complexity: 
// Memory-complexity:
// Note: 
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

bool checkOccurances(std::vector<std::string> const & wordsInTestSentence) {
/* For a vector of words, checks if all characters in the alphabet occurs. */

    std::vector<bool> occurances(26, false);

    // Set occurence at the correct index in the vector to true
    for(std::string word : wordsInTestSentence){
        for(int j = 0; j < word.size(); j++){
            occurances[word[j] - 'a'] = true;
        }
    }


    for(int i=0; i<occurances.size(); i++){
        if(!occurances[i]){
            // the whole alphabet is not covered 
            return false;
        }
        if(i == occurances.size()-1){
            // the whole alphabet is covered 
            return true;
        }
    }

    return false;
}

vector<vector<int>>combinations(vector<int> inputarr, vector<int> temparr, vector<vector<int>> & outputarr, int start, int end, int index, int nrOfElemToRemove){

    if (index == nrOfElemToRemove)
    {
        // base case
        std::vector<int> outputLine;
        for (int j = 0; j < nrOfElemToRemove; j++)
        {
            outputLine.push_back(temparr[j]);
        }
        //sort(outputLine.begin(), outputLine.end());
        outputarr.push_back(outputLine);
        return outputarr;
    }
 
    for (int i = start; i <= end && end- i + 1 >= nrOfElemToRemove - index; i++)
    {
        //std::cout << "ska vara här" << std::endl;
        temparr[index] = inputarr[i];
        combinations(inputarr, temparr, outputarr, i+1, inputarr.size(), index+1, nrOfElemToRemove);
    }
    //std::cout << "ska inte vara här" << std::endl;
    return outputarr;
}

int findsentences(int index, int occur){


}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int NumberOfWords;
string word;
int count = 0;
cin >> NumberOfWords;
vector<string> Words;
vector<int> inputarr;
for(int i=0; i<NumberOfWords; i++){
    cin >> word;
    inputarr.push_back(i);
    Words.push_back(word);
}




return 0;
}