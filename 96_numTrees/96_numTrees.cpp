// 96_numTrees.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int numTrees(int n) {
	if (n == 1)return 1;
	if (n == 2)return 2;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < i; j++)
			dp[i] += dp[j] * dp[i - 1 - j];
	}
	return dp[n];
}

int main()
{
	cout << numTrees(3);
    return 0;
}

