//  $Id: Controllable.cc,v 1.1 2001/04/14 11:45:01 grumbel Exp $
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

#include "Controllable.hh"

Controllable::Controllable (boost::shared_ptr<Controller> arg_controller)
  : controller (arg_controller)
{
  std::cout << "Constructing Controllable" << std::endl;
  left_press_slot   = controller->left->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_left_press));
  middle_press_slot = controller->middle->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_middle_press));
  right_press_slot  = controller->right->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_right_press));
  std::cout << "Constructing Controllable -1" << std::endl;
  pause_press_slot   = controller->pause->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_pause_press));
  abort_press_slot   = controller->abort->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_abort_press));
  std::cout << "Constructing Controllable 0" << std::endl;
  //scroll_left_press_slot  = controller->scroll_left->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_scroll_left_press));
  //scroll_right_press_slot = controller->scroll_right->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_scroll_right_press));
  std::cout << "Constructing Controllable 1.56" << std::endl;

  /*
  next_action_press_slot     = controller->next_action->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_next_action_press));
  previous_action_press_slot = controller->previous_action->signal_pressed.connect(CL_CreateSlot (this, &Controllable::on_previous_action_press));
  std::cout << "Constructing Controllable 1" << std::endl;
  

  left_release_slot   = controller->left->signal_released.connect(CL_CreateSlot (this, &Controllable::on_left_release));
  middle_release_slot = controller->middle->signal_released.connect(CL_CreateSlot (this, &Controllable::on_middle_release));
  right_release_slot  = controller->right->signal_released.connect(CL_CreateSlot (this, &Controllable::on_right_release));
  std::cout << "Constructing Controllable 2" << std::endl;

  pause_release_slot   = controller->pause->signal_released.connect(CL_CreateSlot (this, &Controllable::on_pause_release));
  abort_release_slot   = controller->abort->signal_released.connect(CL_CreateSlot (this, &Controllable::on_abort_release));

  scroll_left_release_slot  = controller->scroll_left->signal_released.connect(CL_CreateSlot (this, &Controllable::on_scroll_left_release));
  scroll_right_release_slot = controller->scroll_right->signal_released.connect(CL_CreateSlot (this, &Controllable::on_scroll_right_release));

  next_action_release_slot     = controller->next_action->signal_released.connect(CL_CreateSlot (this, &Controllable::on_next_action_release));
  previous_action_release_slot = controller->previous_action->signal_released.connect(CL_CreateSlot (this, &Controllable::on_previous_action_release));
  */
  std::cout << "Constructing Controllable done" << std::endl;
}

Controllable::~Controllable ()
{
}

/* EOF */
