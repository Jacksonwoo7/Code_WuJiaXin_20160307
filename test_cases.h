#ifndef _H_TEST_CASES_H
#define _H_TEST_CASES_H

#include "print_shopping_list.h"
#include "commodity.h"
#include "print_shopping_list.h"
#include "discount_strategy.h"
#include "bar_code_control.h"

void preparedTestData(vector<string>& shopping_list_input)
{
	shopping_list_input.push_back("ITEM000001");
	shopping_list_input.push_back("ITEM000001");
	shopping_list_input.push_back("ITEM000001");
	shopping_list_input.push_back("ITEM000001");
	shopping_list_input.push_back("ITEM000001");
	shopping_list_input.push_back("ITEM000003-2");
	shopping_list_input.push_back("ITEM000005");
	shopping_list_input.push_back("ITEM000005");
	shopping_list_input.push_back("ITEM000005");
}

void recoverDiscountTrategy()
{
	discountControl discount_instance = discountControl::getInstance();
	discount_instance.addCommodityBarCodeInto5PecentOffList("ITEM000003");
	discount_instance.addCommodityBarCodeIntoBuy2Get1FreeList("ITEM000001");
	discount_instance.addCommodityBarCodeIntoBuy2Get1FreeList("ITEM000005");
}

 /*
	*func: the test case which just have buy 2 get 1 free goods;
	*/
void justHaveBuy2Get1FreeCommodity()
{
	vector<commodity> commodity_list;
	vector<string> shopping_list_input;
	preparedTestData(shopping_list_input);
	discountControl discount_instance = discountControl::getInstance();

	discount_instance.removeCommodityBarCodeFrom5PecentOffList("ITEM000003");//apple don't discount

	getCommodityList(commodity_list, shopping_list_input);

	cout<<"when just has buy 2 get 1 free commodities, the shopping list is as follows:"<<endl;

	cout<<endl;
	printShoppingList(commodity_list);

	recoverDiscountTrategy();
	cout<<endl;
	cout<<endl;
}

 /*
	*func: the test case which no discount for all goods;
	*/
void noDiscountForAllCommodity()
{
	vector<commodity> commodity_list;
	vector<string> shopping_list_input;
	preparedTestData(shopping_list_input);
	discountControl discount_instance = discountControl::getInstance();

	discount_instance.removeCommodityBarCodeFrom5PecentOffList("ITEM000003");//apple don't discount
	discount_instance.removeCommodityBarCodeFromBuy2Get1FreeList("ITEM000001");
	discount_instance.removeCommodityBarCodeFromBuy2Get1FreeList("ITEM000005");

	getCommodityList(commodity_list, shopping_list_input);

	cout<<"when no discount for all commodities, the shopping list is as follows:"<<endl;

	cout<<endl;
	printShoppingList(commodity_list);

	recoverDiscountTrategy();
	cout<<endl;
	cout<<endl;
}


 /*
	*func: the test case which just have 5% off goods;
	*/
void have5PercentOffCommodity()
{
	vector<commodity> commodity_list;
	vector<string> shopping_list_input;
	preparedTestData(shopping_list_input);
	discountControl discount_instance = discountControl::getInstance();

	discount_instance.removeCommodityBarCodeFromBuy2Get1FreeList("ITEM000001");
	discount_instance.removeCommodityBarCodeFromBuy2Get1FreeList("ITEM000005");

	getCommodityList(commodity_list, shopping_list_input);

	cout<<"only have 5% off commodities, the shopping list is as follows:"<<endl;

	cout<<endl;
	printShoppingList(commodity_list);

	recoverDiscountTrategy();
	cout<<endl;
	cout<<endl;
}


 /*
	*func: the test case which have 5% off goods, also have buy 2 get 1 free goods;;
	*/
void have5PercentOffAndBuy2Get1FreeCommodity()
{
	vector<commodity> commodity_list;
	vector<string> shopping_list_input;
	preparedTestData(shopping_list_input);
	shopping_list_input.push_back("ITEM000001");
	discountControl discount_instance = discountControl::getInstance();

	getCommodityList(commodity_list, shopping_list_input);

	cout<<"have 5% off and buy 2 get 1 free commodities, the shopping list is as follows:"<<endl;

	cout<<endl;
	printShoppingList(commodity_list);

	cout<<endl;
	cout<<endl;
}


#endif