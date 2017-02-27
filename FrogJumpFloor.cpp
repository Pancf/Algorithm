/*
 *题：一只青蛙一次可以跳上一级台阶，也可以跳上两级。求该青蛙跳上一个n级台阶
 *总共有多少种跳法？
 *假设跳上n级台阶总共有f(n)种跳法，那么最后一步要么是跳一级，要么是跳两级
 *也就是说f(n)=f(n-1)+f(n-2)，跳上n级台阶的跳法等于跳上n-1级台阶的跳法加上
 *跳上n-2级台阶的跳法，由此可得一种递归的解法，而递归的出口就是跳上一级台阶
 *只有一种跳法，跳上两级台阶有两种跳法
 */

class solution{
public:
	int jumpFloor(int number){
		if(number<=0)
			return -1;
		else if(number==1)
			return 1;
		else if(number==2)
			return 2;
		else
			return jumpFloor(n-2)+jumpFloor(n-1);
	}
}

/*
 *当n数值比较大时，递归的做法比较耗时，因此考虑用迭代的办法优化
 */

class solution{
public:
	int jumpFloor(int number){
		//跳一级或者两级台阶的跳法
		if(number==1||number==2)
			return number;
		int jumpSum=0;       //当前台阶的跳法总数
		//当前台阶往前退一级的跳法数(初始为两级台阶的跳法数)
		int jumpBackStep1=2; 
		//当前台阶往前退两级的跳法数(初始为一级台阶的跳法数)
		int jumpBackStep2=1;
		for(int i=3;i<=number;i++){
			jumpSum=jumpBackStep1+jumpBackStep2;
			jumpBackStep2=jumpBackStep1;//后退一级下次迭代时变成后退两级
			jumpBackStep1=jumpSum;//当前台阶下次迭代时变成后退一级
		}
		return jumpSum;
	}	
}
