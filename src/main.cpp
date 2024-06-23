#include <iostream>
#include "client.h"
#include "shop.h"

using namespace std;

int main()
{
    shop myShop; // Display inventory

    // create user and get acc number
    cout << "Enter your account number: " << endl;
    int acc;
    cin >> acc;
    client customer(acc);


    customer.setCart(myShop); // user fills in the cart


    myShop.getInvoice(customer); // display an invoice with the items in the user's cart

    myShop.setPayment(customer); // payment

    /*
     * ToDo in v2
     * - divide shop and client into ore classes
     * - payment to be handled by a separate class
    */

    return 0;
}
