#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

int N;

int main(){
  ifstream fin("baseball.in");
  ofstream fout("baseball.out");

  fin >> N;
  int cows[N];
  for (int i=0; i<N; i++){
    fin >> cows[i];
  }
  
  fin.close();
  sort(cows, cows + N);

  int answer = 0;
  for(int i=0; i<N; i++){
    for (int j=i+1; j<N; j++){
      for (int k=j+1; k<N; k++){
        int first_throw = cows[j] - cows[i];
        int second_throw = cows[k] - cows[j];

        if (first_throw <= second_throw && second_throw <= 2*first_throw){
          answer++;
        }
      }
    }
  }
  fout << answer;
  fout.close();
  return 0;
  
}
