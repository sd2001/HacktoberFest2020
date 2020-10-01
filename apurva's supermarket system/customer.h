/************************************************************************************

    Code by : Group A
    Code : Customer class. It inherits dataClass to acces data of the shop.

************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "dataClass.h"

 using namespace std;

 // Class definition
 class customer : protected items {

 public:

     /* Getters */

     // to get item Code
     char* get_code () { return items::get_code (); }
     // to get item name
     char* get_name () { return items::get_name (); }
     // to get item price
     float get_price () { return items::get_price (); }
     // to get item quantity
     int get_quantity () { return items::get_quantity (); }

     /* Setter */
     
     // to set item quantity
     void set_quantity (int quantity) { items::set_quantity (quantity); }

     // To display the object values
     void display_catalog ();

 };

 void customer::display_catalog () {

     std::cout << '\n' << items::get_code () << '\t' << items::get_name () << '\t' << items::get_price ();

}

#endif
