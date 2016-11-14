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
	char folders;
	bool in_folders = false;
	vector<string> all_incl;
	string str, main_name, folders_names[5], binarie;
	Include looking;
	
	cout << "\nPlease, write the name of your main cpp (if its name is main.cpp just write - ):" << endl;
	cout << "Example: my_program.cpp" << endl;
	cin >> main_name;
	
	if(main_name == "-"){
		main_name = "main.cpp";
	}
	
	for(int i = 0; i < main_name.length(); i++){
		if(main_name[i] != '.'){
			binarie += main_name[i];
		}
	}
	
	cout << "Are your files in separated folders like 'src' or 'include'? Y/N";
	cin >> folders;
	
	if(folders == 'Y' || folders == 'y'){
		in_folders = true;
		
		cout << "\nWrite the name of the folder that contains cpp files: ";
		cin >> folders_names[0];
		cout << "\nWrite the name of the folder that contains h (or hpp) files: ";
		cin >> folders_names[1];
		cout << "\nWrite the name of the folder that will contain object files: ";
		cin >> folders_names[2];
		cout << "\nWrite the name of the folder that will contain library files: ";
		cin >> folders_names[3];
		cout << "\nWrite the name of the folder that will contain executable files: ";
		cin >> folders_names[4];
		
		main_name = folders_names[0] + "/" + main_name;
	}
	
	main_user.open(main_name);
	
	if (!main_user){
		cerr << "Error opening main file" << endl;
		cerr << "Check you have writen the name in the right way" << endl;
		cerr << "If the problem persists, check the folders that contains the file is named src/" << endl;
	}
	else{
		
		makefile << "CPPFLAGS = g++ -std=c++11 -c" << endl;
		
		if(in_folders){
			makefile << "SRC = " << folders_names[0] << endl;
			makefile << "INC = " << folders_names[1] << endl;
			makefile << "OBJ = " << folders_names[2] << endl;
			makefile << "LIB = " << folders_names[3] << endl;
			makefile << "BIN = " << folders_names[4] << endl;
		}
		
		makefile << "\n\n";
		
		do{
			getline(main_user, str);
			str = looking.read(str);
			
			if(str != "" && str[0] != '/'){
				all_incl.push_back(str);
			}
			
		}while (str[0] == '#');
		
		if(in_folders){
			makefile << binarie << ": " << binarie << ".o ";
			
			for(int i = 0; i < all_incl.size(); i++){
				////////////////////////////////////////////////////////
			}
			
			makefile << "\tg++ -std=c++11 -o " << binarie << " ";
		}
	}
}
