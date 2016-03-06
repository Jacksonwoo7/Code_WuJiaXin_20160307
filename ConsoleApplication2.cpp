// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test_cases.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	justHaveBuy2Get1FreeCommodity();//test case1
	noDiscountForAllCommodity();//test case2
	have5PercentOffCommodity();//test case3
	have5PercentOffAndBuy2Get1FreeCommodity();//test case4

	cout<<"please finish the process. "<<endl;
	string s;
	do
	{
		cin>>s;
	}
	while(s != "finish");

	return 0;
}

 