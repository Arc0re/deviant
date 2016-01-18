// -*- C++ -*-
#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <fstream> 
#include <string>
#include <map>
#include <sstream>

typedef std::map<std::string, std::string> config_info;

namespace parser
{
	config_info parse_file(std::string file_path);
}

#endif
