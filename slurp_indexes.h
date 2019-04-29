/*
 * slurp_indexes.h
 *
 *  Created on: Apr 29, 2019
 *      Author: eli_lab
 */

#ifndef SLURP_INDEXES_H_
#define SLURP_INDEXES_H_

#include <map>
#include <string>

#include "parameters.h"

std::map< std::string, unsigned long long int > slurp( const Parameters& );

#endif /* SLURP_INDEXES_H_ */
