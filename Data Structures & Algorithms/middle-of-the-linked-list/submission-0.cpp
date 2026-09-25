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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        ListNode* cur = head;

        bool incrementMiddle = false;
        while (cur != nullptr)
        {
            cur = cur->next;
            if (incrementMiddle)
                mid = mid->next;
            incrementMiddle = !incrementMiddle;
        }
        return mid;
    }
};