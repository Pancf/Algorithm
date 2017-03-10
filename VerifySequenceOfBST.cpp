/*
 * 题：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes，否则输出No。假设输出的数组的任意两个数字都互不相同。
 */
class solution{
	public:
		bool VerifySequenceOfBST(vector<int> sequence){
			/*
			 * 如果sequence是一棵二叉搜索树的后序遍历序列，则最后一个数字是
			 * 根节点，前面的数字可以分成前半部分和后半部分，分别为左子树和
			 * 右子树上的结点，由二叉搜索树的性质可知前半部分都小于根节点，
			 * 后半部分都大于根节点。所以可以采用递归的方法，判断序列是否满
			 * 足这个性质
			 */
			if(sequence.empty())
				return false;
			return judge(sequence,0,sequence.size()-1);
		}
		bool judge(vector<int> a,int first,int last){
			//如果能一直递归到first>=last的时候，说明该序列是二叉搜索树的后
			//序遍历
			if(last<=first)
				return true;
			int i=last;
			/*
			 * while循环要先判断i>first，避免a[i-1]数组访问越界
			 * 该循环做的事是找到前半部分和后半部分的分界节点，结束循环时
			 * a[i]>a[last],a[i-1]<a[last]
			 */
			while(i>first&&a[i-1]>a[last])
				--i;
			//验证0～i-1之间的数字都小于根节点a[last]
			for(int j=i-1;j>=first;--j)
				if(a[j]>a[last])
					return false;
			/*
			 * 递归验证前半部分和后半部分(因为前半部分和后半部分也是二叉搜索
			 * 树)
			 */
			return judge(a,first,i-1)&&judge(a,i,last-1);
		}
};
//非递归解法
class solution{
	public:
		bool VerifySequenceOfBST(vector<int> sequence){
			/*
			 * 由二叉搜索树的性质可知左子树的数字< 根节点数字< 右子树的数字
			 * 可以验证整个序列是否满足这个性质，若满足则是二叉搜索树
			 */
			if(sequence.empty())
				return false;
			int size=sequence.size(),i=0;
			while(--size){
				while(sequence[i++]<sequence[size]);
				while(sequence[i++]>sequence[size]);
				if(i<size)
					return false;
				i=0;
			}
			return true;
		}
};
/*
 * 事实上非递归解法是我在论坛上看到的别人的解法，但对于这个解法我持怀疑态度
 * 因为比如一棵非二叉搜索树		8	的后序遍历序列为1,3,2,5,7,6,8
 *							   / \
 *						     2    6
 *						    / \  / \
 *						   1  3 5   7
 * 该序列同样能通过非递归算法最后返回true，而该树并不是二叉搜索树，而且该后
 * 序遍历序列似乎也不能建成一棵二叉搜索树
 * PS:我发现可以建成二叉搜索树了		8
 *									   /
 *									  6
 *									 / \
 *									5   7
 *								   /
 *								  2
 *								 / \
 *								1   3
 * 所以非递归解法看起来是正确的，满足该算法的可以建成一棵二叉搜索树
 */
