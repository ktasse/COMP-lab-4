#include "FileParser.h"
#include <string>
#include <fstream>
#include <iostream>


FileParser::FileParser(const std::string& input, const std::string& output) {

	inputFileName = input;
	outputFileName = output;

}

void FileParser::parse() {

    int nextChar{};
    std::string word{};
    int number{};

    std::ifstream input(inputFileName);
    std::ofstream output(outputFileName, std::ios::app);

    if (!input)
    {
        std::cerr << "Could not open input file\n";
        return;
    }

    if (!output)
    {
        std::cerr << "Could not open output file\n";
        return;
    }

    while ((nextChar = input.peek()) != std::char_traits<char>::eof()) {
        
        
        if (isspace(nextChar))
        {
            input.ignore(1);
            continue;
        }

        if (isdigit(nextChar))
        {       
            input >> number;

            output << "Found an integer: " << number << '\n';
        }
        else
        {            
            input >> word;

            output << "Found a " << word.length() << " character word: " << word << '\n';
        }

    }

    input.close();
    output.close();

}



