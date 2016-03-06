#include "stdafx.h"
#include "bar_code_control.h"

barCodeControl::barCodeControl()
{
}

barCodeControl barCodeControl::getInstance()
{
	static barCodeControl instance;
	return instance;
}

void barCodeControl::distinguishShoppingListInput(const vector<string>& shopping_list_input, 
												  map<string, double>& commodity_with_count,
												  map<string, double>& commodity_with_weight)
{
	string commodity_bar_code = "";
	for(vector<string>::const_iterator const_itor = shopping_list_input.begin(); const_itor != shopping_list_input.end(); const_itor++)
	{
		commodity_bar_code = *const_itor;
		string temp_bar_code(commodity_bar_code.begin(), commodity_bar_code.begin() + STANDARD_BAR_CODE_LENGTH);

		if(commodity_bar_code.size() != STANDARD_BAR_CODE_LENGTH)
		{
			string weight_info(commodity_bar_code.begin() + STANDARD_BAR_CODE_LENGTH + 1, commodity_bar_code.end());
			double weight = std::stod(weight_info);

			commodity_with_weight[temp_bar_code] = weight;
		}
		else
		{
			++commodity_with_count[temp_bar_code];
		}
	} 
}

void  barCodeControl::getCommodityInfo(const string& commodity_bar_code, commodity_info& commodity_information)
{
	if(commodity_bar_code == "ITEM000001")
	{
		commodity_information.name = "badminton";
		commodity_information.price = 1;
		commodity_information.unit = "ball";
	}
	else if(commodity_bar_code == "ITEM000003")
	{
		commodity_information.name = "apple";
		commodity_information.price = 5.5;
		commodity_information.unit = "kg";
	}
	else if(commodity_bar_code == "ITEM000005")
	{
		commodity_information.name = "coca-cola";
		commodity_information.price = 3;
		commodity_information.unit = "bottle";
	}
}