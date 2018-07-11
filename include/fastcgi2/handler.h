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

//#include <boost/any.hpp>
//#include <boost/utility.hpp>

#include <map>
#include <string>
#include <vector>
#include <any>

namespace fastcgi {

class Request;

class HandlerContext {
public:
    virtual ~HandlerContext();

    virtual std::any getParam(const std::string &name) const = 0;
    virtual void setParam(const std::string &name, const std::any &value) = 0;
};

class Handler {
public:
    Handler();
    virtual ~Handler();

    virtual void onThreadStart();
    virtual void handleRequest(Request *req, HandlerContext *context) = 0;

private:
    Handler(const Handler&) = delete;
    Handler&operator=(const Handler&) = delete;


};

} // namespace fastcgi
