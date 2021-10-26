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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* copy1 = l1;
        ListNode* copy2 = l2;
        ListNode* ans = new ListNode; // new ListNode() works as well
        ListNode* result = ans;
        int carry = 0;
        
        while( copy1 != nullptr || copy2 != nullptr )
        {
            if( copy1 != nullptr )
            {
                carry += copy1 -> val;
                copy1 = copy1 -> next;
            }
            if( copy2 != nullptr )
            {
                carry += copy2 -> val;
                copy2 = copy2 -> next;
            }
            
            result -> next  = new ListNode( carry % 10 );
            result = result -> next;
            carry = carry / 10;
            
        }
        if ( carry > 0 )
        {
            result -> next = new ListNode( carry );
            result = result -> next;
        }
        return ans -> next;
 
    }
};
