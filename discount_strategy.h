#ifndef _H_DISCOUNT_STRATEGY_H
#define _H_DISCOUNT_STRATEGY_H

#include "basic_headers.h"

enum DISCOUNTTYPE
{
	BuyTwoGetOneFree,
	DiscountForEach,
	NoDiscount
};

struct discount_benifit
{
	unsigned int free_num;//the goods num which are free
	double saved_money;
};

/* 
    discountControl -- decide each commodity's discount strategy; 
*/
class discountControl
{
public:
	static discountControl getInstance();

	/*
	*func: distinguish each goods' discount type;
	*input:
	      commodity_bar_code;    
	*output:
	       the discount type;
	*/
	DISCOUNTTYPE getDiscountType(string commodity_bar_code);

	/*
	*func: add commodity bar-code into the buy_2_get_1_free_list
	*input:
	      commodity_bar_code;    
	*output:
	       void;
	*/
	void  addCommodityBarCodeIntoBuy2Get1FreeList(const string& commodity_bar_code);

	/*
	*func: remove commodity bar-code from the buy_2_get_1_free_list
	*input:
	      commodity_bar_code;    
	*output:
	       void;
	*/
	void  removeCommodityBarCodeFromBuy2Get1FreeList(const string& commodity_bar_code);

	/*
	*func: add commodity bar-code into the five_percent_off_list
	*input:
	      commodity_bar_code;    
	*output:
	       void;
	*/
	void  addCommodityBarCodeInto5PecentOffList(const string& commodity_bar_code);

	/*
	*func: remove commodity bar-code from the five_percent_off_list
	*input:
	      commodity_bar_code;    
	*output:
	       void;
	*/
	void  removeCommodityBarCodeFrom5PecentOffList(const string& commodity_bar_code);

private:
	static vector<string>        buy_2_get_1_free_list;//contain all the commodities which enjoy the buy 2 get 1 free discount
	static vector<string>        five_percent_off_list;//contain all the commodities which enjoy 5% discount

private:
	discountControl();

};


/* 
    discountBehavior -- the diffrent discount behavior, and the default is no discount; 
*/
class discountBehavior
{
public:
	discountBehavior(double number, double price);
	virtual ~discountBehavior();
	
	/*
	*func: get the benifit customer got
	*input:
	      void;    
	*output:
	       customer benifit;
	*/
	virtual discount_benifit getCustomerBenifit();

protected:
	double          db_commodity_number;
	double          db_price;
};

/* 
    buyTwoGetOneFree -- the discount behavior, which buy 2 goods can get one another goods free; 
*/
class buyTwoGetOneFree:public discountBehavior
{
public:
	buyTwoGetOneFree(unsigned int commodity_number, double price);
	/*
	*func: get the benifit customer got
	*input:
	      void;    
	*output:
	       customer benifit;
	*/
	discount_benifit getCustomerBenifit();
};

/* 
    xPecentOff -- the discount behavior, which get x% off for each goods; 
*/
class xPecentOff: public discountBehavior
{
public:
	xPecentOff(double commodity_number, double price);

	/*
	*func: get the benifit customer got
	*input:
	      void;    
	*output:
	       customer benifit;
	*/
	discount_benifit getCustomerBenifit();

    /*
	*func: set discount percent 
	*input:
	      percentoff: the new percent can off;    
	*output:
	       void;
	*/
	 void setDiscountPercent(double percentoff);

private:
	static double discout_percent;// the discount percent and the default value is 5, ie. 5% off for each commodity
};

/* 
    noDiscount -- no discount for commodity
	
	*/

class noDiscount: public discountBehavior
{
public:
	noDiscount(double commodity_number, double price);
};

#endif