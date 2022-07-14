 /*
  * Algoritmos de ordenamiento
  * 
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución:
  *  ./main < test.txt
  */

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

typedef long long int lli;

int binarySearch(vector<lli> vect, lli key){
  int l = 0;
  int r = vect.size() - 1;
  int mid = 0;

  while (l <= r){
    mid = l + ((r - l) / 2);
    if (vect[mid] == key) return mid;
    else if (vect[mid] > key)r = mid - 1;
    else l = mid + 1;
  }
  
  return -1;  
}

int main() {

  int n, k;

  cin >> n;
  vector<lli> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  cin >> k;
  vector<lli> b(k);
  for (int i = 0; i < k; i++){
    cin >> b[i];
  }

  for (int i = 0; i < k; i++){
    cout << binarySearch(a, b[i]) << " ";
  }
}