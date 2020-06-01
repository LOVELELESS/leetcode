#include <iostream>
#include <vector>

using namespace std;

void func(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}

int main() {
  int size;
  cin >> size;
  vector<int> v;
  for (int i = 0; i < size; i++) {
    int ele;
    cin >> ele;
    v.push_back(ele);
    cout << ele << '\n';
  }

  func(v);
  return 0;
}
