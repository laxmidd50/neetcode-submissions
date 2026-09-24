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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curNode = nullptr;
        ListNode* prevNode = nullptr;

        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 == nullptr)
            {
                curNode = list2;
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                curNode = list1;
                list1 = list1->next;
            }
            else if (list1->val <= list2->val)
            {
                curNode = list1;
                list1 = list1->next;
            }
            else
            {
                curNode = list2;
                list2 = list2->next;
            }

            if (head == nullptr)
                head = curNode;
            if (prevNode != nullptr)
                prevNode->next = curNode;
            prevNode = curNode;
        }

        if (curNode != nullptr)
            curNode->next = nullptr;
        return head;
    }
};
