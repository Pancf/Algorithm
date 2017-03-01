/*
 * 把一个数组最开始的若干元素搬到数组的末尾，我们称之为数组的旋转
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1
 * NOTE:给出的所有元素都大于0，若数组大小为0，请返回0
 * 其实就是找出数组中最小值的遍体
 */
//暴力遍历法，数据量少的时候还可以，简单粗暴
class solution{
	public:
		int minNumberInRotateArray(vector<int> rotateArray){
			if(rotateArray.size()==0)
				return 0;
			int minimum=rotateArray[0];
			for(int i=1;i<rotateArray.size();i++)
				if(minimum>rotateArray[i])
					minimum=rotateArray[i];
			return minimum;
		}
}

//二分法
class solution{
	public:
		int minNumberInRotateArray(vector<int> rotateArray){
			if(rotateArray.size()==0)
				return 0;
			int head=0,tail=rotateArray.size()-1,mid=(head+tail)/2;
			//没有旋转的情况，或者说旋转后和原数组一样的情况
			if(rotateArray[head]<rotateArray[tail])
				return rotateArray[head];
			while(rotateArray[head]>=rotateArray[tail]){
				if(tail-head==1){
					mid=tail;
					break;
				}
				if(rotateArray[mid]>=rotateArray[head])
					head=mid;
				else if(rotateArray[mid]<rotateArray[tail])
					tail=mid;
				mid=(head+tail)/2;
			}
			return rotateArray[mid];
		}
}
