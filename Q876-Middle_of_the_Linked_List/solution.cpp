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
    ListNode *middleNode(ListNode *head)
    {
        int length = 0;
        ListNode *midNode = head;
        while (head != nullptr)
        {
            length++;
            head = head->next;
        }

        int mid = length / 2;
        for (int i = 0; i < mid; i++)
        {
            midNode = midNode->next;
        }

        return midNode;
    }
};