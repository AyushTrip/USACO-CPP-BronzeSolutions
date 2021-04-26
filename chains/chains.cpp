#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;



int main(){
  // READ INPUT
  int n;
  cin >> n;
  int array[n];
  for (int i=0; i<n; i++){
    cin >> array[i];
  }

  // Iterate through and find every combination of averages
  int photos = 0;
  for (int i=0; i<n; i++){
    for (int j=i; j<n; j++){
      int sum = 0;
      for (int k = i; k <= j;k++){
        sum += array[k];
      }
      bool present = false;
      for (int k =i; k <= j; k++){
        if (array[k] * (j-i+1) == sum){
          photos++;
          break;
        }
      }
    }
  }
  cout << photos << endl;


  return 0;
}
