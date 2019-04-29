/*
 * parameters.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: eli_lab
 */

// standard libraries
#include <getopt.h>
#include <cstdlib>
#include <iostream>
#include <string>

// project libraries
#include "parameters.h"
#include "helper.h"

Parameters::Parameters( int argc, char *argv[] ): index1_file( "" ), index2_file( "" ), count_threshold( 0 ) {
	// we're using the c getopt library for parsing.
	// gotta setup the structures
	// we'll use both short options and long options

	if ( argc == 1 ) {
		printUsage();
	}

	const char* short_opts = "a:b:c:h";

	//static struct option long_options[] = {
	const option long_options[] = {
			{ "index1",           required_argument, 0, 'a' },
			{ "index2",           required_argument, 0, 'b' },
			{ "threshold",        required_argument, 0, 'c' },
			{ "help",             no_argument,       0, 'h' },
			{ 0,                  no_argument,       0,  0  }
	};

	while( true ) {
		const int opt = getopt_long( argc, argv, short_opts, long_options, 0 );

		if ( -1 == opt )
		{
			break;
		}

		switch ( opt )
		{
		case 'a':
			setIndex1File( optarg );
			break;
		case 'b':
			setIndex2File( optarg );
			break;
		case 'c':
			setCountThreshold( std::stoull( optarg ) );
			break;
		case 'h': // -h or --help
		case '?': // unrecognized option
			printUsage();
			break;
		default:
			break;
		}
	}


	// make sure we at least have read 1
	if ( getIndex1File().length() == 0 ) {
		logError( std::string( "Index 1 file required but not specified." ) );
	}
	else if ( getIndex2File().length() == 0 ) {
		logError( std::string( "Index 2 file required but not specified." ) );
	}
	else if ( getCountThreshold() < 1 ) {
		logError( std::string( "A count threshold (minimum count for output) > 0 is required." ) );
	}
}

Parameters::~Parameters() {
	// TODO Auto-generated destructor stub
}

void printUsage() {
	std::cout << PROGNAME + std::string( " v" ) + VERSION << std::endl;
	std::cout << std::endl;
	std::cout << std::string( "Usage:" ) << std::endl;
	std::cout << std::string( "count_dual_indexes --index1 <FASTQ> --index2 <FASTQ> --threshold <#>" ) << std::endl;
	std::cout << std::string( "--index1: Index1 FASTQ file (required)" ) << std::endl;
	std::cout << std::string( "--index2: Index2 FASTQ file (required)" ) << std::endl;
	std::cout << std::string( "--threshold: Minimum count to print dual index (required; >0)" ) << std::endl;
	std::cout << std::string( "--help" ) << std::endl;
	std::cout << std::endl;

	std::exit( 0 );
}
