#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int answer = 0;
int temp = 0;

vector<int> cows;
vector<int> possible_answers;

int main(){
  ifstream fin("cbarn.in");
  ofstream fout("cbarn.out");

  fin >> n;
  int cowsraw[n];

  //Read in cow input
  for(int i=0; i<n; i++){
    fin >> cowsraw[i];
  }

  //Create the cow vector

  for(int i=0; i<2; i++){
    for(int j=0; j<n; j++){
      cows.push_back(cowsraw[j]);
    }
  }

  //Find answer
  for(int i=0; i<n+1; i++){
    answer = 0;
    temp = 0;
    for(int j=0; j<n; j++){
      answer += (cows[i+j] * temp);
      temp++;
    }

    possible_answers.push_back(answer);
  }

  int idx = 0;
  for(int i=1; i<possible_answers.size(); i++){
    if (possible_answers[i] < possible_answers[idx]){
      idx = i;
    }
  }

  fout << possible_answers[idx];
  return 0;
}
