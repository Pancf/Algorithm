/*
 * 题：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路
 * 径。路径定义为从树的根节点开始往下一直到叶结点所经过的结点形成一条路径。
 * struct TreeNode{
 *	int val;
 *	struct TreeNode* left;
 *	struct TreeNode* right;
 *	TreeNode(int x):
 *		val(x), left(NULL), right(NULL){}
 * };
 */
class solution{
	public:
		//典型DFS题
		vector<vector<int>> res;	//保存结果的res
		vector<int> tmp;	//保存当前路径的临时vector
		vector<vector<int>> FindPath(TreeNode* root,int expectNumber){
			if(root)
				DFS(root,expectNumber);
			return res;
		}
		//n=给定的expectNumber-当前路径已经经过点之和
		void DFS(TreeNode* node, int n){
			//把当前的node加入路径集合
			tmp.push_back(node->val);
			//如果node左右子树都为空(即node是叶子结点)，并且n=node的值，那么
			//tmp保存的就是一条满足条件的路径，把它放进res
			if(n==node->val&&!node->left&&!node->right)
				res.push_back(tmp);
			//如果node不是叶子结点，那么递归遍历左右子树
			else{
				if(node->left)
					DFS(node->left,n-node->val);
				if(node->right)
					DFS(node->right,n-node->val);
			}
			//递归到叶子结点后，无论这条路径是否满足条件，都要回退一步
			//递归层层返回时tmp也要层层退出之前加入的点
			tmp.pop_back();
		}
};
