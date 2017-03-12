/*
 * 题：求1+2+...+n，要求不能使用乘除法、for、while、if、else、switch、case等
 * 关键字及条件判断语句（A？B：C）
 */
class solution{
	public:
		int Sum_Solution(int n){
			/*
			 * 因为1+2+...+n=n(n+1)/2，这里把乘法用位操作写出来
			 * a*b(a>b,这样可以让循环次数少一点)等价于
			 * res=0;
			 * while(b){             b=b0*2^0+b1*2^1+...+bn*2^n
			 *	if(b&0x1)	res+=a;  若b0=1,res=res+a
			 *	a<<=1;               a<<=1等价于a*2
			 *	b>>=1;               b>>=1等价于b/2,此时b=b1*2^0+...bn*2^n-1
			 * }
			 */
			int a=n+1,res=0;
			while(n){
				if(n&0x1)
					res+=a;
				a<<=1;
				n>>=1;
			}
			res>>=1;
			return res;
		}
}
/*
 * 还看到别人有种做法是利用了逻辑与&&的短路特性,但是这个方法的复杂度是O(n)
 * 我的方法复杂度是O(logn)，n变得很大时就会有速度的差异
 */
class solution{
	public:
		int Sum_Solution(int n){
			int res=n;
			//当递归到res=n=0时，逻辑表达式遇到前项res=0就不再计算后项
			res&&(res+=Sum_Solution(n-1));
			return res;
		}
}
