/*
 * 题：定义栈的数据结构，请在该类型中事先一个能够得到栈最小元素的min函数
 */

class solution{
	public:
		stack<int> dataStack,minStack;
		void push(int value){
			dataStack.push(value);
			if(minStack.empty())
				minStack.push(value);
			else if(value<minStack.top())
				minStack.push(value);
		}
		void pop(){
			if(dataStack.pop()==minStack.top()){
				dataStack.pop();
				minStack.pop();
			}
			else
				dataStack.pop();
		}
		int top(){
			return dataStack.top();
		}
		int min(){
			return minStack.top();
		}
};
