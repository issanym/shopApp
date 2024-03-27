#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <string>
class  shop;

using namespace std;

class client
{
private:
    vector <double> cartPrice;
    vector <string> cart;
    double wallet;
    int accountNum;
    double total=0;

public:
    client(int); // instanciate object and set the user's account number
    void setCart(shop &obj); // get the items and price from the user then produce the total amount
    void setWallet(); // generate/retrive user's money
    string getCart(int index);
    double getWallet();
    int getAccountNum();
    int csize();
    double ctotal();
    double price(int index);
};


/*
 * including class A in class B
 * and class B in class A result in some weird errors
 * instead in .h file of class A define class B
 * as in [ class B; ]
*/

#endif // CLIENT_H
