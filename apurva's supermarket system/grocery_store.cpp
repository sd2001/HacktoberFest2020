/*********************************************************************************

    Code by : Group A
    Code : Main grocery stoe interface

*********************************************************************************/

#include <iostream>
#include <fstream>
#include "clerk.h"
#include "customer.h"

 void customer_acces ();
 void clerk_acces ();
 void test ();

 using namespace std;

 int main(int argc, char const *argv[]) {

     int acc;

     do {

         system ("clear");

         std::cout << "\n\n\t\t\t Access Menu";
         std::cout << "\n\n\t 1. Customer";
         std::cout << "\n\t 2. Clerk";
         std::cout << "\n\t 3. Exit";
         std::cout << "\n\n\t Enter the choice : ";
         std::cin >> acc;

         switch (acc) {

             case 1 : customer_acces ();
                      break;

             case 2 : clerk_acces ();
                      break;

             case 3 : exit (0);

             default : std::cout << "\n\t Wrong Choice!!" << '\n';
                       cin.ignore ();
                       getchar ();

         }

     } while (1);

     return 0;
 }

 void customer_acces () {

     int option;
     fstream item, cart;
     customer cstmr;

     do {

         system ("clear");

         std::cout << "\n\n\n\t\t\t\t Welcome to ABC grocery store : customer";
         std::cout << "\n\n\t\t Menu";
         std::cout << "\n\n\t 1. Display item list";
         std::cout << "\n\t 2. Add item to cart";
         std::cout << "\n\t 3. Delete item from cart";
         std::cout << "\n\t 4. Display cart";
         std::cout << "\n\t 5. Bill";
         std::cout << "\n\t 6. Exit";
         std::cout << "\n\n\t Enter choice : ";
         std::cin >> option;

         switch (option) {

             case 1 : item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary);
                      item.seekg (0);
                      system ("clear");
                      while (1) {
                          item.read ((char*) &cstmr, sizeof (cstmr));
                          if (item.eof ())
                            break;
                          cstmr.display_catalog ();
                      }
                      item.close ();
                      break;

             case 2 :{ char ans = 'y';
                       int flag = 0;
                       char cd [10];
                       int qty;
                       item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary);
                       cart.open("/home/apurva/Desktop/c++ project/cart.txt", ios::out | ios::app);

                       do {

                           cout<<"\nEnter the Code of the item";
                           cin>>cd;
                           item.seekg (0);
                           while (1) {
                               item.read((char*) &cstmr, sizeof(cstmr));
                               if (item.eof ())
                                break;
                               if(!std::strcmp (cstmr.get_code(), cd)) {
                                   flag++;
                                   cstmr.display_catalog ();
                                   std::cout << "\n\n\t Enter the quantity needed : ";
                                   cin >> qty;
                                   while (cstmr.get_quantity () < qty) {
                                       std::cout << "\n\n\t The quantity entered is not possible" << '\n';
                                       std::cout << "Max possible quantity is : " << cstmr.get_quantity () << '\n';
                                       std::cout << "Enter new quantity : ";
                                       std::cin >> qty;
                                   }
                                   cstmr.set_quantity(qty);
                                   cart.write((char*) &cstmr, sizeof(cstmr));
                                   std::cout << "\n\t Item added" << '\n';
                               }
                           }
                           if (!flag) {
                               std::cout << "\n\t Item with that code does not exist" << '\n';
                           }
                           flag= 0;
                           std::cout << "\n\t Do you wanna add more items? (Y/N) : ";
                           std::cin >> ans;
                       } while (ans == 'y' || ans == 'Y');
                       item.close();
                       cart.close();
                       break;
                   }

             case 3 :{ char cd [10];
                       char found='f',confirm='n';
                       cart.open("/home/apurva/Desktop/c++ project/cart.txt",ios::in);
                       ofstream fout;
                       fout.open("/home/apurva/Desktop/c++ project/temp.txt",ios::out);
                       cout<<"\nEnter the code of the item you want to be deleted";
                       cin>>cd;
                       while(1) {
                           cart.read((char*)&cstmr,sizeof(cstmr));
                           if (cart.eof ())
                            break;
                           if(!std::strcmp (cstmr.get_code(), cd)) {
                               found='t';
                               cout<<"\nItem Code="<<cstmr.get_code();
                               cout<<"\nItem Name="<<cstmr.get_name();
                               cout<<"\nItem quantity="<<cstmr.get_quantity();
                               cout<<"\nItem Price="<<cstmr.get_price();
                               cout<<"\nAre you sure you want to delete this item?[y/n]";
                               cin>>confirm;
                               if(confirm=='n')
                                 fout.write((char*)&cstmr,sizeof(cstmr));
                             }
                             else
                                 fout.write((char*)&cstmr,sizeof(cstmr));
                             if(found=='f')
                             cout<<"\nItem not found";
                             cart.close();
                             fout.close();
                             remove("/home/apurva/Desktop/c++ project/cart.txt");
                             rename("/home/apurva/Desktop/c++ project/temp.txt","/home/apurva/Desktop/c++ project/cart.txt");
                             break;
                         }
                     }

             case 4 : cart.open("/home/apurva/Desktop/c++ project/cart.txt", ios::in);
                      cart.seekg (0);
                      while(1) {
                          cart.read((char*) &cstmr, sizeof(cstmr));
                          if (cart.eof ())
                             break;
                          cout<<"\nItem Code="<<cstmr.get_code();
                          cout<<"\nItem Name="<<cstmr.get_name();
                          cout<<"\nItem Quantity="<<cstmr.get_quantity();
                          cout<<"\nItem Price="<<cstmr.get_price();
                      }
                      cart.close();
                      break;

             case 5 :{ float sum = 0;
                       item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary | ios::out | ios::ate);
                       cart.open("/home/apurva/Desktop/c++ project/cart.txt", ios::in);
                       clerk clrk;
                       cart.seekg (0);
                       while(1) {
                           cart.read((char*)&cstmr,sizeof(cstmr));
                           if (cart.eof ())
                              break;
                           cstmr.display_catalog ();
                           std::cout << "  " << cstmr.get_quantity () << '\n';
                           item.seekg (0);
                           while (1) {
                               item.read ((char*) &clrk, sizeof (clrk));
                               if (item.eof ())
                                  break;
                               if (!std::strcmp (clrk.get_code (), cstmr.get_code ())) {
                                   clrk.set_quantity (clrk.get_quantity () - cstmr.get_quantity ());
                                   item.seekp (-sizeof (clrk), ios::cur);
                                   item.write ((char*) &clrk, sizeof (clrk));
                                   break;
                               }
                           }
                           sum+=(cstmr.get_price() * cstmr.get_quantity ());
                       }
                       cout<<"\nThe amount is $"<<sum;
                       cart.close ();
                       item.close ();
                       remove ("/home/apurva/Desktop/c++ project/cart.txt");
                       break;
                   }

             case 6 : return;

             default : std::cout << "\n\t Wrong choice!" << '\n';

         }

         cin.ignore ();
         getchar ();

     } while (1);

 }

 void clerk_acces () {

     int option;
     clerk clrk;
     char code [10], name [20], ans;
     float price;
     int quantity;
     int size, flag = 0, pos;

     fstream item;
     item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary | ios::out | ios::app);
     item.close ();

     do {

         system ("clear");

         std::cout << "\n\n\n\t\t\t\t Welcome to ABC grocery store : Admin Access ";
         std::cout << "\n\n\t\t Menu";
         std::cout << "\n\n\t 1. Display item list";
         std::cout << "\n\t 2. Add items";
         std::cout << "\n\t 3. Delete item";
         std::cout << "\n\t 4. Modify item";
         std::cout << "\n\t 5. Exit";
         std::cout << "\n\n\t Enter the choice : ";
         std::cin >> option;

         switch (option) {

             case 1 : item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary);
                      if (item.fail ()) {
                          std::cout << "\nfile couldn't open " << '\n';
                          std::cin.ignore ();
                          getchar ();
                          continue;
                      }
                      item.seekg (0, ios::beg);
                      system ("clear");
                      std::cout << "\n\n code  name  price  quantity " << '\n';
                      while (1) {
                          item.read ((char*) &clrk, sizeof (clrk));
                          if (item.eof ())
                            break;
                          clrk.display_item ();
                          std::cout << '\n';
                      }
                      item.close ();
                      break;

             case 2 : flag = 0;
                      item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary);
                      item.seekg (0, ios::beg);
                      cout<<"\n\n\tPlease Enter the Item Code : ";
                      cin >>code;
                      while (1) {
                          item.read ((char*) &clrk, sizeof (clrk));
                          if (item.eof ())
                            break;
                          if (!std::strcmp (clrk.get_code (), code))
                              flag++;
                      }
                      if (flag != 0) {
                          std::cout << "\n\n\t Entered code already exists" << '\n';
                          item.close ();
                          break;
                      }
                      item.close ();
                      cout<<"\n\tPlease Enter The Item Name : ";
                      cin >>name;
                      cout<<"\n\tPlease Enter The Item Price : ";
                      cin>>price;
                      cout<<"\n\tPlease Enter The Item Quantity : ";
                      cin>>quantity;
                      clrk.set_code (code);
                      clrk.set_name (name);
                      clrk.set_price (price);
                      clrk.set_quantity (quantity);
                      item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::binary | ios::out | ios::app);
                      item.write ((char*) &clrk, sizeof (clrk));
                      std::cout << "\n\t written in file" << '\n';
                      item.close ();
                      break;

             case 3 :{
                      item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary);
                      ofstream file;
                      file.open ("/home/apurva/Desktop/c++ project/temp.dat", ios::out | ios::binary | ios::app);
                      std::cout << "\n\n\t Enter the code of item which you wanna delete : ";
                      std::cin >> code;
                      item.seekg (0);
                      while (1) {
                          flag = 0;
                          item.read ((char*) &clrk, sizeof (clrk));
                          if (item.eof ())
                            break;
                          if (!std::strcmp (clrk.get_code (), code)) {
                              clrk.display_item ();
                              std::cout << "\n\t Do you wanna delete it ? (y/n) : ";
                              std::cin >> ans;
                              if (ans == 'y' || ans == 'Y') {
                                std::cout << "Deleted" << '\n';
                                flag++;
                              }
                          }
                          if (!flag)
                            file.write ((char*) &clrk, sizeof (clrk));
                      }
                      item.close ();
                      file.close ();
                      remove ("/home/apurva/Desktop/c++ project/items.dat");
                      rename ("/home/apurva/Desktop/c++ project/temp.dat", "/home/ankit/Desktop/c++ project/items.dat");
                      break;
                  }

             case 4 : item.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary | ios::out | ios::ate);
                      std::cout << "\n\n\t Enter the code of item you wanna modify : ";
                      std::cin >> code;
                      flag = 0;
                      item.seekg (0);
                      while (1) {
                          pos = item.tellg ();
                          item.read ((char*) &clrk, sizeof (clrk));
                          if (item.eof ())
                            break;
                          if (!std::strcmp (clrk.get_code (), code)) {
                              clrk.display_item ();
                              std::cout << "\n\n\t Enter modified details : " << '\n';
                              std::cout << "\n Enter modified code : ";
                              std::cin >> code;
                              std::cout << "\n Enter modified name : ";
                              std::cin >> name;
                              std::cout << "\n Enter the modified price : ";
                              std::cin >> price;
                              std::cout << "\n Enter the modified quantity : ";
                              std::cin >> quantity;
                              flag++;
                              break;
                          }
                      }
                      if (flag == 0) {
                        std::cout << "\n\t Item does not exist" << '\n';
                        item.close ();
                        break;
                      }
                      item.seekp (pos);
                      clrk.set_code (code);
                      clrk.set_name (name);
                      clrk.set_price (price);
                      clrk.set_quantity (quantity);
                      item.write ((char*) &clrk, sizeof (clrk));
                      std::cout << "\n\t Modified ";
                      item.close ();
                      break;

             case 5 : return;

             default : std::cout << "\n\t Wrong choice!! " << '\n';

         }

         std::cin.ignore ();
         getchar ();

     } while (1);

 }

 void test () {
     ifstream fin;
     clerk c;
     fin.open ("/home/apurva/Desktop/c++ project/items.dat", ios::in | ios::binary);
     int count;
     fin.seekg (0);
     while (!fin.eof ()) {
         std::cout << fin.tellg () << '\n';
         fin.read ((char*) &c, sizeof (c));
         c.display_item ();
         std::cout << '\n';
         std::cout << fin.tellg () << '\n';
     }
     fin.close ();
 }
