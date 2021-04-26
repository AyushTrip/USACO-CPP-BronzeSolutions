#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    int a_capacity, b_capacity, c_capacity;
    int a,b,c;

    fin >> a_capacity >> a;
    fin >> b_capacity >> b;
    fin >> c_capacity >> c;

    for(int i = 3; i < 103; i++){

      // Pour bucket A to bucket B
      if (i % 3 == 0){
        if (a > (b_capacity - b)){
          a -= (b_capacity - b);
          b = b_capacity;
        }

        else{
          b += a;
          a = 0;
        }
      }

      // Pour bucket B to bucket C
      if (i % 3 == 1){
        if (b > (c_capacity - c)){
          b -= (c_capacity - c);
          c = c_capacity;
        }

        else{
          c += b;
          b = 0;
        }
      }

      //Pour bucket C to bucket A
      if (i % 3 == 2){
        if (c > (a_capacity - a)){
           c -= (a_capacity - a);
           a = a_capacity;
        }

        else{
          a += c;
          c = 0;
        }
      }
    }

    fout << a << '\n' << b << '\n' << c;
    return 0;
}
