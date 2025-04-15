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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        int cnt=0;
        ListNode *cur=head,*prev=NULL,*t=NULL;
        while(cur){
            cnt++;
            st.push(cur);
            cur=cur->next;
        }
        prev=head;
        cur=head->next;
        for(int i=0;i<int(cnt/2) && cur;i++){
            t=st.top();
            st.pop();
            prev->next=t;
            t->next=cur;
            prev=cur;
            cur=cur->next;
        }
        if(cnt==1) return;
        if(cnt%2==1){
            t->next=prev;
        }
        prev->next=NULL;
    }
};