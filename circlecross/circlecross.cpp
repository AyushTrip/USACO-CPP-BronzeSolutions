#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

string cows;
vector<pair <char, char>> combinations;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int answer = 0;

//Find occurances of a character in a string function
vector<int> find(string sequence, char a){
  vector<int> locations;

  for(int i=0; i<sequence.size(); i++){
    if(sequence[i] == a){
      locations.push_back(i);
    }
  }
  return locations;
}


int main(){
  ifstream fin("circlecross.in");
  ofstream fout("circlecross.out");

  fin >> cows;

  for (int i=0; i<26; i++){
    for (int j=0; j<26; j++){
      combinations.push_back(make_pair(alphabet[i], alphabet[j]));
    }
  }

  for(int i=0; i<combinations.size(); i++){
    if(combinations[i].first != combinations[i].second){
      vector<int> result1 = find(cows, combinations[i].first);
      vector<int> result2 = find(cows, combinations[i].second);


      if (result1[0] < result2[0] && result2[0] < result1[1] && result1[1] < result2[1]){
        answer++;
      }
    }
  }

  fout << answer;
  return 0;
}
