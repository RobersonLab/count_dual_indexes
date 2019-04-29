/*
 * helper.cpp
 *
 *  Created on: Feb 27, 2019
 *      Author: eli_lab
 */

// template libraries
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

// project includes
#include "helper.h"

/*
// functions
*/

void logError(const std::string& msg) {
	std::cerr << "Error: " << msg << std::endl;
	std::exit( 1 );
}
