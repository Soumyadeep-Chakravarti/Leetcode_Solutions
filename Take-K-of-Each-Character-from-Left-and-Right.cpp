#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;

#define NO_SAN                                                                 \
  __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))

class Solution {
private:
  static constexpr uint MAXV = 100'000;
  static array<uint16_t, 3> freqs; // Using std::array for better type safety

  static bool checkFreqs(const int k) INL NO_SAN HOT {
    return freqs[0] >= k && freqs[1] >= k && freqs[2] >= k;
  }

public:
  static int takeCharacters(const string &s, const int k) NO_SAN HOT {
    const int n = s.length();
    fill(freqs.begin(), freqs.end(), 0);

    for (char c : s) {
      freqs[c - 'a']++;
    }

    if (!checkFreqs(k)) {
      return -1;
    }

    int result = n;
    int left = 0;
    array<uint16_t, 3> window = {0, 0, 0};

    for (int right = 0; right < n; right++) {
      window[s[right] - 'a']++;

      while (freqs[0] - window[0] < k || freqs[1] - window[1] < k ||
             freqs[2] - window[2] < k) {
        window[s[left] - 'a']--;
        left++;
      }

      result = min(result, n - (right - left + 1));
    }

    return result;
  }
};

array<uint16_t, 3> Solution::freqs;

static auto init = []() NO_SAN HOT {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

int main() {
  Solution sol;
  cout << sol.takeCharacters("aabaaaacaabc", 2) << endl; // Expected Output: 8
  cout << sol.takeCharacters("a", 1) << endl;            // Expected Output: -1
  return 0;
}
