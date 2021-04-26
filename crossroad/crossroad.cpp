#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n, cow, side;
int answer = 0;

int main(){
  ifstream fin("crossroad.in");
  ofstream fout("crossroad.out");

  fin >> n;
  int logs[n] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

  for(int i=0; i<n; i++){
    fin >> cow >> side;


    if (logs[cow-1] != 2 && logs[cow-1] != side){
      answer++;
    }

    logs[cow-1] = side;
  }

  fout << answer;
  return 0;
}
