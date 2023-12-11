#pragma once

#include "Aqua/Core/Core.h"
#include <iostream>
#include <string>
#include <vector>

namespace Aqua {


	enum class AQUA_API AQUA_2D_DATA_TYPES {
		LINE,
		SQUARE,
		CIRCLE,
		POLYGON,
	};


	class AQUA_API AQUA_2D_DATA
	{
	private:
		std::vector<std::string> names;
		std::vector<std::string> properties;
		int size;

	public:

		AQUA_2D_DATA(std::string dataNames, std::string dataProperties) :
			names{ dataNames }, properties{ dataProperties } {
			size = names.size();
		}


	};

}