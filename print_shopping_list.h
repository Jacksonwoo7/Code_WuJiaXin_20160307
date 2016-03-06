#ifndef _H_PRINT_SHOPPING_LIST_H
#define _H_PRINT_SHOPPING_LIST_H
#include "commodity.h"

   /*
	*func: print the shopping list
	*input:
	      commodity_list    
	*output:
	       void;
	*/
void printShoppingList(vector<commodity> commodity_list);

   /*
	*func: used for get the shopping list by manual input the bar-code
	*input:
	      commodity_list    
	*output:
	       void;
	*/
void createShoppingListInput(vector<string>& shopping_list_input);

   /*
	*func: get the commodity list from the shopping list input;
	*input:
	      shopping_list_input: which contain all the bar-code information;    
	*output:
	       commodity_list;
	*/

void getCommodityList(vector<commodity>& commodity_list,const vector<string>& shopping_list_input);

   /*
	*func: convert the commodity to the commodity list;
	*input:
	      commodity_map;    
	*output:
	       commodity_list;
	*/
void convertCommodityMapToCommodotyList(vector<commodity>& commodity_list, const map<string, double>& commodity_map);
#endif