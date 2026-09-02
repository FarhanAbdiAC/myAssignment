// Inventory Management System

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:


    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }


    void displayDetails() const
    {
        cout << left << setw(8) << productId
             << setw(15) << name
             << setw(12) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(12) << totalValue()
             << endl;
    }


    double totalValue() const
    {
        return price * quantity;
    }


    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }
};





double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}


double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    double tax = cost * taxRate / 100;

    return cost + tax;
}



double applyDiscount(double price, double discountPercent = 10.0)
{
    double discount = price * discountPercent / 100;

    return price - discount;
}


int main()
{

    Product products[5];


    cout << "===== ENTER PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }


    cout << "\n\n===== INVENTORY REPORT =====" << endl;

    cout << left << setw(8) << "ID"
         << setw(15) << "Name"
         << setw(12) << "Price"
         << setw(8) << "Qty"
         << setw(12) << "Total Value"
         << endl;

    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }


    int highest = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() > products[highest].totalValue())
        {
            highest = i;
        }
    }

    cout << "\nHighest Value Product: ";
    products[highest].displayDetails();



    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock Products:" << endl;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            products[i].displayDetails();
        }
    }


    cout << "\n===== REORDER COST =====" << endl;

    double cost1 = reorderCost(10, 50.0);
    cout << "Integer quantity cost: " << cost1 << endl;

    double cost2 = reorderCost(10.5, 50.0);
    cout << "Fractional quantity cost: " << cost2 << endl;

    double cost3 = reorderCost(10, 50.0, 18.0);
    cout << "Cost with 18% tax: " << cost3 << endl;


    cout << "\n===== DISCOUNT =====" << endl;

    double price = 1000;

    cout << "Price after default 10% discount: "
         << applyDiscount(price) << endl;


    cout << "Price after 20% discount: "
         << applyDiscount(price, 20) << endl;


    return 0;
}
