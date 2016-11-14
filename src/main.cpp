//
//  main.cpp
//  Makefile Automator
//
//  Created by Jesús Jiménez Sánchez on 7/11/16.
//  Copyright © 2016 Jesús Jiménez Sánchez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "include_reader.h"

using namespace std;

int main(int argc, const char * argv[]) {
	ifstream main_user;
	ofstream makefile;
	string main_name;
	char folders;
	bool in_folders = false;
	vector<string> all_incl;
	string str;
	Include looking;
	
	cout << "\nPlease, write the name of your main cpp (if its name is main.cpp just write - ):" << endl;
	cout << "Example: my_program.cpp" << endl;
	cin >> main_name;
	
	if(main_name == "-"){
		main_name = "main.cpp";
	}
	
	cout << "Are your files in separated folders like 'src' or 'include'? Y/N";
	cin >> folders;
	
	if(folders == 'Y' || folders == 'y'){
		main_name = "src/" + main_name;
		
		in_folders = true;
	}
	
	main_user.open(main_name);
	
	if (!main_user){
		cerr << "Error opening main file" << endl;
		cerr << "Check you have writen the name in the right way" << endl;
		cerr << "If the problem persists, check the folders that contains the file is named src/" << endl;
	}
	else{
		getline(main_user, str);
		while(str[0] == '#'){
			str = looking.read(str);
			
			if(str != ""){
				/////////ORDENES DE COMPILACIÓN///////////////
			}
		}
	}
}
