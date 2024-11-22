class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    unordered_map<string, int>
        patternCount; // To store the patterns and their counts
    int maxRows = 0;

    for (const auto &row : matrix) {
      string pattern;
      for (int j = 0;) {
        normalPattern += to_string(cell);
        flippedPattern += to_string(1 - cell); // Flip the cell value
      }
      // Increment the count for both patterns
      rowPatterns[normalPattern]++;
      rowPatterns[flippedPattern]++;
      // Update the maximum rows count
      maxRows = max(
          {maxRows, rowPatterns[normalPattern], rowPatterns[flippedPattern]});
    }

    return maxRows;
  }
};

#include <iostream>
#include <vector>
using namespace std;

int main() {
  Solution solution;
  vector<vector<int>> matrix1 = {{0, 1}, {1, 1}};
  cout << solution.maxEqualRowsAfterFlips(matrix1) << endl; // Output: 1

  vector<vector<int>> matrix2 = {{0, 1}, {1, 0}};
  cout << solution.maxEqualRowsAfterFlips(matrix2) << endl; // Output: 2

  vector<vector<int>> matrix3 = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
  cout << solution.maxEqualRowsAfterFlips(matrix3) << endl; // Output: 2

  return 0;
}
