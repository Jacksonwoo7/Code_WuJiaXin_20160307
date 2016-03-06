#include "stdafx.h"
#include "commodity.h"


commodity::commodity(double number, string name, double price, string unit, DISCOUNTTYPE discount_type)
	:commodity_number(number),commodity_name(name),commodity_price(price),commodity_unit(unit)
{
	switch(discount_type)
	{
	case BuyTwoGetOneFree:
		discount_strady = new buyTwoGetOneFree(number, price);
		break;
	case DiscountForEach:
		discount_strady = new xPecentOff(number, price);
		break;
	case NoDiscount:
		discount_strady = new noDiscount(number, price);
		break;
	default:
		discount_strady = new noDiscount(number, price);
		break;
	}
}


commodity::~commodity()
{
	if(discount_strady != NULL)
	{
		delete  discount_strady;
		discount_strady = NULL;
}
};

commodity::commodity(const commodity& org)
{
	commodity_number = org.commodity_number;
	commodity_name = org.commodity_name;
	commodity_price = org.commodity_price;
	commodity_unit = org.commodity_unit;
	discount_strady = new discountBehavior(commodity_number, commodity_price);
	strcpy((char*)discount_strady, (char*)org.discount_strady);
}

commodity& commodity::operator= (const commodity& rhs)
{
	commodity temp(rhs);
	std::swap(*this, temp);
	return *this;
}


void commodity::getCommodityInfo(commodity_info& goods_info)
{
	goods_info.name = commodity_name;
	goods_info.number = commodity_number;
	goods_info.price = commodity_price;
	goods_info.unit = commodity_unit;
}


double commodity::getRevenueForSameCommodity()
{
	discount_benifit costomerBenifit = discount_strady->getCustomerBenifit();
	return commodity_price * commodity_number - costomerBenifit.saved_money;
}


discount_benifit commodity::getCostomerBenifit()
{
	return discount_strady->getCustomerBenifit();
}

