/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 *If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 *You may not alter the values in the nodes, only nodes itself may be changed.
 *
 *Only constant memory is allowed.
 *
 *For example,
 *Given this linked list: 1->2->3->4->5
 *
 *For k = 2, you should return: 2->1->4->3->5
 *
 *For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2)
            return head;
        ListNode *p=head;
        int cnt=0;
        while(p!=NULL){
            cnt++;
            if(cnt==k){
                ListNode *q=head->next;
                head->next=reverseKGroup(p->next,k);
                for(int i=1;i<k;i++){
                    ListNode *temp=q->next;
                    q->next=head;
                    head=q;
                    q=temp;
                }
                break;
            }
            p=p->next;
        }
        return cnt==k?p:head;
    }
};
