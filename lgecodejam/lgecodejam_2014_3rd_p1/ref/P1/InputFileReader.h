#pragma once

#include <vector>

class InputFileReader
{
public:
	
	typedef struct _t_cross { int first; int second; } t_cross;
	typedef struct _t_query { int start; int end; } t_query; 

	typedef struct {
		int number_of_n;
		int number_of_m;
	} t_header;

	std::vector<t_cross> pair_of_cross;
	std::vector<t_query> pair_of_query;
	

	InputFileReader(void);
	~InputFileReader(void);
	void printValue();
	void loadFile(const char * path);

	int number_of_test_case;
	std::vector<t_header> header_info;
	std::vector<std::vector<t_cross>> cross_info;
	std::vector<std::vector<t_query>> query_info;
};
