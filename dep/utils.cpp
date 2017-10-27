#include "utils.hpp"


string prompt(string input)
{
	cout << "\n $: ";
	if (input == "")
	{cin >> input; return input;}
	else
	{return input;}	
}
