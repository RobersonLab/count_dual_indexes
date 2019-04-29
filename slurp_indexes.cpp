/*
 * slurp_indexes.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: eli_lab
 */

#include "parameters.h"
#include "slurp_indexes.h"

#include <fstream>
#include <map>
#include <string>


std::map< std::string, unsigned long long int > slurp( const Parameters& settings ) {
	std::map< std::string, unsigned long long int > dual_index_count_map;

	std::string idx1_fname = settings.getIndex1File();
	std::string idx2_fname = settings.getIndex2File();

	std::ifstream IDX1( idx1_fname.c_str(), std::ios::in );
	std::ifstream IDX2( idx2_fname.c_str(), std::ios::in );

	unsigned int fastq_line_part = 1;
	std::string buffer1 = "";
	std::string buffer2 = "";

	while( !IDX1.eof() and !IDX2.eof() ) {
		std::getline( IDX1, buffer1 );
		std::getline( IDX2, buffer2 );

		if ( fastq_line_part == 2 ) {
			std::string current_index = buffer1 + "-" + buffer2;

			std::map< std::string, unsigned long long int >::iterator endIter = dual_index_count_map.end();
			std::map< std::string, unsigned long long int >::iterator searchIter = dual_index_count_map.find( current_index );

			if ( endIter == searchIter ) {
				// not found, start a new one
				dual_index_count_map.insert( std::pair< std::string, unsigned long long int >( current_index, 1 ) );
			}
			else {
				dual_index_count_map[ current_index ] += 1;
			}
		}
		else if ( fastq_line_part == 4 ) {
			fastq_line_part = 0;
		}
		++fastq_line_part;
	}

	IDX1.close();
	IDX2.close();

	return dual_index_count_map;
}
