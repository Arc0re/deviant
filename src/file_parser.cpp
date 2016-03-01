#include "file_parser.h"

config_info parser::parse_file(std::string file_path)
{
	std::ifstream file;
	config_info file_contents; // key-value returned
	std::string line; // current line
	
	file.open(file_path.c_str());

	if (!file) {
		std::cerr << "Failed to load " << file_path << std::endl;
		exit(EXIT_FAILURE);
	}

	while (std::getline(file, line)) {
		std::istringstream is_line(line);
		std::string key;

		if (std::getline(is_line, key, '=')) {
			std::string value;

			if (std::getline(is_line, value)) {
				file_contents[key] = value;
			}
		}
	}

	file.close();

	return file_contents;
}
