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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(-1);
        ListNode* odd = oddHead;
        ListNode* evenHead = new ListNode(-1);
        ListNode* even = evenHead;
        while (head) {
            odd->next = head;
            odd = odd->next;
            even->next = head->next;
            even = even->next;
            if (head->next) {
                ListNode* temp = head->next->next;
                head->next = NULL;
                head = temp;
            } else {
                head = head->next;
            }
        }

        oddHead = oddHead->next;
        evenHead = evenHead->next;
        odd->next = evenHead;
        return oddHead;
    }
};