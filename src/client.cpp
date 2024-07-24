#include "client.h"
#include "shop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


client::client(int accnum) /* instanciate object and se the user's account number */
{
    accountNum = accnum;
}

void client::setCart(shop& obj) /* get the items and price from the user then produce the total amount */
{
    string items[10];
    int prices[10];

    for(int i=0; i<10; i++)
    {
        items[i] = obj.getInventory(i);
        prices[i] = obj.getPrices(i);
    }                                   // add multiple choice for one item

    while(true)
    {
        cout << "Add items to your cart (P.S respect capitalization) : ";
        string itm;
        cin >> itm;

        cout << "\n";

        for (int i = 0; i<10; i++)
        {
            if (itm == items[i])
            {
                total = total + prices[i];
                cart.push_back(itm);
                cartPrice.push_back(prices[i]);
                i=11;
            }
        }

        char decision;
        cout << "Continue shopping(y/n): ";
        cin>> decision;
        if ( decision != 'y')
        {
            break;
        }
    }
}

//========================================================================================================================
//         || USER WILL NOT DIRECTLY INTERACT WITH THESE METHODS THEY'RE MENT FOR CLASS-TO-CLASS INTERACTION !!!!!!  ||
//========================================================================================================================

string client::getCart(int index) // It doesnt "get" the cart, it "sends" it to shop
{
    return cart[index];
}

double client::price(int index)  // see above method
{
    return cartPrice[index];
}

double client::ctotal()  // see above method
{
    return total;
}

double client::getWallet()  // method to be combined with the above method
{
    srand(time(0));
    wallet = 5 + rand()%25;
    return wallet;
}

int client::csize()
{
    return cart.size();
}

int client::getAccountNum()
{
    return accountNum;
}


