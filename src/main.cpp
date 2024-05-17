#include <iostream>
#include "client.h"
#include "shop.h"

using namespace std;

int main()
{
    shop a; // Display inventory

    // create user and get acc number
    cout << "Enter your account number: " << endl;
    int acc;
    cin >> acc;
    client b(acc);


    b.setCart(a); // user fills in the cart


    a.getInvoice(b); // display an invoice with the items in the user's cart

    a.setPayment(b); // payment

    /*
     * ToDo
     * - Rename the instances of client and shop to more intuitive names
     * - Comment your damn code man it's always treasure hunting everytime i'm here
    */

    return 0;
}
