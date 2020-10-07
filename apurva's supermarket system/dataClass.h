/***********************************************************************************

    Code by : Group A
    Code : Data set class. Class which is used to acces data of shop from files.
           It contains getters and setters to acces and set the values of the
           retailers data.

***********************************************************************************/

#include <string>
#include <cstring>
#include <iostream>
#ifndef _DATACLASS_H
#define _DATACLASS_H

 // Class definition
 class items {

      char item_code [10];
      char item_name [20];
      float item_price;
      int item_quantity;

  protected:

      /* Getters */

      // to get item Code
      char* get_code () { return item_code; }
      // to get item name
      char* get_name () { return item_name; }
      // to get item price
      float get_price () { return item_price; }
      // to get item quantity
      int get_quantity () { return item_quantity; }

      /* Setter */

      // to set item Code
      void set_code (char code [10]) { std::strcpy (item_code, code); }
      // to set item name
      void set_name (char name [20]) { std::strcpy (item_name, name); }
      // to set item price
      void set_price (float price) { item_price =  price; }
      // to set item quantity
      void set_quantity (int quantity) { item_quantity =  quantity; }

 };

#endif
