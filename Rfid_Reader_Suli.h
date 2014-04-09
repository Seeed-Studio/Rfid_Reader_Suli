/*
  Rfid_Reader_Suli.h
  
  This is a Suli-compatible Library. 
  
  For more information please refer to http://www.seeedstudio.com/wiki/Grove_-_125KHz_RFID_Reader
  
  2014 Copyright (c) Seeed Technology Inc.  All right reserved.
  
  Author:Loovee
  2014-4-9
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __RFID_READER_H__
#define __RFID_READER_H__

#include "Suli.h"

void rfid_reader_init(void * uart, int16 num);          // initialize
uint8 rfid_reader_available();                          // if uart data available
uint8 rfid_reader_read_data(uint8 *dest_storage);       // return data length
void rfid_reader_write_data(uint8 *data, uint8 len);    // write a buff to Uart

#endif
