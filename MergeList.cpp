/*
 * 题：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后
 * 的链表满足单调不减规则
 * struct ListNode{
 *	int val;
 *	struct ListNode* next;
 *	ListNode(int x):val(x),next(NULL){}
 * };
 */
//递归解法
class solution{
	public:
		ListNode* Merge(ListNode* pHead1,ListNode* pHead2){
			if(!pHead1)	//若pHead1为空，则返回pHead2链表
				return pHead2;
			if(!pHead2)	//若pHead2为空，则返回pHead1链表
				return pHead1;
			ListNode* pHead=NULL;
			if(pHead1->val<=pHead2->val){	//递归
				pHead=pHead1;
				pHead->next=Merge(pHead1->next,pHead2);
			}
			else{
				pHead=pHead2;
				pHead->next=Merge(pHead1,pHead2->next);
			}
			return pHead;
		}
}

//非递归解法
class solution{
	public:
		ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
			if(!pHead1)
				return pHead2;
			if(!pHead2)
				return pHead1;
			ListNode* res=NULL;
			ListNode* cur=NULL;
			while(pHead1&&pHead2){
				if(pHead1->val<=pHead2->val){
					if(res==NULL){
						res=pHead1;
						cur=pHead1;
					}
					else{
						cur->next=pHead1;
						cur=cur->next;
					}
					pHead1=pHead1->next;
				}
				else{
					if(res==NULL){
						res=pHead2;
						cur=pHead2;
					}
					else{
						cur->next=pHead2;
						cur=cur->next;
					}
					pHead2=pHead2->next;
				}
			}
			if(!pHead1)
				cur->next=pHead2;
			else
				cur->next=pHead1;
			return res;
		}
}
