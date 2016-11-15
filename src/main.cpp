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
	vector<string> incl_no_h;
	string str, main_name, folders_names[5], binary;
	Include looking;
	
	cout << "\nPlease, write the name of your main cpp (if its name is main.cpp just write - ):" << endl;
	cout << "Example: my_program.cpp" << endl;
	cin >> main_name;
	
	if(main_name == "-"){
		main_name = "main.cpp";
	}
	
	for(int i = 0; i < main_name.length(); i++){
		if(main_name[i] != '.'){
			binary += main_name[i];
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
		cout << "\nWrite the name of the folder that will contain binary files: ";
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
		
		for(int i = 0; i < all_incl.size(); i++){
			string aux;
			
			for(int j = 0; j < all_incl[i].length(); j++){
				if(all_incl[i][j] != '.' && all_incl[i][j+1] != 'h' &&
				   (j+2) < all_incl[i].length()){		//i = element in vector, j = character in this element
					aux += all_incl[i][j];
				}
			}
			
			incl_no_h.push_back(aux);
		}
		
		if(in_folders){
			makefile << "\n## Binary file ##" << endl;
			makefile << "$(BIN)/" << binary << ": $(OBJ)/" << binary << ".o $(LIB)/libautomator.a" << endl;
			makefile << "\tg++ -std=c++11 -o $(BIN)/" << binary << "$(OBJ)/" << binary << " -I" << folders_names[1] << "/ -lautomator" << endl;
			
			makefile << "\n## Object files ##" << endl;
			makefile << "$(OBJ)/" << binary << ".o: $(SRC)/" << main_name << endl;
			makefile << "\t$(CPPFLAGS) $(SRC)/" << main_name << " -o $(OBJ)/" << binary << ".o -I" << folders_names[1] << "/" << endl;
			
			for(int i = 0; i < all_incl.size(); i++){
				makefile << "$(OBJ)/" << incl_no_h[i] << ".o: $(SRC)/" << incl_no_h[i] << ".cpp" << endl;
				makefile << "\t$(CPPFLAGS) $(SRC)/" << incl_no_h[i] << " -o $(OBJ)/" << incl_no_h[i] << ".o -I" << folders_names[1] << "/" << endl;
			}
			
			makefile << "\n## Library ##" << endl;
			////////////////////////////////////////////////////////
		}
	}
}
