/*
 * 题：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入
 * 的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
 * {1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
 *
 * Definiion of binary tree
 * struct TreeNode{
 *	int val;
 *	TreeNode* left;
 *	TreeNode* right;
 *	TreeNode(int x):val(x), left(NULL), right(NULL){}
 * };
 */
class solution{
	public:
		TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin){
		/*
		 * 前序遍历的第一个结点肯定是树的根节点，通过中序遍历找出根节点所在
		 * 位置，根节点左边的中序遍历序列就是根节点左子树的中序遍历序列，右
		 * 边的就是右子树的中序遍历序列，而通过左子树的中序遍历序列又可以在
		 * 前序遍历中找出左子树的前序遍历序列，通过右子树的中序遍历序列可以
		 * 在前序遍历序列中找出右子树的前序遍历序列。至此，问题就是一个递归
		 * 问题了，分成左右子树分别递归即可
		 */
			if(pre.size()==0||vin.size()==0)	//退出递归的条件
				return NULL;
			vector<int> pre_left,pre_right,vin_left,vin_right;
			TreeNode* head=new TreeNode(pre[0]);//根节点肯定是前序遍历第一个
			int index=0;
			for(int i=0;i<vin.size();i++){
				if(vin[i]==pre[0]){
					index=i;
					break;
				}
			}
			for(int i=0;i<index;i++){	//构建左子树的前序遍历和中序遍历
				vin_left.push_back(vin[i]);
				pre_left.push_back(pre[i+1]);
			}
			for(int i=index+1;i<vin.size();i++){	//右子树
				vin_right.push_back(vin[i]);
				pre_right.push_back(pre[i]);
			}
			head->left=reConstructBinaryTree(pre_left,vin_left)
			head->right=reConstructBinaryTree(pre_right,vin_right);
			return head;
		}
}
