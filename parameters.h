/*
 * parameters.h
 *
 *  Created on: Apr 29, 2019
 *      Author: eli_lab
 */

// standard libraries
#include <string>

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

class Parameters {
	public:
		Parameters( int argc, char *argv[] );
		virtual ~Parameters();

		const std::string& getIndex1File() const {
			return index1_file;
		}

		void setIndex1File(const std::string& index1File) {
			index1_file = index1File;
		}

		const std::string& getIndex2File() const {
			return index2_file;
		}

		void setIndex2File(const std::string& index2File) {
			index2_file = index2File;
		}

		const unsigned int getCountThreshold() const {
			return count_threshold;
		}

		void setCountThreshold(int threshold) {
			count_threshold = threshold;
		}

	private:
		// input files
		std::string index1_file;
		std::string index2_file;

		unsigned long long int count_threshold;
};

void printUsage();

#endif /* PARAMETERS_H_ */
