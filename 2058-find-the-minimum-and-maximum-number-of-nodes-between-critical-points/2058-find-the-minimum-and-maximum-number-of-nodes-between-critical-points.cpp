/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        while (curr->next != nullptr) {
            int x = prev->val;
            int y = curr->val;
            int z = curr->next->val;
            if ((y > x && y > z) || (y < x && y < z)) {
                if (first == -1) {
                    first = idx;
                }
                if (last != -1) {
                    minDist = min(minDist, idx - last);
                }
                last = idx;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        if (first == -1 || first == last) {
            return {-1, -1};
        }
        int maxDist = last - first;
        return {minDist, maxDist};
    }
};