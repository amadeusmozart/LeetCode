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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        carry = (carry + l1->val + l2->val);
        ListNode * res = new ListNode(carry % 10);
        carry = carry / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode * temp = res;
        while(l1 != NULL && l2 != NULL)
        {
            carry = (carry + l1->val + l2->val);
            res->next = new ListNode(carry % 10);
            res = res->next;
            carry = carry / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            carry = (carry + l1->val);
            res->next = new ListNode(carry % 10);
            res = res->next;
            carry = carry / 10;
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            carry = (carry + l2->val);
            res->next = new ListNode(carry % 10);
            res = res->next;
            carry = carry / 10;
            l2 = l2->next;
        }
        
        if(carry != 0)
            res->next = new ListNode(carry);
        
        return temp;
    }
};
