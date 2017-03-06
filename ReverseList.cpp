/*
 * 题：输入一个链表，反转链表后，输出链表的所有元素
 * struct ListNode{
 *	int val;
 *	struct ListNode* next;
 *	ListNode(int x):val(x), next(NULL){}
 * };
 */
class solution{
	public:
		ListNode* ReverseList(ListNode* pHead){
			if(pHead==NULL)
				return NULL;
			ListNode* ptr1=pHead->next;		//辅助指针ptr1和ptr2
			ListNode* ptr2=pHead->next;
			pHead->next=NULL;
			while(ptr1!=NULL){
				ptr2=ptr1->next;	//ptr2领先ptr1一个位置，领先pHead两个
				ptr1->next=pHead;	//ptr1->next指向ptr1前面的一个结点
				pHead=ptr1;	//pHead完成记录前一个结点的任务后往后移一个位置
				ptr1=ptr2;	//ptr1往后移一个位置，此时ptr1和ptr2在同一结点
			}
			return pHead;
		}
};
