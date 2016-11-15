/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 *You must do this in-place without altering the nodes' values.
 *
 *For example,
 *Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */
 
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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        int n=0;
        ListNode *p=head;
        while(p!=NULL){
            n++;
            p=p->next;
        }
        
        int half_point=n/2+n%2;
        p=head;
        n=1;
        while(n!=half_point){
            p=p->next;
            n++;
        }
        ListNode *second_half_old_start=p->next;
        p->next=NULL;
        p=second_half_old_start;
        ListNode *q=second_half_old_start->next;
        ListNode *r=q;
        while(q!=NULL){
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }
        second_half_old_start->next=NULL;
        q=head;
        while(p!=NULL){
            r=p->next;
            p->next=q->next;
            q->next=p;
            p=r;
            q=q->next->next;
        }
        return;
    }
};
