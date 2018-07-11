// Fastcgi Daemon - framework for design highload FastCGI applications on C++
// Copyright (C) 2011 Ilya Golubtsov <golubtsov@yandex-team.ru>
// Copyright (C) 2017 Kirill Shmakov <menato@yandex-team.ru>

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#pragma once

#include <string>
#include <vector>
//#include <boost/utility.hpp>

#include <fastcgi2/data_buffer.h>

namespace fastcgi {

class Range;

class StringUtils  {
public:
	static std::string urlencode(const Range &val);
	static std::string urlencode(const std::string &val);

	static std::string urldecode(const Range &val);
	static std::string urldecode(DataBuffer data);
	static std::string urldecode(const std::string &val);

	typedef std::pair<std::string, std::string> NamedValue;

	static void parse(const Range &range, std::vector<NamedValue> &v);
	static void parse(const std::string &str, std::vector<NamedValue> &v);
	static void parse(DataBuffer data, std::vector<NamedValue> &v);

	static const std::string EMPTY_STRING;

private:
	static void urldecode(const Range &range, std::string &result);

	StringUtils();
	virtual ~StringUtils();

private:
	StringUtils(const StringUtils&) = delete;
	StringUtils&operator=(const StringUtils&) = delete;



};

class HttpDateUtils  {
public:
	static time_t parse(const char *value);
	static std::string format(time_t value);

private:
	HttpDateUtils();
	virtual ~HttpDateUtils();

private:
	HttpDateUtils(const HttpDateUtils&) = delete;
	HttpDateUtils&operator=(const HttpDateUtils&) = delete;


};

} // namespace fastcgi
