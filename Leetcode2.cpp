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
        ListNode* head = new ListNode(); // new ListNode works as well
        ListNode* dummy = head;
        ListNode* pNode1 = l1;
        ListNode* pNode2 = l2;
        int i1, i2, value;
        int takeover = 0;
        while( pNode1 != nullptr || pNode2 != nullptr )
        {
            dummy -> next = new ListNode(); //segmentation fault without this line!!
            dummy = dummy -> next;
            i1 = ( pNode1 != nullptr )? pNode1 -> val : 0;
            i2 = ( pNode2 != nullptr )? pNode2 -> val : 0;
            value = i1 + i2 + takeover;
            takeover = value / 10;
            (dummy -> val) = value % 10;
            if ( pNode1 != nullptr)
                pNode1 = pNode1 -> next;
            if ( pNode2 != nullptr )
                pNode2 = pNode2 -> next;
        }
        
        if ( takeover > 0 )
        {
            dummy -> next = new ListNode;
            dummy = dummy -> next;
            dummy -> val =  takeover;
        }
        
        return head -> next;
    }
};
