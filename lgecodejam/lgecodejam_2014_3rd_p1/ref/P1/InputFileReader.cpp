#include "InputFileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) 
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

InputFileReader::InputFileReader()
{

}

InputFileReader::~InputFileReader(void)
{
	
}


void InputFileReader::loadFile(const char * path)
{
	string line;
	ifstream file(path);

	if (file.is_open()) 
	{
		// 1. number of case
		getline (file,line);
		number_of_test_case = atoi(line.c_str());

		//cout << "1." << number_of_test_case << endl;

		for (int n_case = 0; n_case < number_of_test_case; n_case ++) 
		{

			// 2. N, M
			getline (file,line);
			vector<string> x = split(line.c_str(), ' ');
			
			t_header header;
			memset(&header, 0x00, sizeof(header));
			header.number_of_n = atoi(x[0].c_str());
			header.number_of_m = atoi(x[1].c_str());
			header_info.push_back(header);

			//cout << "2." << header.number_of_n << endl;
			//cout << "2." << header.number_of_m << endl;

			std::vector<t_cross> cross;

			// 3. get information of tree
			for (int idx = 0; idx < header.number_of_n-1; idx++) 
			{
				getline (file,line);
				vector<string> x = split(line.c_str(), ' ');				

				t_cross cr;
				memset(&cr, 0x00, sizeof(cr));

				cr.first = atoi(x[0].c_str());
				cr.second = atoi(x[1].c_str());

				//cout << "3." << cr.first << endl;
				//cout << "3." << cr.second << endl;
	
				cross.push_back(cr);
			}

			cross_info.push_back(cross);

			std::vector<t_query> query;

			// 4.get query 
			for (int idx_m = 0; idx_m < header.number_of_m; idx_m++) 
			{
				getline (file,line);
				vector<string> x = split(line.c_str(), ' ');

				t_query qry;
				memset(&qry, 0x00, sizeof(qry));
				qry.start = atoi(x[0].c_str());
				qry.end = atoi(x[1].c_str());

				query.push_back(qry);
			}

			query_info.push_back(query);			
			
		}
		file.close();
	}	
}

void InputFileReader::printValue()
{
	cout << "case : " << number_of_test_case << endl;
	

	for (int idx = 0; idx < number_of_test_case; idx++) 
	{
		cout << "case # " << idx << endl;
		cout << "N : " << header_info[idx].number_of_n << endl;
		cout << "M : " << header_info[idx].number_of_m << endl;

		for (int idx_n = 0; idx_n< header_info[idx].number_of_n - 1; idx_n++) 
		{
			cout << "{" << cross_info[idx][idx_n].first << "," << cross_info[idx][idx_n].second  << "}" << endl;
		}

		for (int idx_m = 0; idx_m< header_info[idx].number_of_m; idx_m++) 
		{
			cout << "<" << query_info[idx][idx_m].start<< "," << query_info[idx][idx_m].end  << ">" << endl;
		}
	}

}


