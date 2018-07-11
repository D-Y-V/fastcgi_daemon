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
//#include <boost/utility.hpp>
#include <memory>

namespace fastcgi {

class Config;
class Component;

class ComponentContext  {
public:
	virtual ~ComponentContext();

	virtual const Config* getConfig() const = 0;
	virtual std::string getComponentXPath() const = 0;

	template<typename T>
	T* findComponent(const std::string &name) {
		return dynamic_cast<T*>(findComponentInternal(name));
	}

protected:
	virtual Component* findComponentInternal(const std::string &name) const = 0;

private:
    //ComponentContext(const ComponentContext&) = delete; //TODO tempporary allow default constructor
    ComponentContext&operator=(const ComponentContext&) = delete;

};

class Component  {
public:
	Component(ComponentContext *context);
	virtual ~Component();

	virtual void onLoad() = 0;
	virtual void onUnload() = 0;

protected:
	ComponentContext* context();
	const ComponentContext* context() const;

private:
	ComponentContext *context_;

	Component(const Component&) = delete;
    Component&operator=(const Component&) = delete;
};

} // namespace fastcgi
