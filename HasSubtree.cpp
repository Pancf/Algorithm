/*
 * 题：输入两棵二叉树A、B，判断B是不是A的字结构（PS：我们约定空树不是任意
 * 一棵树的子结构）
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
		bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
			//如果pRoot1或pRoot2为空树，则直接返回false
			if(!(pRoot1&&pRoot2))
				return false;
			//递归，只要其中一个条件为真，则返回true
			return isSubtree(pRoot1,pRoot2)||
				HasSubtree(pRoot1->left,pRoot2)||
				HasSubtree(pRoot1->right,pRoot2);
		}
		bool isSubtree(TreeNode* pRoot1,TreeNode* pRoot2){
			/*
			 *此处务必先判断pRoot2是否为空，因为假如B树的叶子结点刚好也是A
			 *的叶子结点，那么递归调用到最后一步时pRoot1=pRoot2=NULL，如果
			 *先判断pRoot1，那么显然会把这种情况分类错误。所以先判断pRoot2
			 *，如果pRoot2此时为NULL，那就直接返回true，如果pRoot2还不为
			 *NULL的时候，再判断pRoot1是否为NULL，为空返回false。
			 */
			if(!pRoot2)
				return true;
			if(!pRoot1)
				return false;
			//当前两棵树的结点val相等时，递归调用isSubtree
			if(pRoot1->val==pRoot2->val)
				return isSubtree(pRoot1->left,pRoot2->left)&&
					isSubtree(pRoot1->left,pRoot2->left);
			else
				return false;
		}
};
