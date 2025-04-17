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
        ListNode *cur1=l1,*cur2=l2,*cur=NULL,*head=NULL;
        int carry=0;
        while(cur1 && cur2){
            int num=cur1->val+cur2->val+carry;
            cur1=cur1->next;
            cur2=cur2->next;
            if(num>9){
                carry=1;
                num=num%10;
            }
            else{
                carry=0;
            }
            ListNode *t=new ListNode(num);
            if(!cur){
                cur=t;
                head=cur;
            }
            else{
                cur->next=t;
                cur=cur->next;
            }
        }
        while(cur1){
            int num=cur1->val+carry;
            cur1=cur1->next;
            if(num>9){
                num=num%10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode *t=new ListNode(num);
            if(!cur){
                cur=t;
            }
            else{
                cur->next=t;
            }
            cur=cur->next;
        }
        while(cur2){
            int num=cur2->val+carry;
            cur2=cur2->next;
            if(num>9){
                num=num%10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode *t=new ListNode(num);
            if(!cur){
                cur=t;
            }
            else{
                cur->next=t;
            }
            cur=cur->next;
        }
        if(carry>0){
            ListNode *t=new ListNode(1);
            cur->next=t;
        }
        return head;
    }
};