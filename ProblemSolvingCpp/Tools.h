#ifndef __PS_TOOLS_H__
#define __PS_TOOLS_H__

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>

std::ostream& operator << (std::ostream &os, std::list<std::string> const &list)
{
	os << "{ ";
	std::copy (list.begin (), list.end (), std::ostream_iterator<std::string> (os, " "));
	os << "}";
	return os;
}

#endif // __PS_TOOLS_H__