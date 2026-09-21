#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, int> tmp;
        for (const auto c : s) {
            ++tmp[c];
        }
    }
};
