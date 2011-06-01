#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>

/* Authors:
 *   Corsin Camichel <cocaman@gmail.com>
 *
 * Copyright (C) 2011 Corsin Camichel
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
*/
bool check(std::string str) {
	std::string::reverse_iterator rit;
	std::string reversed, sLower;
	std::transform(str.begin(), str.end(), std::back_inserter(sLower), tolower);

	for (rit = sLower.rbegin() ; rit < sLower.rend(); rit++) {
		reversed += *rit;
	}
	return !(sLower == reversed);
}

int main() {

	std::istream_iterator<std::string> eof;

	std::cout << "Please enter your text:" << std::endl;
	std::vector<std::string> ves(std::istream_iterator<std::string>(std::cin),eof);
	std::vector<std::string> res;

	std::remove_copy_if(ves.begin(),ves.end(), std::back_inserter(res), check);

	std::cout << std::endl;
	std::cout << "Palindromes are: " << std::endl;
	std::copy(res.begin(), res.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	
	std::cout << "============" << std::endl;
	
	return 0;
}
