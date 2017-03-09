/*
 * 题：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为
 * 该栈的探出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的
 * 压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可
 * 能是该压栈序列的弹出序列（注意：这两个序列的长度是相等的）
 */
class solution{
	public:
		bool IsPopOrder(vector<int> pushV, vector<int> popV){
			if(pushV.empty()||popV.empty())
				return false;
			/*
			 * 设一个辅助栈s，每次压栈一个数字，判断当前栈顶是否等于出栈序列
			 * 如果等于则出栈，用while循环判断，直至栈顶数字不等于出栈序列当
			 * 前的数字
			 * 压栈序列的数字全部压完后退出for循环，判断辅助栈s，s如果为空则
			 * 说明弹出序列正确，否则弹出序列错误
			 */
			stack<int> s;
			for(int i=0,j=0;i<pushV.size();i++){
				s.push(pushV[i]);
				while(j<popV.size()&&s.top()==popV[j]){
					s.pop();
					j++;
				}
			}
			return s.empty();
		}
}
