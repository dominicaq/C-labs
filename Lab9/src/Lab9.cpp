//============================================================================
// Name        : Lab9.cpp
// Author      : Dominic Quintero
// Version     :
// Copyright   :
// Description : Record Program
//============================================================================

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "record.h"

using namespace std;

int main()
{
	// Vector of records
	vector<Record> records;
	string filename;

	/*
	 * Insert user input into filename, then find and read file
	 */
	cout << "Enter name of your file with file path " << endl;
	cin >> filename;
	ifstream ifs(filename.c_str());

	if (!ifs){
		cout << "Can't open file " << filename << endl;
		return 1;
	}

	// Read in file
	string line;
	while(getline(ifs, line))
	{
		int size = records.size();
		records.push_back(Record(line));

		for(int i = 0; i < size; i++)
		{
			// Duplicates
			if (records[size] == records[i])
				records.erase (records.begin()+size);

			// Sorting
			sort(records.begin(), records.begin()+size);
		}
	}
	ifs.close();

	// Create file and path strings
	string path = filename.substr(0, filename.find_last_of("\\/"));
	string file = filename.substr(filename.find_last_of("\\/") + 1,filename.length());

	// Create new file name, remove .extension if present
	file = file.substr (0, file.find("."));
	file = "new_" + file + ".csv";
	string final = path + "/" + file;

	if (path.compare(file) == 0)
		path == "";

	/*
	 * Create a output file with user input, run a loop and add a number to each element as its added
	 */
	ofstream outFile;
	outFile.open (final.c_str());
	int size = records.size();
	int index = 1;
	for (int i = 0; i < size; i++)
	{
		outFile << index << ", " << records[i];
		index ++;
	}
	outFile.close();

	// Output csv file to terminal with tab view
	// Header
	cout << setw(15) << left << "Department";
	cout << setw(15) << left << "Item Code";
	cout << setw(10) << "Quantity";
	cout << setw(5) << right << "Cost";
	cout << setw(12) << right << "Total" << "\n";
	cout << "___________________________________________________________\n";

	// Record lines
	for (int i = 0; i < size; i++)
	{
		// Prepare data for output
		Record p = records[i];
		vector<string> table;
		table = p.getRec();
		int quantity = p.getQuantity();
		double cost = p.getCost();
		double total = quantity * cost;

		// Outputting data
		cout << setw(15) << left << table[0];
		cout << setw(15) << left << table[1];
		cout << setw(10) << quantity;
		cout << setw(5) << fixed << setprecision (2) << right << cost;
		cout << setw(12) << fixed << setprecision (2) << right << total << "\n";
	}

	cout << "Output directory: " << path << "\n";
	cout << "Output file: " << file << "\n";
	return 0;
}

///home/student/Desktop/data-base.csv
