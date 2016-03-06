#ifndef _H_BAR_CODE_CONTROL_H
#define _H_BAR_CODE_CONTROL_H

#include "basic_headers.h"
#include "commodity.h"

const int STANDARD_BAR_CODE_LENGTH = 10;

/* 
    barCodeControl -- provided the related service for the commodity bar-code

*/
class barCodeControl
{
private:
	barCodeControl();
public:
	static barCodeControl getInstance();

	/*
	*func: distinguish the bar-code in the shopping list;
	*input:
	      shopping_list_input: a list which contain all commoditoes' bar-code;      
	*output:
	       commodity_with_count : the count commodity map, such as coca-cola 
		   commodity_with_weight: the weight commodity map, such as apple
	*/
	void distinguishShoppingListInput(const vector<string>& shopping_list_input, 
		                              map<string, double>& commodity_with_count,
									  map<string, double>& commodity_with_weight);

    /*
	*func: get commodity information by bar-code;
	*input:
	      commodity_bar_code;     
	*output:
	       commodity_information;
	*/
	void  getCommodityInfo(const string& commodity_bar_code, commodity_info& commodity_information);
};

#endif