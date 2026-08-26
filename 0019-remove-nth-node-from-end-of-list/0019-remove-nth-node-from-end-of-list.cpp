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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        // Count length
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        // If head needs to be removed
        if (n == len) {
            return head->next;
        }

        // Reach node before the one to delete
        temp = head;
        for (int i = 1; i < len - n; i++) {
            temp = temp->next;
        }

        // Delete node
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};