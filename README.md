# Warren
//题目描述 有股神吗？
//有，小赛就是！ 
//经过严密的计算，小赛买了一支股票，他知道从他买股票的那天开始，股票会有以下变化：
//第一天不变，以后涨一天，跌一天，涨两天，跌一天，涨三天，跌一天...依此类推。 
//为方便计算，假设每次涨和跌皆为1，股票初始单价也为1，请计算买股票的第n天每股股票值多少钱？
//输入
//输入包括多组数据；
//每行输入一个n，1<=n<=10^9 。
//样例输入
//1
//2
//3
//4
//5
//输出
//请输出他每股股票多少钱，对于每组数据，输出一行。
//样例输出
//1
//2
//1
//2
//3
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int main()
{
	vector<long long> nSet;//input days
	vector<long long> rSet;//output results
	long long n, m, r, x;//

	while (cin >> n)//input
	{
	  if (n > 0)
		  nSet.push_back(n);
		else 
		  continue;
	}

	if (nSet.size()>0)//
	{

		for (int i = 0; i<nSet.size(); i++)
		{

			n = nSet[i];
			m = ceil((1 + sqrtl((long double)(1 + 8 * n))) / 2) - 1;//第几组涨跌
			x = ((long long)(((1 + sqrtl((long double)(1 + 8 * n))) / 2 - m) * m)) % m;//第m组涨跌的第几个涨，0表示跌

			if (m == 1)
			{
				r = 1;
			}
			if (x == 0)//恰好一个涨跌结束，当前为跌的那一天
				r = (m - 1)*(m - 2) / 2 + 1;
			else//第m个涨跌的第x涨的天数
				r = (m - 2)*(m - 3) / 2 + 1 + x;

			rSet.push_back(r);

		}
		for (int i = 0; i<rSet.size(); i++)//输出
			cout << rSet[i] << endl;
	}

	return 0;

}

//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	long long n,s;
//	vector<long long> nSet,rSet;
//
//	while (cin >> n){
//		nSet.push_back(n);
//	}
//	long long i,j;
//	for (i = 0; i < nSet.size(); i++)
//	{
//		n = nSet[i];
//		if (n == 1) rSet.push_back(1);
//		if (n == 2) rSet.push_back(2);
//		if (n == 3) rSet.push_back(1);
//		if (n > 3)
//		{
//			for (j = 1; j <= n; j++)
//			{
//				s = j + j*(j - 1) / 2;
//				if (s == n){ break; }
//				if (s > n){ j = j - 1; break; }
//			}
//
//			rSet.push_back(n - 2 * (j - 1));
//		}
//	}
//	for (int i = 0; i<rSet.size(); i++)
//	{
//		cout << rSet[i] << endl;
//	}
//	
//	return 0;
//}
