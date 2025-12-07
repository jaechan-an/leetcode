#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
   public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* prev = nullptr;
        int passed = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int val1 = 0;
            int val2 = 0;

            if (l1 != nullptr) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                val2 = l2->val;
                l2 = l2->next;
            }

            int sum = val1 + val2 + passed;
            passed = 0;

            if (sum >= 10) {
                passed = sum / 10;
            }

            ListNode* newNode = new ListNode(sum % 10);
            if (result == nullptr) {
                result = newNode;
            }
            if (prev != nullptr) {
                prev->next = newNode;
            }
            prev = newNode;
        }

        if (passed > 0) {
            ListNode* newNode = new ListNode(passed);
            prev->next = newNode;
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    ListNode* result = sol.addTwoNumbers(l1, l2);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
