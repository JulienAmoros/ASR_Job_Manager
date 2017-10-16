#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include "job.hpp"

class Command : public Job{
	public:
	char** argv;
	Command(const char * str){
		//cmd = std::string(str);
		//std::cout << "this is your string: " << cmd << std::endl;
		build_argv(str);
		for(int j=0; argv[j] != 0; j++){
			std::cout<< argv[j] << std::endl;
		}
	}

	void build_argv(const char * str){
		int nb = calc_nb_elements(str);
		//std::cout << "nb elements:" << nb << std::endl;
		argv = new char*[nb+1];
		int res_index = 0;
		std::string * tmp = new std::string();
		for(;*str != 0; str++){
			//std::cout << *str;
			if(*str != ' ') *tmp+=*str;
			else{
				char * tmp2 = new char[tmp->size()+1];
				std::copy(tmp->begin(),tmp->end(),tmp2);
				argv[res_index] = tmp2;
				res_index++;
				//std::cout << *tmp << std::endl;
				tmp = new std::string();	
			}
		}
		char * tmp2 = new char[tmp->size()+1];
		std::copy(tmp->begin(),tmp->end(),tmp2);
		argv[res_index] = tmp2;
		//std::cout << tmp << std::endl;
		res_index++;
		
		argv[res_index] = (char*) 0;
		//std::cout << std::endl << "res content:" << std::endl;
	}

	int calc_nb_elements(const char * str){
		int i=0;
		for(; *str != 0; str++){
			if(*str==' ') i++;
		}		
		return i+1;
	}

	int run(){
		execvp(argv[0], argv);
		exit(1);
	}
};
