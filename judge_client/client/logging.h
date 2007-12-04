/*
 * Copyright 2007 Xu, Chuan <xuchuan@gmail.com>
 *
 * This file is part of ZOJ Judge Server.
 *
 * ZOJ Judge Server is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * ZOJ Judge Server is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ZOJ Judge Server; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __LOGGING_H
#define __LOGGING_H

#include <string>
#include <sstream>
#include <errno.h>
#include <syslog.h>

using namespace std;

#define DEBUG 0
#define ERROR 1
#define WARNING 2
#define INFO 3
#define FATAL 4
#define SYSCALL_ERROR -1
#define LOG(level) Log(__FILE__, __LINE__, level).stream()

class Log {
    public:
        Log(const char* filename, int lineNumber, int level);
        ~Log();

        ostream& stream() { return this->messageStream; }

    private:
        const char* filename;
        int lineNumber;
        int level;
        ostringstream messageStream;
};

#endif