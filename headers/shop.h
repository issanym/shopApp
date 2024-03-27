#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
#include "client.h"

using namespace std;

class shop
{
private:
    const string items[10] = { "Grapes", "Apples", "Potatoes", "Carrots", "Kiwi", "Banana", "Pear", "Mango", "Pepper", "Onion" };
    const double prices[10] = { 5.23, 0.50, 3.00, 5.07, 4.87, 2.65, 3.44, 4.45, 3.33, 1.25};
    vector <string> usrItems;
    vector <double> cPrice;

public:
    shop(); // instanciate object and display inventory
    string getInventory(int index); // return inventory
    double getPrices(int index);
    void getInvoice(client &obj); // generate invoice from cart
    void setPayment(client &obj); // recieve total amnt and account num
};

#endif // SHOP_H
