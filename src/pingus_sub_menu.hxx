//  $Id: pingus_sub_menu.hxx,v 1.4 2002/07/30 14:57:25 grumbel Exp $
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

#ifndef HEADER_PINGUS_PINGUS_SUB_MENU_HXX
#define HEADER_PINGUS_PINGUS_SUB_MENU_HXX

#include "gui/gui_manager.hxx"

class CL_Key;
class CL_InputDevice;
class PingusMenuManager;

class PingusSubMenu : public GUI::GUIManager
{
protected:
  PingusMenuManager* manager;

public:
  PingusSubMenu (PingusMenuManager* m);
  virtual ~PingusSubMenu ();

  /// load all the data which is needed for the menu
  virtual void preload () =0;

  /// Return a handle to the parent menu manager
  PingusMenuManager* get_manager () { return manager; }
};

#endif

/* EOF */
