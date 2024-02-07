#include <iostream>
#include <string>
using namespace std;

#define __define_ocg__

string ArrayChallenge(string strArr[], int arrLength) {
  // __define_ocg__
  int N = stoi(strArr[0]);
  int gas[N];
  int cost[N];

  for (int i = 1; i <= N; i++) {
    size_t pos = strArr[i].find(":");
    gas[i - 1] = stoi(strArr[i].substr(0, pos));
    cost[i - 1] = stoi(strArr[i].substr(pos + 1));
  }

  int start = 0;
  int tank = 0;
  int total_gas = 0;
  int total_cost = 0;

  for (int i = 0; i < N; i++) {
    total_gas += gas[i];
    total_cost += cost[i];
    tank += gas[i] - cost[i];

    if (tank < 0) {
      start = i + 2;
      tank = 0;
    }
  }

  if (total_gas >= total_cost) {
    return to_string(start);
  } else {
    return "impossible";
  }
}

int main(void) {
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayChallenge(A, arrLength);
  return 0;
}
