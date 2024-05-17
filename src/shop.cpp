#include "shop.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "client.h"
#include <cstdlib>
#include <ctime>

using namespace std;



shop::shop() /* instanciate object and display inventory */
{
    cout << "0-----------------------------0"<<endl;
    cout << "|           INVENTORY         |"<<endl;
    cout << "0-----------------------------0"<<endl;
    for(int i = 0; i<10; i++)
    {
        cout << "| " << setw(12)<< items[i] << " | " << setw(12)<< fixed << setprecision(2) << prices[i] << " |" << endl;
    }
    cout << "0-----------------------------0"<<endl;
}

void shop::getInvoice(client& obj) /* generate invoice from cart */
{
    for(int i=0; i<obj.csize(); i++) // change obj to something else
    {
        usrItems.push_back(obj.getCart(i));
        cPrice.push_back(obj.price(i));
    }

    cout << endl;
    cout << "0--------------------------------------------------------0" << endl;
    cout << "|                        INVOICE                         "<<"|" << endl;
    cout << "0--------------------------------------------------------0" << endl;
    cout << "| "<<setw(16)<<"Description"<<" | "<<setw(16)<<"Prices"<<" | "<<setw(16)<<"Subtotal"<<" |" << endl;
    cout << "0--------------------------------------------------------0" << endl;

    for (int i=0; i<obj.csize(); i++)
    {
        cout << "| " << setw(16) << left << usrItems[i] << " | ";
        cout << setw(16) << cPrice[i] << " | ";
        cout << setw(12) << right << "R"<< fixed << setprecision(2) << cPrice[i] << " |\n";
    }

    cout << "0--------------------------------------------------------0" << endl;
    cout << "| " << setw(49) <<"Total: "<< fixed << setprecision(2) << obj.ctotal()<<" |" << endl;
    cout << "0--------------------------------------------------------0" << endl;
}

void shop::setPayment(client& obj) /* recieve total amnt and account num */
{
    srand(time(0));
    obj.setWallet();
    if ( obj.getAccountNum() <= 847000000 && obj.getAccountNum() >839999999) // Acceptable values
    {
        if (obj.ctotal() > obj.getWallet())
        {
            cout << obj.getWallet() << endl;
            cout << "Payment decline."<<endl;
        }
        else
        {
            cout << obj.getWallet() << endl;
            cout<<"Thanks for shopping at the shop."<<endl;
        }
    }
    else
    {
        cout << "Invalid account number.\n";
    }


}

//========================================================================================================================
//         || USER WILL NOT DIRECTLY INTERACT WITH THESE METHODS THEY'RE MENT FOR CLASS-TO-CLASS INTERACTION !!  ||
//========================================================================================================================

std::string shop::getInventory(int index) /* return inventory */
{

    return items[index];

}

double shop::getPrices(int index) /* return inventory prices */
{

    return prices[index];

}
