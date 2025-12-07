#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        if (word1.size() == 0) {
            return word2;
        } else if (word2.size() == 0) {
            return word1;
        }

        int w1_size = word1.size();
        int w2_size = word2.size();

        int common_size = w1_size < w2_size ? w1_size : w2_size;

        const char* w1 = word1.c_str();
        const char* w2 = word2.c_str();
        char result[w1_size + w2_size + 1];

        for (int i = 0; i < common_size; ++i) {
            result[2 * i] = w1[i];
            result[2 * i + 1] = w2[i];
        }

        for (int i = common_size; i < w1_size; ++i) {
            result[common_size + i] = w1[i];
        }

        for (int i = common_size; i < w2_size; ++i) {
            result[common_size + i] = w2[i];
        }

        result[w1_size + w2_size] = '\0';

        return string(result);
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    string result1 = sol.mergeAlternately("abcdef", "ABC");
    std::cout << result1 << std::endl;

    string result2 = sol.mergeAlternately("ABC", "abcdef");
    std::cout << result2 << std::endl;

    return 0;
}
