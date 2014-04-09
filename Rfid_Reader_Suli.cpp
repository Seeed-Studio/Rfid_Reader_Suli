/*
  Rfid_Reader_Suli.cpp
  
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


#include "Rfid_Reader_Suli.h"

// set baudrate to 9600
void * uart_device;
int uart_num;

void rfid_reader_init(void * uart, int16 num)
{
    uart_device = uart;
    uart_num = num;
    suli_uart_init(uart_device, uart_num, 9600);
}

// if get data
uint8 rfid_reader_available()
{
    return suli_uart_readable(uart_device, uart_num);
}

// read data from rfid reader
uint8 rfid_reader_read_data(uint8 *dest_storage)  //return data length
{

    int len = 0;
    
    while(rfid_reader_available())
    {
        dest_storage[len++] = suli_uart_read_byte(uart_device, uart_num);
    }

    return len;    
}

// write buf to rfid reader
void rfid_reader_write_data(uint8 *data, uint8 len)
{
    suli_uart_send(uart_device, uart_num, data, len);
}