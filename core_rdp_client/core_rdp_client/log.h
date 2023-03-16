#pragma once
#include <windows.h>

#include <string>

namespace u_log
{
	bool initialize();
	void write(std::string buf);
	void close();

	void err(std::string s);
	void warning(std::string s);
	void info(std::string s);
}
