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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a--, b++;
        ListNode *l1 = list1;
        ListNode *l2 = l1;
        while(a>0 || b>0) {
            if(a>0) {
                l1 = l1->next;
                a--;
            }
            if(b>0) {
                l2 = l2->next;
                b--;
            }
        }
        l1->next = list2;
        while(l1->next != NULL) {
            l1 = l1->next;
        }
        l1->next = l2;
        return list1;
    }
};