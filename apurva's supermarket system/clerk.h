/************************************************************************************

    Code by : Group A
    Code : Clerk Class. It inherits dataClass to acces data of the shop.

************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#ifndef _CLERK_H
#define _CLERK_H
#include "dataClass.h"

using namespace std;

//Class definition
class clerk : protected items {

public:

  char* get_code () { return items::get_code (); }
  /* Setter */
  float get_quantity () { return items::get_quantity (); }

  // to set item Code
  void set_code (char code [10]) { items::set_code (code); }
  // to set item name
  void set_name (char name [20]) { items::set_name (name); }
  // to set item price
  void set_price (float price) { items::set_price (price); }
  // to set item quantity
  void set_quantity (int quantity) { items::set_quantity (quantity); }

  // To display the items
  void display_item ();

};

void clerk::display_item () {

    std::cout << items::get_code () << "  " << items::get_name () << "  " << items::get_price () << "  " << items::get_quantity ();

}

#endif
