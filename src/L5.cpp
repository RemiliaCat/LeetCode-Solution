#include <string>
#include <utility>

using namespace std;

class Solution {
  private:
    pair<int, int> expand(const string &s, int left, int right) const {
        const int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

  public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n < 2) {
            return s;
        }
        int maxL = 0, maxR = 0;
        for (int i = 0; i < n; ++i) {
            auto [left1, right1] = expand(s, i, i);
            if (right1 - left1 >= maxR - maxL) {
                maxL = left1;
                maxR = right1;
            }

            auto [left2, right2] = expand(s, i, i + 1);
            if (right2 - left2 >= maxR - maxL) {
                maxL = left2;
                maxR = right2;
            }
        }
        return s.substr(maxL, maxR - maxL + 1);
    }
};
