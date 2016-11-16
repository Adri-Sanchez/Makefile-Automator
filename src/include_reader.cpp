//
//  include_reader.cpp
//  Makefile Automator
// 
//  Created by Jesús Jiménez Sánchez on 7/11/16.
//  Copyright © 2016 Jesús Jiménez Sánchez. All rights reserved.
//

#include "include_reader.h"
#include <string>

using namespace std;

Include::Include(){
	user_includes.clear();
}

string Include::getUserInclude(unsigned int pos){
	string to_return = "";
	
	if(pos < user_includes.size()){
		to_return = user_includes[pos];
	}
	
	return to_return;
}

vector<string> Include::getUserInclude() const{
	return user_includes;
}

bool Include::cppLibraries(const string &looking) const{
	bool cpplib = false;
	
	if(looking == "cassert" || looking == "assert.h")
		cpplib = true;
	if(looking == "cctype" || looking == "ctype.h")
		cpplib = true;
	if(looking == "cerrno" || looking == "errno.h")
		cpplib = true;
	if(looking == "cfenv" || looking == "fenv.h")
		cpplib = true;
	if(looking == "cfloat" || looking == "float")
		cpplib = true;
	if(looking == "cinttypes" || looking == "inttypes.h")
		cpplib = true;
	if(looking == "ciso646" || looking == "iso646.h")
		cpplib = true;
	if(looking == "climits" || looking == "limits.h")
		cpplib = true;
	if(looking == "clocale" || looking == "locale.h")
		cpplib = true;
	if(looking == "cmath" || looking == "math.h")
		cpplib = true;
	if(looking == "csetjmp" || looking == "setjmp.h")
		cpplib = true;
	if(looking == "csignal" || looking == "signal.h")
		cpplib = true;
	if(looking == "cstdarg" || looking == "stdarg.h")
		cpplib = true;
	if(looking == "cstdbool" || looking == "stdbool.h")
		cpplib = true;
	if(looking == "cstddef" || looking == "stdbool.h")
		cpplib = true;
	if(looking == "cstdint" || looking == "stdint.h")
		cpplib = true;
	if(looking == "cstdio" || looking == "stdio.h")
		cpplib = true;
	if(looking == "cstdlib" || looking == "stdlib.h")
		cpplib = true;
	if(looking == "cstring" || looking == "string.h")
		cpplib = true;
	if(looking == "ctgmath" || looking == "tgmath")
		cpplib = true;
	if(looking == "ctime" || looking == "looking.h")
		cpplib = true;
	if(looking == "cuchar" || looking == "uchar.h")
		cpplib = true;
	if(looking == "cwchar" || looking == "wchar.h")
		cpplib = true;
	if(looking == "cwctype" || looking == "wctype.h")
		cpplib = true;
	if(looking == "array")
		cpplib = true;
	if(looking == "deque")
		cpplib = true;
	if(looking == "forward_list")
		cpplib = true;
	if(looking == "list")
		cpplib = true;
	if(looking == "map")
		cpplib = true;
	if(looking == "queue")
		cpplib = true;
	if(looking == "set")
		cpplib = true;
	if(looking == "stack")
		cpplib = true;
	if(looking == "unordered_map")
		cpplib = true;
	if(looking == "unordered_set")
		cpplib = true;
	if(looking == "vector")
		cpplib = true;
	if(looking == "fstream")
		cpplib = true;
	if(looking == "iomanip")
		cpplib = true;
	if(looking == "ios")
		cpplib = true;
	if(looking == "iosfwd")
		cpplib = true;
	if(looking == "iostream")
		cpplib = true;
	if(looking == "istream")
		cpplib = true;
	if(looking == "ostream")
		cpplib = true;
	if(looking == "sstream")
		cpplib = true;
	if(looking == "streambuf")
		cpplib = true;
	if(looking == "atomic")
		cpplib = true;
	if(looking == "condition_variable")
		cpplib = true;
	if(looking == "future")
		cpplib = true;
	if(looking == "mutex")
		cpplib = true;
	if(looking == "thread")
		cpplib = true;
	if(looking == "algorithm")
		cpplib = true;
	if(looking == "bitset")
		cpplib = true;
	if(looking == "chrono")
		cpplib = true;
	if(looking == "codecvt")
		cpplib = true;
	if(looking == "complex")
		cpplib = true;
	if(looking == "exception")
		cpplib = true;
	if(looking == "functional")
		cpplib = true;
	if(looking == "initializer_list")
		cpplib = true;
	if(looking == "iterator")
		cpplib = true;
	if(looking == "limits")
		cpplib = true;
	if(looking == "locale")
		cpplib = true;
	if(looking == "memory")
		cpplib = true;
	if(looking == "new")
		cpplib = true;
	if(looking == "numeric")
		cpplib = true;
	if(looking == "random")
		cpplib = true;
	if(looking == "ratio")
		cpplib = true;
	if(looking == "regex")
		cpplib = true;
	if(looking == "stdexcept")
		cpplib = true;
	if(looking == "string")
		cpplib = true;
	if(looking == "system_error")
		cpplib = true;
	if(looking == "tuple")
		cpplib = true;
	if(looking == "typeindex")
		cpplib = true;
	if(looking == "typeinfo")
		cpplib = true;
	if(looking == "type_traits")
		cpplib = true;
	if(looking == "utility")
		cpplib = true;
	if(looking == "valarray")
		cpplib = true;
	
	
	return cpplib;
}

string Include::read(const string &complete){
	size_t pos_1, pos_2;
	bool angle, quotation;
	string looking;
	
	angle = false;
	quotation = false;
	
	for(int i = 0; i < complete.length() && !angle && !quotation; i++){
		if(complete[i] == '<'){
			angle = true;
			looking = "<";
		}
		
		if(complete[i] == '"'){
			quotation = true;
			looking = "\"";
		}
	}
	
	if(quotation){
		pos_1 = complete.find("\"");
		pos_2 = complete.find("\"", pos_1+1);
		
		looking = complete.substr(pos_1+1, pos_2-1);
	}
	else{
		looking = "";
	}
	
	if(angle){
		pos_1 = complete.find("<");
		pos_2 = complete.find(">", pos_1+1);
		
		looking = complete.substr(pos_1+1, pos_2-1);
	}
	else{
		looking = "";
	}
	
	if(looking != "" && !cppLibraries(looking)){
		user_includes.push_back(looking);
	}
	else{
		looking = "";
	}
	
	return looking;
}
