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
        if (head->next == nullptr) return head;
        ListNode *slower = head, *faster = head;
        while (head != nullptr)
        {
            slower = head->next;
            faster = faster->next->next;
            if (faster == nullptr || faster->next == nullptr)
            {
                return slower;
            }
            head = head->next;
        }

        return slower;
    }
};