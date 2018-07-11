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

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

//#include <boost/utility.hpp>
//#include <boost/regex.hpp>

namespace fastcgi {

class Config;
class ComponentSet;
class Handler;
class Request;
class RequestFilter;

class HandlerSet
{
public:
	struct HandlerDescription {
		typedef std::vector<std::pair<std::string, std::shared_ptr<RequestFilter> > > FilterArray;
		FilterArray filters;
		std::vector<Handler*> handlers;
		std::string poolName;
		std::string id;
	};
	typedef std::vector<HandlerDescription> HandlerArray;

public:
	HandlerSet();
	virtual ~HandlerSet();

	void init(const Config *config, const ComponentSet *componentSet);

	const HandlerSet::HandlerDescription* findURIHandler(const Request *request) const;
	void findPoolHandlers(const std::string &poolName, std::set<Handler*> &handlers) const;
	std::set<std::string> getPoolsNeeded() const;

private:
	HandlerArray handlers_;


private:
	HandlerSet(const HandlerSet&) = delete;
	HandlerSet&operator=(const HandlerSet&) = delete;


};

} // namespace fastcgi

