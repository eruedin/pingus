//  $Id: SmallMap.cc,v 1.3 2000/02/26 16:15:42 grumbel Exp $
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

#include "PinguHolder.hh"
#include "Display.hh"
#include "Playfield.hh"
#include "World.hh"
#include "SmallMap.hh"

SmallMap::SmallMap()
{
  sur = 0;
  width = 175;
  height = 75;
  scroll_mode = false;
}

SmallMap::~SmallMap()
{
  delete sur;
}
  
void
SmallMap::init()
{
  CL_Canvas*  canvas;
  ColMap* colmap;
  World* world = client->get_server()->get_world();
  unsigned char* buffer;
  unsigned char* cbuffer;
  int tx, ty;

  colmap = world->get_colmap(); 
  buffer = colmap->get_data();

  canvas = new CL_Canvas(width, height);
 
  canvas->lock();
  
  cbuffer = static_cast<unsigned char*>(canvas->get_data());

  for(int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
	{
	  tx = x * colmap->get_width() / width;
	  ty = y * colmap->get_height() / height;

	  switch(buffer[tx + (ty * colmap->get_width())])
	    {
	    case ColMap::NOTHING:
	      cbuffer[4 * ((y * width) + x) + 0] = 150;
	      cbuffer[4 * ((y * width) + x) + 1] = 0;
	      cbuffer[4 * ((y * width) + x) + 2] = 0;
	      cbuffer[4 * ((y * width) + x) + 3] = 0;
	      break;
	    case ColMap::SOLID:
	      cbuffer[4 * ((y * width) + x) + 0] = 255;
	      cbuffer[4 * ((y * width) + x) + 1] = 100;
	      cbuffer[4 * ((y * width) + x) + 2] = 100;
	      cbuffer[4 * ((y * width) + x) + 3] = 100;
	      break;
	    default:
	      cbuffer[4 * ((y * width) + x) + 0] = 255;
	      cbuffer[4 * ((y * width) + x) + 1] = 200;
	      cbuffer[4 * ((y * width) + x) + 2] = 200;
	      cbuffer[4 * ((y * width) + x) + 3] = 200;
	      break;
	    }
	}
    }

  canvas->unlock();
  
  sur = CL_Surface::create(canvas, true);

  x_pos = 0;
  y_pos = CL_Display::get_height() - sur->get_height();

  rwidth = CL_Display::get_width() * width / client->get_server()->get_world()->get_colmap()->get_width();
  rheight = CL_Display::get_height() * height / client->get_server()->get_world()->get_colmap()->get_height();
}

void
SmallMap::set_client(Client* c)
{
  client = c;
  init();
}

void
SmallMap::draw()
{
  Playfield* playfield = client->get_playfield();

  int x_of = playfield->get_x_offset();
  int y_of = playfield->get_y_offset();

  sur->put_screen(0, CL_Display::get_height() - sur->get_height()); 
  
  x_of = -x_of * width / client->get_server()->get_world()->get_colmap()->get_width();
  y_of = -y_of * height / client->get_server()->get_world()->get_colmap()->get_height();

  Display::draw_rect(x_of, y_of + CL_Display::get_height() - sur->get_height(),
		     x_of + rwidth, y_of + rheight + CL_Display::get_height() - sur->get_height(),
		     0.0, 1.0, 0.0, 1.0);

  draw_pingus();
}

void
SmallMap::draw_pingus()
{
  int x;
  int y;
  PinguHolder* pingus = client->get_server()->get_world()->get_pingu_p();

  for(list<Pingu*>::iterator i = pingus->begin(); i != pingus->end(); i++)
    {
      //FIXME: Replace this with put pixel
      x = x_pos + ((*i)->get_x() * width / client->get_server()->get_world()->get_colmap()->get_width());
      y = y_pos + ((*i)->get_y() * height / client->get_server()->get_world()->get_colmap()->get_height());

      CL_Display::draw_line(x, y, x, y-1, 1.0, 0.0, 0.0, 1.0);
    }
}

void
SmallMap::let_move()
{
  int cx, cy;
  ColMap* colmap = client->get_server()->get_world()->get_colmap();
  
  if (scroll_mode)
    {
      cx = (CL_Mouse::get_x() - x_pos) * colmap->get_width() / width;
      cy = (CL_Mouse::get_y() - y_pos) * colmap->get_height() / height ;

      client->get_playfield()->set_viewpoint(cx, cy);

      cout << "scrolling...cx:" << cx << " cy:" << cy << endl;
    }
}

bool
SmallMap::mouse_over()
{
  if (CL_Mouse::get_x() > x_pos && CL_Mouse::get_x() < x_pos + width
      && CL_Mouse::get_y() > y_pos && CL_Mouse::get_y() < y_pos + height)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void
SmallMap::button_press(const CL_Key& key)
{
  switch(key.id)
    {
    case 0:
      if (mouse_over())
	{
	  scroll_mode = true;
	}
      break;
    }
}

void
SmallMap::button_release(const CL_Key& key)
{
  switch(key.id)
    {
    case 0:
      scroll_mode = false;
      break;
    }
}

/* EOF */

