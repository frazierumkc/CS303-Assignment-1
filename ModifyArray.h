#ifndef MODIFYARRAY_H_
#define MODIFYARRAY_H_
#pragma once

class ModifyArray {
public:
	/** Reads the data from the file and inputs it into the array.
		pre: File named integer_file.txt consisting of less than 150 integers exists in directory
		post: Data from file is stored in class's array named integer_array
	*/
	void read_file();

	/** Outputs array to console via cout.
		pre: Integer data from file is stored in class's array
	*/
	void get_array();

	/** Check if a certain integer exists within the array and return the index where the 
	number is present. If value is not found, returns -1.
		pre: Inputted value is of type int
		@param value Value to check for
		@return Index integer is stored at
	*/
	int get_index_for_specified_int(int value);

	/** Modifies the value of an integer when called with the index of the integer in the 
		array, and returns the new and old value back to the user.
		pre: Index is within array (ints 0 to 149), new value is of type int
		@param index Index of integer to the modified
		@param new_value New integer value for the given index
		@return Old value
	*/
	int set_value_of_index(int index, int new_value);

	/** Adds a new integer to the end of the array (AKA first occurence of 0).
		pre: New value is of type int
		@param new_value New integer to be added
		@return Index where value was inputted
	*/
	int set_new_integer(int new_value);

	/** Takes the given index of the array and replaces its value with 0.
		pre: Index is within array (ints 0 to 149)
		@param index Index to be replaced with 0
	*/
	void remove_value_at_index(int index);

	/** Constructor, automatically reads file and sets remaining values to 0.
	*/
	ModifyArray();

private:
	int integer_array[150];
	int end_of_array;
};

#endif