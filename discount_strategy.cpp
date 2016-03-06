#include "stdafx.h"
#include "discount_strategy.h"

discountControl::discountControl()
{
	addCommodityBarCodeIntoBuy2Get1FreeList("ITEM000005");
}

discountControl discountControl::getInstance()
{
	static discountControl instance;
	return instance;
}

DISCOUNTTYPE discountControl::getDiscountType(string commodity_bar_code)
{
	bool is_buy_2_get_1_free_commodity = false;
	bool is_5_percent_free_commodity = false;

	vector<string>::iterator itor1 = std::find(five_percent_off_list.begin(), five_percent_off_list.end(),commodity_bar_code);
	vector<string>::iterator itor2 = std::find(buy_2_get_1_free_list.begin(), buy_2_get_1_free_list.end(),commodity_bar_code);
	
	is_5_percent_free_commodity = (itor1 != five_percent_off_list.end());

	is_buy_2_get_1_free_commodity = (itor2 != buy_2_get_1_free_list.end());

	if(is_5_percent_free_commodity)
	{
		if(is_buy_2_get_1_free_commodity)
			return BuyTwoGetOneFree;
		else 
			return DiscountForEach;
	}
	else if(is_buy_2_get_1_free_commodity)
	{
		return BuyTwoGetOneFree;
	}
	else
	{
		return NoDiscount;
	}
}

void  discountControl::addCommodityBarCodeIntoBuy2Get1FreeList(const string& commodity_bar_code)
{
	vector<string>::iterator itor = std::find(buy_2_get_1_free_list.begin(), buy_2_get_1_free_list.end(),commodity_bar_code);

	if(itor == buy_2_get_1_free_list.end())
	{
		buy_2_get_1_free_list.push_back(commodity_bar_code);
	}
	/*else
	{
		cout<<"this commodity has existed in the discount list."<<endl;
	}*/
}

void  discountControl::removeCommodityBarCodeFromBuy2Get1FreeList(const string& commodity_bar_code)
{
	vector<string>::iterator itor = std::find(buy_2_get_1_free_list.begin(), buy_2_get_1_free_list.end(),commodity_bar_code);

	if(itor != buy_2_get_1_free_list.end())
		buy_2_get_1_free_list.erase(itor);
}

void  discountControl::addCommodityBarCodeInto5PecentOffList(const string& commodity_bar_code)
{
	vector<string>::iterator itor = std::find(five_percent_off_list.begin(), five_percent_off_list.end(),commodity_bar_code);

	if(itor == five_percent_off_list.end())
	{
		five_percent_off_list.push_back(commodity_bar_code);
	}
	/*else
	{
		cout<<"this commodity has existed in the discount list."<<endl;
	}*/
}

void  discountControl::removeCommodityBarCodeFrom5PecentOffList(const string& commodity_bar_code)
{
	vector<string>::iterator itor = std::find(five_percent_off_list.begin(), five_percent_off_list.end(),commodity_bar_code);

	if(itor != five_percent_off_list.end())
		five_percent_off_list.erase(itor);
}

vector<string>  discountControl::buy_2_get_1_free_list(1,"ITEM000001");
vector<string>  discountControl::five_percent_off_list(1,"ITEM000003");





discountBehavior::discountBehavior(double commodity_number, double price)
	:db_commodity_number(commodity_number), db_price(price)
{
}


discountBehavior::~discountBehavior()
{};

discount_benifit discountBehavior::getCustomerBenifit()
{
	discount_benifit clientBenifit = {};
	clientBenifit.free_num = 0;
	clientBenifit.saved_money = 0;
	return clientBenifit;
}

buyTwoGetOneFree::buyTwoGetOneFree(unsigned int commodity_number, double price)
	:discountBehavior(commodity_number, price)
{
}


discount_benifit buyTwoGetOneFree::getCustomerBenifit()
{
	discount_benifit clientBenifit = {};
	clientBenifit.free_num = db_commodity_number/3;
	clientBenifit.saved_money = clientBenifit.free_num * db_price;
	return clientBenifit;
}


noDiscount::noDiscount(double commodity_number, double price)
	:discountBehavior(commodity_number, price)
{
}




xPecentOff::xPecentOff(double commodity_number, double price)
	:discountBehavior(commodity_number, price)
{
};


discount_benifit xPecentOff::getCustomerBenifit()
{
	discount_benifit clientBenifit = {};
	clientBenifit.free_num = 0;
	clientBenifit.saved_money = db_commodity_number * db_price * discout_percent/100;
	return clientBenifit;
}

void xPecentOff::setDiscountPercent(double percentoff)
{
	discout_percent = percentoff;
}
double xPecentOff::discout_percent = 5.0;