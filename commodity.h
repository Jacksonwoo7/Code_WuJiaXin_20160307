#ifndef _H_COMMODITY_H
#define _H_COMMODITY_H
#include "discount_strategy.h"

struct commodity_info
{
	double       number;
	string       name;
	double       price;
	string       unit;
};

/* 
    commodity -- provided the basic functions for the commodity
*/
class commodity 
{
public:
	commodity(double number, string name, double price, string unit, DISCOUNTTYPE discount_type);

	virtual ~commodity();
	commodity(const commodity& org);
	commodity& commodity::operator= (const commodity& rhs);

	/*
	*func: get commodites' information;
	*input:
	      goods_info;     
	*output:
	       goods_info;
	*/
	void getCommodityInfo(commodity_info& goods_info);

	/*
	*func: get same kind of commodity's revenue;
	*input:
	      void;     
	*output:
	       commodities' revenue;
	*/
    double getRevenueForSameCommodity();

	/*
	*func: get customer's benifit got by discount;
	*input:
	      void;     
	*output:
	       commodities' revenue;
	*/
	discount_benifit getCostomerBenifit();

private:
	double            commodity_number;
	string            commodity_name;
	double            commodity_price;
	string            commodity_unit;
	discountBehavior* discount_strady;
};


#endif