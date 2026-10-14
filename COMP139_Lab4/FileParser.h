#pragma once

#include <string>


class FileParser
{
private:
	std::string inputFileName;
	std::string outputFileName;
	
public:

	/*
	* Constructor that stores input and output file names
	*
	* @param input  Name of the input file
	* @param output Name of the output file
	*/
	FileParser(const std::string& input, const std::string& output);

	/*
	* Reads the input file and writes classified words and integers
	* to the output file
	* 
	* will thow std::cerr if it can not open either file
	* 
	* appends the output file
    */
	void parse();

};

