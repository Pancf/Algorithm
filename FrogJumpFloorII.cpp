/*
 * 题：一只青蛙一次可以跳上1级台阶，也可以跳上2级...它也可以跳上n级。求该
 * 青蛙跳上一个n级的台阶总共有多少种跳法
 * 设f(n)为跳上n级台阶的跳法，则青蛙最后一步可以是从第n-1级台阶跳上来，也可
 * 以从n-2级台阶跳上来，也可从第0级台阶跳上来（即一步跳n级），则有：
 * f(n)=f(n-1)+f(n-2)+...+f(1)+f(0)
 * f(n-1)=f(n-2)+...+f(1)+f(0)
 * ...
 * f(1)=1
 * f(0)=0
 * f(n)=2*f(n-1)=2^(n-1)*f(1)
 */
class solution{
	public:
		int jumpFloorII(int number){
			return std::pow(2,number-1);
		}
}
另还有一种位操作法：
class solution{
	public:
		int jumpFloorII(int number){
			return 1<<(--number);
		}
}
