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
	bool isPalindrome(ListNode* head) {
		if (head->next == nullptr) return true;
		if (head->next->next == nullptr) return head->val == head->next->val;

		ListNode *initHead = head;
		ListNode *slower = head->next, *faster = head->next->next;

		while (faster != nullptr && faster->next != nullptr)
		{
			slower = slower->next;
			faster = faster->next->next;
		}
		if (faster) slower = slower->next;

		ListNode *reverse = nullptr;
		while (slower != nullptr)
		{
			ListNode *next = slower->next;
			slower->next = reverse;
			reverse = slower;
			slower = next;
		}

		while (initHead != nullptr && reverse != nullptr)
		{
			if (initHead->val != reverse->val) return false;
			initHead = initHead->next;
			reverse = reverse->next;
		}

		return true;
	}
};