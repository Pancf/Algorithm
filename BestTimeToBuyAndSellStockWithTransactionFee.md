Question: Best Time To Buy and Sell Stock with Transaction Fee

Difficulty: **medium**

Description:

Your are given an array of integers `prices`, for which the `i`-th element is the price of a given stock on day `i`; and a non-negative integer `fee` representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

**Example 1:**

```
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Note:**

`0 < prices.length <= 50000`.

`0 < prices[i] < 50000`.

`0 <= fee < 50000`.



Analysis:

在第i ($i\in[0, n-1]$)天，在最大可交易次数为k的情况下，令最大收益为P(i)(k)。

如果这一天持有股票，设为P(i)(k)(1)，则P(i)(k)(1) = max(P(i-1)(k)(1), P(i-1)(k)(0) - prices[i])。

如果这一天不持有股票，设为P(i)(k)(0)，则P(i)(k)(0) = max(P(i-1)(k)(0), P(i-1)(k-1)(1) + prices[i])。

具体到这个问题就是求当k=+$\infty$，P(n-1)($+\infty$)(0)。

当k=+$\infty$，P(i-1)(k-1)(1) = P(i-1)(k)(1)。

所以P(i)(k)(0) = max(P(i-1)(k)(0), P(i-1)(k)(1) + prices[i])。

通过两个递推关系可以知道，问题可以分解为子问题自底向上解决，而且第i 天的结果只依赖于第i-1 天，

所以不同于一般的DP问题需要数组来保存结果以便回溯，这里的空间复杂度只需要O(1)。



Solution：

```c
int maxProfit(int* prices, int pricesSize, int fee) {
#ifndef max(x, y)
#define max(x, y) ((x) > (y) ? (x) : (y))
#endif
	int cash = 0;  //P(0)(k)(0)
	int hold = -prices[0];  //P(0)(k)(1)
	for (int i = 1; i < pricesSize; ++i) {
        /*
         *Update: leetcode看到一种不需要cache cash_old的解释。
         *在等式P(i)(k)(0)=max(P(i-1)(k)(0), P(i-1)(k)(1)+prices[i])中会出现两种情况。
         *1）P(i-1)(k)(0) > P(i-1)(k)(1)+prices[i]，此时P(i)(k)(0)=P(i-1)(k)(0)。
         *  那么P(i)(k)(1) = max(P(i-1)(k)(1), P(i-1)(k)(0)-prices[i])与
         *     P(i)(k)(1) = max(P(i-1)(k)(1), P(i)(k)(0)-prices[i])没有差别。
         *2）P(i)(k)(0)=P(i-1)(k)(1)+prices[i] > P(i-1)(k)(0)。
         *  此时P(i-1)(k)(1)=P(i)(k)(0)-prices[i] > P(i-1)(k)(0)-prices[i]。
         *  那么P(i)(k)(1) = max(P(i-1)(k)(1), P(i-1)(k)(0)-prices[i])
         *                = max(P(i-1)(k)(1), P(i)(k)(0)-prices[i])
         *                = P(i-1)(k)(1)
         *综合以上两种情况的分析，可以知道没必要对cash_old 进行cache。
         */
        int cash_old;
        //P(i)(k)(0) = max(P(i-1)(k)(0), P(i-1)(k)(1)+prices[i]-fee).
    	cash = max(cash, prices[i] + hold - fee);
        //P(i)(k)(1) = max(P(i-1)(k)(1), P(i-1)(k)(0)-prices[i]).
    	hold = max(hold, cash_old - prices[i]);
	}
	return cash;
}
```