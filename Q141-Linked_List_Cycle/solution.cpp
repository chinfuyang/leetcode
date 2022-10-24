#include <vector>
#include <queue>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        std::unordered_map<ListNode *, bool> umap;
        while ( head != NULL) {

            if (umap[head]) {
                return true;
            }
            umap[head] = true;
            head = head->next;
        }

        return false;
    }

    bool hasCycle2(ListNode *head) {
        
        if (head == NULL) return false;

        ListNode *fast = head, *slow = head;

        while (fast != NULL && slow != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};