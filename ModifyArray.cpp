#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ModifyArray.h"

/** Reads the data from the file and inputs it into the array.
	pre: File named integer_file.txt consisting of less than 150 integers exists in directory
	post: Data from file is stored in class's array named integer_array
*/
void ModifyArray::read_file()
{
	std::ifstream file;
	file.open("integer_file.txt");
	for (int i = 0; i < 100; i++)
		file >> integer_array[i];
	file.close();
};

/** Outputs array to console via cout.
	pre: Integer data from file is stored in class's array
*/
void ModifyArray::get_array() {
	for (int i = 0; i < end_of_array; i++) {
		std::cout << integer_array[i] << " ";
		if ((i + 1) % 10 == 0)
			std::cout << "\n";
	}
}

/** Check if a certain integer exists within the array and return the index where the
number is present. If value is not found, returns -1.
	pre: Inputted value is of type int
	@param value Value to check for
	@return Index integer is stored at
*/
int ModifyArray::get_index_for_specified_int(int value)
{
	for (int i = 0; i < 150; i++)
	{
		if (value == integer_array[i])
			return i;
	}
	return -1;
}

/** Modifies the value of an integer when called with the index of the integer in the
array, and returns the new and old value back to the user.
	pre: Index is within array (ints 0 to 149), new value is of type int
	@param index Index of integer to the modified
	@param new_value New integer value for the given index
	@return Old value
*/
int ModifyArray::set_value_of_index(int index, int new_value)
{
	/**Try and catch blocks to catch user input errors for question 2*/
	try {
		if (new_value == 0)
			throw (0);
		if (index < 0 || index > 149)
			throw std::out_of_range("User input out of range of array.");

	}
	catch (std::out_of_range& ex) {
		std::cerr << "*** Out of range exception thrown for index user provided.\n" << ex.what() << "\n";
		abort();
	}
	catch (...) {
		std::cerr << "User input is not valid, it must be a nonzero integer\n";
		abort();
	}
	int old_value = integer_array[index];
	integer_array[index] = new_value;
	std::cout << "Old value was " << old_value << ", now replaced by " << new_value << "\n";
	return old_value;
}

/** Adds a new integer to the end of the array (AKA first occurence of 0).
	pre: New value is of type int and nonzero
	@param new_value New integer to be added
	@return Index where value was inputted
*/
int ModifyArray::set_new_integer(int new_value)
{
	/**Try and catch blocks to catch user input errors for question 2*/
	try {
		if (end_of_array > 149)
			throw std::out_of_range("Array is full, no new values can be added to end.");
		if (new_value == 0)
			throw(0);
	}
	catch (std::out_of_range& ex) {
		std::cerr << "*** Out of range exception thrown for index being accessed.\n" << ex.what() << "\n";
		abort();
	}
	catch (...) {
		std::cerr << "User input is not valid, it must be a nonzero integer\n";
		abort();
	}

	integer_array[end_of_array] = new_value;
	end_of_array++;
	return end_of_array - 1;
}


/** Takes the given index of the array and replaces its value with 0.
	pre: Index is within array (ints 0 to 149)
	@param index Index to be replaced with 0
*/
void ModifyArray::remove_value_at_index(int index)
{
	integer_array[index] = 0;
}

/** Constructor, automatically reads file and sets remaining values to 0.
*/
ModifyArray::ModifyArray()
{
	read_file();
	for (int i = 100; i < 150; i++)
		integer_array[i] = 0;
	end_of_array = 100;
}