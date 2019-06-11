/*
 * record.cpp
 *
 *  Created on: March 27, 2019
 *      Author: Dominic Quintero
 */

#include "record.h"
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Returns line it is given
Record::Record(string str)
{
	// Remove all white space
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	// Parsing data using , as a delimiter, then storing it into vector
	vector<string> table;
    stringstream check1(str);
    string intermediate;
    while(getline(check1, intermediate, ','))
    {
        table.push_back(intermediate);
    }

	// Assign parsed data to their fields
	department = table[1];
	item_code = table[2];
	quantity = atoi((table[3]).c_str());
	cost = atof((table[4]).c_str());
}

// Return true if all fields of records are equal to each other
bool operator ==(const Record &a, const Record &b)
{
	return (a.department == b.department && a.item_code == b.item_code && a.quantity == b.quantity && a.cost == b.cost);
}

// Compare function used for sort function
bool operator <(const Record &a, const Record &b)
{
	if(a.department < b.department)
		return true;
	else if (a.department == b.department && a.item_code < b.item_code)
		return true;
	else
		return false;
}

// Prints out data with commas separating the fields
ostream& operator <<(ostream& out, const Record&p)
{
	out << p.department << ", " << p.item_code << ", " << p.quantity << ", " << p.cost << "\n";
	return out;
}

vector<string> Record::getRec()
{
	vector<string> table;
	table.push_back(department);
	table.push_back(item_code);
	return table;
}

double Record::getQuantity(){
	return quantity;
}

double Record::getCost(){
	return cost;
}

Record::~Record() {
	// Empty
}
