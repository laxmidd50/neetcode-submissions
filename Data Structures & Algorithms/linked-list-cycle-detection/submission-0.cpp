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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode *, bool> nodemap;

        ListNode * curNode = head;
        while (curNode != nullptr)
        {
            if (nodemap[curNode] == true)
                return true;
            nodemap[curNode] = true;
            curNode = curNode->next;
        }
        return false;
    }
};
