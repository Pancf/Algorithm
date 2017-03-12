/*
 * 题：写一个函数，求两个整数之和，要求在函数体内不得使用+、-、／、*四则运算
 * 符号
 */
class solution{
	public:
		/*
		 * 题目要求不能使用四则运算符号，那么就要考虑位运算了
		 * 通过观察可知num1&num2的结果中1所在的位置表示两个二进制数相加有进
		 * 位的地方
		 * num1^num2的结果中1所在位置表示二进制数正常相加的地方
		 * for example: 0111+1001=10000,0111&1001=0001,0111^1001=1110
		 * 显然最低位的1就是有进位的位置，另外三个位置正常相加
		 * 所以0111+1001等价于1110+0001<<1=1110+0010
		 * 由此可得：
		 *		1）若当前表示进位的数字num2不为0，那么num1等于num1和num2异或
		 *		   num2=num1和num2相与然后再左移1位
		 *		2）如果num2不为0，重复1），直至num2==0，此时返回num1
		 */
		int Add(int num1, int num2){
			while(num2){
				int tmp=num1&num2;
				num1^=num2;
				num2=tmp<<1;
			}
			return num1;
		}
}
//还有一种更简洁但是使用了递归的版本
class solution{
	public:
		int Add(int num1, int num2){
			return num2?Add(num1^num2,(num1&num2)<<1):num1;
		}
}
