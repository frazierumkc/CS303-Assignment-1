#include <iostream>
#include "ModifyArray.h"

using namespace std;

int main()
{
	ModifyArray newArray;
	int input, input2, output;

	//Inputting file data into array
	newArray.read_file();

	//Testing get_index_for_specified_int function
	cout << "Enter an integer to check if if it in the array.\n";
	cin >> input;
	output = newArray.get_index_for_specified_int(input);
	if (output == -1)
		cout << "\nNumber was not found in array.\n";
	else
		cout << "Number was found at array index " << output << ".\n";

	//Testing set_value_of_index function
	cout << "\nEnter an integer and an index for it to be placed at.\nInteger: ";
	cin >> input;
	cout << "\nIndex: ";
	cin >> input2;
	cout << "\n";
	newArray.set_value_of_index(input2, input);
	cout << "\nNew array:\n";
	newArray.get_array();
	cout << "\n";

	//Testing set_new_integer function
	cout << "\nEnter an integer to be added to the end of the array.\n";
	cin >> input;
	cout << "\nNew value " << input << " was set at index " << newArray.set_new_integer(input) << "\n";
	cout << "\nNew array:\n";
	newArray.get_array();
	cout << "\n";

	//Testing remove_value_at_index function
	cout << "\nEnter an index to replace with 0.\n";
	cin >> input;
	newArray.remove_value_at_index(input);
	cout << "\nValue at index " << input << " was replaced with 0.\n";
	cout << "\nNew array:\n";
	newArray.get_array();
	cout << "\n";

	return 0;
}