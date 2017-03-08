/*
 * 题：操作给定的二叉树，将其变换为源二叉树的镜像
 * 二叉树的镜像定义：源二叉树			镜像二叉树
 *					8                       8
 *				  /   \                    / \
 *				 6    10                 10   6
 *			    / \  /  \               / \  / \
 *			   5  7 9    11            11  9 7  5
 * struct TreeNode{
 *	int val;
 *	struct TreeNode* left;
 *	struct TreeNode* right;
 *	TreeNode(int x):
 *		val(x), left(NULL),right(NULL){}
 * };
 */
class solution{
	public:
		//递归解法
		void Mirror(TreeNode* pRoot){
			if(!pRoot)
				return;
			//反转左右子结点
			TreeNode* p=pRoot->left;
			pRoot->left=pRoot->right;
			pRoot->right=p;
			//递归反转左右子树
			Mirror(pRoot->left);
			Mirror(pRoot->right);
		}
};

class solution{
	public:
		void Mirror(TreeNode* pRoot){
			if(!pRoot)
				return;
			stack<TreeNode*> nodeStack;
			nodeStack.push(pRoot);	//根结点进栈
			while(!nodeStack.empty()){
				TreeNode* p=nodeStack.top();	//获取栈顶元素，然后pop
				nodeStack.pop();
				//如果当前结点的左右子树不全为空，则反转
				//可以避免处理叶子结点的开销
				if(p->left||p->right){
					TreeNode* tmp=p->left;
					p->left=p->right;
					p->right=tmp;
				}
				//叶子结点不需要反转
				if(p->left)
					nodeStack.push(p->left);
				if(p->right)
					nodeStack.push(p->right);
			}
		}
}
