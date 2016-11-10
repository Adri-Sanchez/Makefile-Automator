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

string Include::getUserInclude(int pos){
	string to_return;
	
	if(pos < user_includes.size()){
		to_return = user_includes[pos];
	}
	
	return to_return;
}

vector<string> Include::getUserInclude(){
	return user_includes;
}

void Include::read(string complete){
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
	
	//Empezar a leer
}
