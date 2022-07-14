#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;

int compute_min_refills(int location, int dist, int tank, vector<int> & stops, bool & reachable, int & cnt) {
  cnt++;
  
  if (location + tank >= dist){
    return 0;
  }

  if (stops.empty() || ((stops[0] - location) > tank)){
    reachable = false;
  }

  int lastStop = location;

  while (!stops.empty() && (stops[0] - location) <= tank){
    lastStop = stops[0];
    stops.erase(stops.begin());
  }
  
  if (reachable == false){
    return -cnt;
  } else{
    return 1 + compute_min_refills(lastStop, dist, tank, stops, reachable, cnt);
  }
}


int main() {

  
  int dist = 0;
  cin >> dist;
  int tank = 0;
  cin >> tank;
  int nStops = 0;
  cin >> nStops;
  

  vector<int> stops(nStops);
  for (size_t i = 0; i < nStops; ++i)
    cin >> stops.at(i);


  
  bool reachable = true;
  int cnt = 0;

/*
  int dist = 700;
  int tank = 200;
  int nStops = 4;
  vector<int> stops = {100, 200, 300, 400};
  */
  
  

  int location = 0;
  cout << compute_min_refills(location, dist, tank, stops, reachable, cnt) << "\n";

  return 0;
}
