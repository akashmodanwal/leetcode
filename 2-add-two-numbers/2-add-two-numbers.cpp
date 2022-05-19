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
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int lastval = 0;
        while(l1 || l2){
            ListNode* t = new ListNode();
            int sum = lastval;
            if(l1){
                sum+= l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            int add = sum;
            if(sum>9){
                add = sum%10;
                lastval = 1;
            }
            else{
                lastval = 0;
            }
            temp->next = new ListNode(add);
            temp = temp->next;
            
        }
        if(lastval) temp->next = new ListNode(lastval);
        return head->next;
    }
};