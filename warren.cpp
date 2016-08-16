#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

int main()
{
	vector<long long> days;
	vector<long long> shares;
	long long day, updown, share, ups;
	
	while (cin >> day)
	{
		days.push_back(day);
	}
	
	if (days.size()>0)
	{
	
		for (int i = 0; i<days.size(); i++)
		{
	
			day = days[i];
			updown = ceil((1 + sqrtl((long double)(1 + 8 * day))) / 2) - 1;//第几组涨跌
			ups = ((long long)(((1 + sqrtl((long double)(1 + 8 * day))) / 2 - updown) * updown)) % updown;//第m组涨跌的第几个涨，0表示跌
	
	
			if (updown == 1)
			{
				share = 1;
			}
			if (ups == 0)//恰好一个涨跌结束，当前为跌的那一天
				share = (updown - 1)*(updown - 2) / 2 + 1;
			else//第updown个涨跌的第ups涨的天数
				share = (updown - 2)*(updown - 3) / 2 + 1 + ups;
	
			shares.push_back(share);
	
		}
		for (int i = 0; i<shares.size(); i++)
			cout << shares[i] << endl;
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
