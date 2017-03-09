/*
 * 题：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
 * 如果输入如下矩阵：{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
 * 1	2	3	4
 * 5	6	7	8
 * 9	10	11	12
 * 13	14	15	16
 * 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10
 */
class solution{
	public:
		vector<int> printMatrix(vector<vector<int>> matrix){
			/*
			 * 考虑记录矩阵左上角和右下角两个点的坐标，每打印一圈后将左上角
			 * 的横纵坐标都+1，右下角的横纵坐标-1，打印结束的条件就是左上角
			 * 的横纵坐标等于右下角的横纵坐标
			 */
			int row=matrix.size(),col=matrix[0].size();
			vector<int> result;	//存放结果的vector
			int left=0,top=0,right=col-1,bottom=row-1;//初始的横纵坐标
			while(left<=right&&top<=bottom){
				//最上面一行从左到右打印
				for(int i=left;i<=right;i++)
					result.push_back(matrix[top][i]);
				//从上到下打印一列
				for(int i=top+1;i<=bottom;i++)
					result.push_back(matrix[i][right]);
				//if判定避免重复打印，从右到左打印一行
				if(bottom-top>=1)
					for(int i=right-1;i>=left;i--)
						result.push_back(matrix[bottom][i]);
				//if判定避免重复打印，从下到上打印一列
				if(rigt-left>=1)
					for(int i=bottom-1;i>top;i--)
						result.push_back(matrix[i][left]);
				++left;++top;--right;--bottom;
			}
			return result;
		}
}
