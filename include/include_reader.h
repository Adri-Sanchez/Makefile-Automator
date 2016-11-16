//
//  include_reader.h
//  Makefile Automator
// 
//  Created by Jesús Jiménez Sánchez on 7/11/16.
//  Copyright © 2016 Jesús Jiménez Sánchez. All rights reserved.
//

#ifndef include_reader_hpp
#define include_reader_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Include{
private:
	vector<string> user_includes;
public:
	/**
	 @brief Makes a clear object
	 */
	Include();
	
	/**
	 @brief Returns a concrete include
	 @param pos Position in vector
	 @return Concrete include
	 */
	string getUserInclude(unsigned int pos) const;
	
	/**
	 @brief Returns the entire vector
	 @return The entire vector
	 */
	vector<string> getUserInclude() const;
	
	/**
	 @brief Check if it is a C++ librarie
	 @param looking Reads it and compare
	 Check if it is a library from C++
	 */
	bool cppLibraries(const string &looking) const;
	
	/**
	 @brief Reads all includes and saves them
	 @param complete For example: #include <iostream>
	 @return looking String with the header file
	 Reads all includes and saves those which are written by the developer
	 */
	string read(const string &complete);
};

#endif /* include_reader_h */
