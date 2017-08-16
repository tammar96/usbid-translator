#ifndef USBIDS_HPP
#define USBIDS_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <exception>
#include <stdexcept>

#include "../PEGTL/pegtl.hh"
#include "../PEGTL/pegtl/analyze.hh"
#include "../PEGTL/pegtl/contrib/abnf.hh"



#include "types.hpp"
#include "params.hpp"

class USBIDs{
public:
	USBIDs(const std::string &);

	std::string idToString(uint16_t vid, uint16_t pid);
	std::string interfaceToString(uint8_t c, uint8_t s, uint8_t p);

private:
	int parseStream(const std::string &);
	usb_ids_t usb_info;
};

class syntax_error : public std::runtime_error {
public:
	 syntax_error(const std::string &s): std::runtime_error(s) { }
};
#endif

/* vim: set ts=4 sw=4 tw=0 noet : */
