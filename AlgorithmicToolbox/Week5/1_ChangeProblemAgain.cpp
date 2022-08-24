/*
  * Compilación:
  *  g++ -std=c++17 *.cpp -o main
  *
  * Ejecución - Casos de prueba:
  *  ./main
*/ 

#include <iostream>
#include <vector>
using std::vector;

int get_change(int m) {
  vector<int> coins = {1, 3, 4};
  vector<int> minCoins(m+1, m+1);
  minCoins[0] = 0;

  for (int i = 1; i < minCoins.size(); i++) {
    int currentNumCoins = minCoins[i];
    for (auto c : coins) {
      if (c <= i) {
        currentNumCoins = minCoins[i-c] + 1;
        if (currentNumCoins < minCoins[i]) {
          minCoins[i] = currentNumCoins;
        }
      }
    }
  }
  return minCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}