/*
 * 题：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的
 * 小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种办法？
 * +++++...n...+++++   2*n的大矩形
 * +++++...n...+++++
 * +  ++			   2*1的小矩形的两种形态
 * +
 * 通过观察可以发现这个问题等价于“走n级台阶，每次只能走1级或2级，共有多少
 * 种走法”的问题
 * 设走n级台阶的走法为f(n)，则最后一步可以是走1级也可以是走2级，所以
 * f(n)=f(n-1)+f(n-2)
 * f(1)=1,f(2)=2
 */
//递归解法
class solution{
	public:
		int rectCover(int number){
			if(number<=0)
				return 0;
			else if(number==1||number==2)
				return number;
			else
				return rectCover(number-1)+rectCover(number-2);
		}
}
//迭代解法
class solution{
	public:
	int rectCover(int number){
		if(number<=0)
			return 0;
		int rectCoverBack1=2,rectCoverBack2=1,rectCoverSum=0;
		for(int i=3;i<=number;i++){
			rectCoverSum=rectCoverBack1+rectCoverBack2;
			rectCoverBack2=rectCoverBack1;
			rectCoverBack1=rectCoverSum;
		}
		return rectCoverSum;
	}
}
