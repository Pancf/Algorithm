/*题：给定一个double类型的浮点数base和int类型的证书exponent，求base的
 *exponent次方
 *
 *值得注意的是exponent可能为正也可能为负，因此要分类处理
 */

class solution{
public:
	double Power(double base, int exponent){
		double ret=1;
		for(int i=0;i<abs(exponent);i++){
			ret*=base;
		}
		if(exponent<0)
			ret=1/ret;
		return ret;
	}	
}
