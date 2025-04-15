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
        int len=0;
        ListNode *cur=head;
        while(cur){
            len++;
            cur=cur->next;
        }
        if(len==1 && n==1){
            return NULL;
        }
        ListNode *prev=NULL;
        cur=head;
        int cnt=0;
        while(cur){
            if(n==len-cnt){
                if(!prev){
                    head=cur->next;
                }
                else{
                    prev->next=cur->next;
                }
                break;
            }
            cnt++;
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};