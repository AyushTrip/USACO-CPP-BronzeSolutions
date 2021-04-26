#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int n, answer = 0;
string sequence;

vector<int> c_occurances;
vector<int> o_occurances;
vector<int> w_occurances;

int main(){

  ifstream fin("cow.in");
  ofstream fout("cow.out");

  fin >> n;
  fin >> sequence;

  for (int i=0; i<n; i++){
    if (sequence[i] == 'C'){
      c_occurances.push_back(i);
    }
    if (sequence[i] == 'O'){
      o_occurances.push_back(i);
    }
    if (sequence[i] == 'W'){
      w_occurances.push_back(i);
    }
  }

  int answer = 0;
  for (int i : c_occurances){
    for (int j : o_occurances){
      for (int k : w_occurances){
        cout << "RAW " << i << j << k << endl;
        if (i < j && j < k){
          answer++;
        }
      }
    }
  }

  fout << answer;
  return 0;
}


//if (sequence[i] < sequence[j] && sequence[j] < sequence[k]){
// cout << i << j << k << endl;
//}
