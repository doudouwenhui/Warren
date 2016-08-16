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
