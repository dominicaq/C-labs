/*
 * record.h
 *
 */

#ifndef RECORD_H_
#define RECORD_H_

#include <iostream>
#include <string>
#include <vector>

class Record {
public:

	Record(std::string str);
	virtual ~Record();

	// Getters
	std::vector<std::string> getRec();
	double getQuantity();
	double getCost();

	// Output the data to output stream
	friend std::ostream& operator <<(std::ostream&, const Record&);
	// Comparison operators between records
	friend bool operator ==(const Record &lhs, const Record &rhs);
	friend bool operator <(const Record &lhs, const Record &rhs);

private:
	std::string department;
	std::string item_code;
	int quantity;
	double cost;
};


#endif /* RECORD_H_ */
