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
public:
	vector<string> user_includes;
private:
	/**
	 @brief Makes a clear object
	 */
	Include();
	
	/**
	 @brief Returns a concrete include
	 @param pos Position in vector
	 @return Concrete include
	 */
	string getUserInclude(int pos);
	
	/**
	 @brief Returns the entire vector
	 @return The entire vector
	 */
	vector<string> getUserInclude();
	
	/**
	 @brief Reads all includes and saves them
	 
	 Reads all includes and saves those which are written by the developer
	 */
	void read(string complete);
};

#endif /* include_reader_h */
