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
        unordered_set<ListNode *> nodeset;

        ListNode * curNode = head;
        while (curNode != nullptr)
        {
            if (nodeset.find(curNode) != nodeset.end())
                return true;
            nodeset.insert(curNode);
            curNode = curNode->next;
        }
        return false;
    }
};
