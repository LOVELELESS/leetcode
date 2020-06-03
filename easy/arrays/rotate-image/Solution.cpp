#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int topR = 0;
        int botR = n - 1;
        int leftC = 0;
        int rightC = n - 1;
        for (int s = n; s > 0; s -= 2) {
            for (int i = 0; i < s - 1; i++) {
                int currR = topR;
                int currC = leftC + i;
                int currNum = matrix[currR][currC];
                for (int j = 0; j < 4; j++) {
                    int nextR = currR;
                    int nextC = currC;
                    switch (j) {
                        case 0:
                            for (int k = 0; k < s - 1; k++) {
                                if (nextC + 1 == leftC + s) {
                                    nextR++;
                                } else {
                                    nextC++;
                                }  
                            }
                            break;
                        case 1:
                            for (int k = 0; k < s - 1; k++) {
                                if (nextR + 1 == topR + s) {
                                    nextC--;
                                } else {
                                    nextR++;
                                }  
                            }
                            break;
                        case 2:
                            for (int k = 0; k < s - 1; k++) {
                                if (nextC - 1 == rightC - s) {
                                    nextR--;
                                } else {
                                    nextC--;
                                }  
                            }
                            break;
                        case 3:
                            for (int k = 0; k < s - 1; k++) {
                                if (nextR - 1 == botR - s) {
                                    nextC++;
                                } else {
                                    nextR--;
                                } 
                            }
                            break;
                    }
                    //cout << "nextR: " << nextR << endl;
                    //cout << "nextC: " << nextC << endl;
                    //cout << "val: " << currNum << endl;
                    int tmp = matrix[nextR][nextC];
                    matrix[nextR][nextC] = currNum;
                    currNum = tmp;
                    currR = nextR;
                    currC = nextC;
                }
            }
            topR++;
            botR--;
            leftC++;
            rightC--;
        }
    }
};

int main() {
  vector<int> v1 = {1,2};
  vector<int> v2 = {3,4};
  vector<vector<int>> v;
  v.push_back(v1);
  v.push_back(v2);
  Solution solution;
  solution.rotate(v);
  return 0;
}
