/*
 * 从上往下打印出二叉树的每个节点，同层结点从左到右打印
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
		vector<int> PrintFromTopToBottom(TreeNode* root){
			//借助一个队列来实现
			queue<TreeNode*> q;
			vector<int> result;
			//判断根节点是否为空，如果为空则返回一个空vector
			if(!root)
				return res;
			q.push(root);
			while(!q.empty()){
				TreeNode* tmp=q.front();
				q.pop();
				result.push_back(tmp->val);
				//在左右子结点进队列前判断，非空的子结点才能进队列
				if(tmp->left)
					q.push(tmp->left);
				if(tmp->right)
					q.push(tmp->right);
			}
			return result;
		}
}
