//  $Id: StartPos.hh,v 1.1 2000/08/04 20:10:41 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
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
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef STARTPOS_HH
#define STARTPOS_HH

#include "EditorObj.hh"

class StartPos : public EditorObj
{
private:
  
public:
  ///
  StartPos(int arg_x_pos, int arg_y_pos);
  ///
  virtual ~StartPos();
  ///
  virtual void   save(std::ofstream* plf, std::ofstream* psm);
  ///
  virtual void   save_xml(std::ofstream* xml);
  ///
  virtual EditorObj* duplicate();
};

#endif

/* EOF */
