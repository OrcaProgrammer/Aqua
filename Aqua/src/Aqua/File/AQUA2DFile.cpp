#include "AQUA2DFile.h"

namespace Aqua {

	void AQUA2DFile::read(std::string filepath) {

		std::string data;
		std::ifstream file;

		// ensure ifstream objects can throw exceptions:
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		// read in shader code
		try
		{
			file.open(filepath);
			std::stringstream fileStream;
			fileStream << file.rdbuf();
			file.close();
			data = fileStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "Failed to read file!" << "\n";
		}

		data.erase(std::remove(data.begin(), data.end(), '\n'), data.cend());

		bool endOfData = false;

		std::vector<std::string> dataNames;
		std::vector<std::string> dataProperties;
		

		// Parse data
		for (int i = 0; i < data.length();) {

			// Get data line
			std::size_t endOfLinePos = data.find(';', i);
			std::string dataLine = data.substr(i, endOfLinePos);
			dataLine.erase(std::remove(dataLine.begin(), dataLine.end(), ';'), dataLine.cend());

			// Extract data name
			std::size_t nameEndPos = dataLine.find(':', 0);
			std::string dataName = dataLine.substr(0, nameEndPos);
			dataNames.push_back(dataName);

			// Extract data property
			std::size_t propEndPos = dataLine.find(':', nameEndPos + 1);
			std::string dataProperty = dataLine.substr(nameEndPos + 1, propEndPos);
			dataProperties.push_back(dataProperty);

			i += (endOfLinePos + 1);
		}
	}

}