/*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < prueba.txt
*/

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int edit_distance(const string &str1, const string &str2) {

  vector<vector<int>> distances(str2.size()+1);

  for (int i = 0; i < str1.size()+1; i++) {
    distances[0].push_back(i);
  }

  for (int i = 1; i < str2.size()+1; i++) {
    distances[i].push_back(i);
  }

  for (int i = 1; i < str2.size()+1; i++) {
    for (int j = 1; j < str1.size()+1; j++) {

      if (str1[j-1] == str2[i-1]) {
        distances[i].push_back(distances[i-1][j-1]);
      } else {
        distances[i].push_back(std::min(distances[i][j-1], std::min(distances[i-1][j-1], distances[i-1][j])) + 1);
      }
    }
  }

  // This prints the matrix
  /* 
  for (int i = 0; i < str2.size()+1; i++) {
    for (int j = 0; j < str1.size()+1; j++) {
      cout << distances[i][j] << " ";
    }
    cout << endl;
  }
  */
  
  
  return distances[str2.size()][str1.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}