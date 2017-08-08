#include <iostream>
#include <string>

#include "USBIDs.hpp"

int main(int argc, char *argv[]){

	// class USBIDs *a = new class USBIDs("./input");

	if(argc == 4 && static_cast<std::string>(argv[1]) == "id"){
		//--------------------------------------------
		// WARNING WARNING WARNING WARNING WARNING
		//--------------------------------------------
		uint16_t vid = static_cast<uint16_t>(std::stoi(argv[2], 0, 16));
		uint16_t pid = static_cast<uint16_t>(std::stoi(argv[3], 0, 16));
		//--------------------------------------------

		class USBIDs *a = new class USBIDs("./content");
		std::string output = a->idToString(vid, pid);
		std::cout << output << std::endl;
		delete a;
	}
	else if(argc == 5 && static_cast<std::string>(argv[1]) == "interface"){
		//--------------------------------------------
		// WARNING WARNING WARNING WARNING WARNING
		//--------------------------------------------
		uint16_t c = static_cast<uint16_t>(std::stoi(argv[2], 0, 16));
		uint16_t s = static_cast<uint16_t>(std::stoi(argv[3], 0, 16));
		uint16_t p = static_cast<uint16_t>(std::stoi(argv[4], 0, 16));
		//--------------------------------------------

		class USBIDs *a = new class USBIDs("./content");
		std::string output = a->interfaceToString(c, s, p);
		std::cout << output << std::endl;
		delete a;
	}
	else{
		std::cout << "USBID-parser help message" << std::endl
				  << "Usage:" << std::endl
				  << "USBID-parser [OPTION] args" << std::endl
				  << "    id\t\tVID PID\t\t " << std::endl
				  << "    interface\tC S P\t" << std::endl;
	}


	return 0;
}

/* vim: set ts=4 sw=4 tw=0 noet : */
