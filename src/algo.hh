//  $Id: algo.hh,v 1.11 2000/06/20 17:52:48 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA. 

#ifndef ALGO_HH
#define ALGO_HH

#include <string>

#ifndef WIN32
#include <unistd.h>
#else /* WIN32 */
#include <io.h>
#include <iostream>
#define F_OK 0
#endif /* WIN32 */

/** This file contains different algorithmens and other usefull
    routines which are completly indepentantly of the game. */
#define frand() ((double) rand() / (RAND_MAX+1.0))

/** Check if the two given rectangles collide.
    @return Return true if they collide. */
bool rect_col(int ax1, int ax2, int ay1, int ay2,
              int bx1, int bx2, int by1, int by2);

/** Add the tailing string to a directory name, if it is not allready
    there. */
std::string add_slash(std::string& str);

/// Returns the directory part of a filename.
std::string get_directory(std::string s);

///
char*  tolowerstr(char*);

/** Search for a filename in the given path.
    @return The complete filename when found, else the given filename 
    @param path A colon seperated list of directories 
    @param filename An uncomplete/relative filename, it might consist
           of directories */
std::string find_file(const std::string& path, const std::string& filename);

//std::string basename(std::string filename);
/*template<class T> inline std::string to_string(const T& n)
{
 std::ostringstream tmp;
 tmp << n;
 return tmp.str();
 }*/
/*
template<class T> inline void from_string(const std::string& s, T& n)
{
 std::istringstream tmp(s);
 tmp >> n;
}
*/

#endif

/* EOF */
