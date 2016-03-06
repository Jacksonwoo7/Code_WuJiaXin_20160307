#include "stdafx.h"
#include "commodity.h"
#include "print_shopping_list.h"
#include "discount_strategy.h"
#include "bar_code_control.h"


void printShoppingList(vector<commodity> commodity_list)
{
	
	commodity_info goods_info = {};
	commodity_info buy_2_get_1_free_information = {};
	vector<commodity_info> buy_2_get_1_free_list;

	double total_revenue_for_same_commodity = 0;
	double total_revenue_for_all_commodity = 0;
	double total_saved_money_for_all_commodity = 0;
	discount_benifit customer_discount;
	bool has_buy_2_get_1_free_commodity = false;
	bool has_discount_for_each_commodity = false;
	bool has_saved_money = false;
	

	cout<<"              **** WalMart Shopping List****       "<<endl;

	for(vector<commodity>::iterator itor = commodity_list.begin(); itor != commodity_list.end(); itor++)
	{
		itor->getCommodityInfo(goods_info);

		total_revenue_for_same_commodity = itor->getRevenueForSameCommodity();
		total_revenue_for_all_commodity += total_revenue_for_same_commodity;

		customer_discount = itor->getCostomerBenifit();

		total_saved_money_for_all_commodity += customer_discount.saved_money;

		if(customer_discount.free_num)
		{
			buy_2_get_1_free_information.name = goods_info.name;
			buy_2_get_1_free_information.number =customer_discount.free_num;
			if(customer_discount.free_num > 1)
				buy_2_get_1_free_information.unit = goods_info.unit + "s";
			else
				buy_2_get_1_free_information.unit = goods_info.unit;


			has_buy_2_get_1_free_commodity = true;
			buy_2_get_1_free_list.push_back(buy_2_get_1_free_information);
			has_saved_money = true;
		}
		
	   else if(customer_discount.saved_money != 0)
		{
			has_saved_money = true;
			has_discount_for_each_commodity = true;
		}

		if(goods_info.number > 1)
				goods_info.unit = goods_info.unit + "s";
			else
				goods_info.unit = goods_info.unit;

		cout<<"name: "<<goods_info.name<<", number:"<<goods_info.number<<" "<<goods_info.unit
			<<", price: "<<goods_info.price<<" (Yuan)"<<", sum: "<<total_revenue_for_same_commodity<<" (Yuan)";

		if(has_discount_for_each_commodity)
		{
			cout<<", saved: "<<customer_discount.saved_money;
			has_discount_for_each_commodity = false;
		}
		cout<<endl;

	}

	if(has_buy_2_get_1_free_commodity)
	{
		cout<<"----------------------"<<endl;
		cout<<"The commodities which buy 2 get 1 free are:"<<endl;

		for(vector<commodity_info>::const_iterator const_itor = buy_2_get_1_free_list.begin(); const_itor != buy_2_get_1_free_list.end(); const_itor++)
		{
			cout<<"name: "<<const_itor->name<<", number:"<<const_itor->number<<" "<<const_itor->unit<<endl;
		}
	}

	
	cout<<"----------------------"<<endl;

	cout<<"total:"<<total_revenue_for_all_commodity<<"(Yuan)"<<endl;
	if(has_saved_money == true)
	{
		cout<<"saved:"<<total_saved_money_for_all_commodity<<"(Yuan)"<<endl;
	}

	cout<<"**********************"<<endl;
}



void createShoppingListInput(vector<string>& shopping_list_input)
{
	string input_item;
	cout<<"please enter commodity's bar-code: (enter 'finish' to finish the process)"<<endl;

	cin>>input_item;
	while(input_item != "finish")
	{
		shopping_list_input.push_back(input_item);
		cin>>input_item;
	}
}


void getCommodityList(vector<commodity>& commodity_list,const vector<string>& shopping_list_input)
{
	map<string, double> commodity_with_count;
	map<string, double> commodity_with_weight;
	barCodeControl  cashier_instance = barCodeControl::getInstance();
	cashier_instance.distinguishShoppingListInput(shopping_list_input,commodity_with_count, commodity_with_weight);

	convertCommodityMapToCommodotyList(commodity_list, commodity_with_count);
	convertCommodityMapToCommodotyList(commodity_list, commodity_with_weight);
}

void convertCommodityMapToCommodotyList(vector<commodity>& commodity_list, const map<string, double>& commodity_map)
{
	discountControl discount_instance = discountControl::getInstance();
	barCodeControl  cashier_instance = barCodeControl::getInstance();
	commodity_info goods_info = {};
	DISCOUNTTYPE  discout_type = NoDiscount;

	
	for(map<string, double>::const_reverse_iterator const_itor = commodity_map.rbegin(); const_itor!= commodity_map.rend(); const_itor++)
	{
		discout_type = discount_instance.getDiscountType(const_itor->first);
		cashier_instance.getCommodityInfo(const_itor->first, goods_info);
		goods_info.number = const_itor->second;
	    commodity commodity_item(goods_info.number, goods_info.name, goods_info.price, goods_info.unit,discout_type);
		commodity_list.push_back(commodity_item);
	}
}

