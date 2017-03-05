/*
 * 题：输入一个链表，输出该链表中倒数第k个结点
 * struct ListNode{
 *		int val;
 *		struct ListNode* next;
 *		ListNode(int x):
 *			val(x), next(NULL){}
 * };
 */

class solution{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
		if(pListHead==NULL||k<=0)
			return NULL;
		int sum=0;
		ListNode* ptr=pListHead;
		while(ptr){		//统计链表结点数量
			++sum;
			ptr=ptr->next;
		}
		if(k>sum)		//如果k大于链表结点数量则返回NULL
			return NULL:
		ptr=pListHead;
		for(int i=1;i<sum-k+1;i++)
			ptr=ptr->next;
		return ptr;
	}
}
