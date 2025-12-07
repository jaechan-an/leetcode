#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. sort the array and keep track of original indices
        vector<pair<int, int>> num_with_index;
        for (int i = 0; i < nums.size(); i++) {
            num_with_index.push_back({nums[i], i});
        }
        sort(num_with_index.begin(), num_with_index.end());

        // 2. use two pointers to find the target
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = num_with_index[left].first + num_with_index[right].first;
            if (sum == target) {
                return {num_with_index[left].second, num_with_index[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        // Should never reach here.
        return {};
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = sol.twoSum(nums, target);
    for (int idx : res) {
        cout << idx << " ";
    }
    cout << endl;

    vector<int> nums2 = {3, 2, 4};
    target = 6;
    res = sol.twoSum(nums2, target);
    for (int idx : res) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
