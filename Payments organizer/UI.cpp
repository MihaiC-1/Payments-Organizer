//
//  UI.cpp
//  laborator4
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "UI.hpp"
#include <iostream>

using namespace std;

UI::UI()
{
}

UI::UI(Service& ser)
{
    this->ser = ser;
}

UI::~UI()
{
}

void UI::display_menu()
{
    cout << " 1. Add a new payment! " << endl;
    cout << " 2. Add a new payment for today! " << endl;
    cout << " 3. Delete payments from one day! " << endl;
    cout << " 4. Delete payments between two days! " << endl;
    cout << " 5. Delete payments for one type! " << endl;
    cout << " 6. Display all payments for this month! " << endl;
    cout << " 7. Display all payments for one type! " << endl;
    cout << " 8. Display all payments for one type greater than an amount! " << endl;
    cout << " 9. Display all payments for one type equal to an amount! " << endl;
    cout << " 10. Display the amount for all payments with the same type! " << endl;
    cout << " 11. Display the day with the highest amount! " << endl;
    cout << " 12. Display the amount per day, descending! " << endl;
    cout << " 13. Display the amount per day for one type, ascending! " << endl;
    cout << " 14. Type filter! " << endl;
    cout << " 15. Type filter with an amount smaller than a sum! " << endl;
    cout << " 16. Type filter with an amount equal to a sum! " << endl;
    cout << " 17. Undo! (one time) " << endl;
    cout << " 0. EXIT! " << endl;
}

void UI::op_1()
{
    int day, amount;
    char* type = new char[20];
    char t[20];
    cout << " day = ";
    cin >> day;
    cout << " amount = ";
    cin >> amount;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.add(day, amount, type);
}

void UI::op_2()
{
    int amount;
    char* type = new char[20];
    char t[20];
    cout << " amount = ";
    cin >> amount;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.add_today(amount, type);
}

void UI::op_3()
{
    int day;
    cout << " day = ";
    cin >> day;
    this->ser.delete_payment_by_day(day);
}

void UI::op_4()
{
    int start_day;
    int end_day;
    cout << " start day = ";
    cin >> start_day;
    cout << " end day = ";
    cin >> end_day;
    this->ser.delete_payment_by_days(start_day, end_day);
}

void UI::op_5()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.delete_payment_by_type(type);
}

void UI::op_6()
{
    this->ser.print_payments();
}

void UI::op_7()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.print_by_type(type);
}

void UI::op_8()
{
    int amount;
    char* type = new char[20];
    char t[20];
    cout << " amount = ";
    cin >> amount;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.print_by_type_over_price(type, amount);
}

void UI::op_9()
{
    int amount;
    char* type = new char[20];
    char t[20];
    cout << " amount = ";
    cin >> amount;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.print_by_type_eq_price(type, amount);
}

void UI::op_10()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.amount_for_one_type(type);
}

void UI::op_11()
{
    this->ser.max_amount_day();
}

void UI::op_12()
{
    this->ser.amount_per_day();
}

void UI::op_13()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.amount_per_day_for_type(type);
}

void UI::op_14()
{
    char* type = new char[20];
    char t[20];
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.filter_by_type(type);
}

void UI::op_15()
{
    int amount;
    char* type = new char[20];
    char t[20];
    cout << " amount = ";
    cin >> amount;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.filter_by_type_under_amount(type, amount);
}

void UI::op_16()
{
    int amount;
    char* type = new char[20];
    char t[20];
    cout << " amount = ";
    cin >> amount;
    cout << " type = ";
    cin >> t;
    strcpy(type, t);
    this->ser.filter_by_type_equal_amount(type, amount);
}

void UI::load_undo()
{
    this->n = this->ser.get_size();
    for (int i = 0; i < n; i++)
    {
        this->payments[i] = this->ser.read()[i];
    }
}

void UI::undo()
{
    int i = 0;
    while (i < this->ser.get_size())
    {
        this->ser.delete_payment(this->ser.read()[i]);
    }
    
    for (int j = 0; j < this->n; j++)
    {
        this->ser.add(this->payments[j].get_day(), this->payments[j].get_amount(), this->payments[j].get_type());
    }
}

void UI::run_UI()
{
    int op = -1;
    
    while (op != 0)
    {
        display_menu();
        cout << "Choose an option: ";
        cin >> op;
        switch (op) {
            case 1:
                this->load_undo();
                this->op_1();
                break;
            case 2:
                this->load_undo();
                this->op_2();
                break;
            case 3:
                this->load_undo();
                this->op_3();
                break;
            case 4:
                this->load_undo();
                this->op_4();
                break;
            case 5:
                this->load_undo();
                this->op_5();
                break;
            case 6:
                this->op_6();
                break;
            case 7:
                this->op_7();
                break;
            case 8:
                this->op_8();
                break;
            case 9:
                this->op_9();
                break;
            case 10:
                this->op_10();
                break;
            case 11:
                this->op_11();
                break;
            case 12:
                this->op_12();
                break;
            case 13:
                this->op_13();
                break;
            case 14:
                this->load_undo();
                this->op_14();
                break;
            case 15:
                this->load_undo();
                this->op_15();
                break;
            case 16:
                this->load_undo();
                this->op_16();
                break;
            case 17:
                this->undo();
                break;
            default:
                break;
        }
    }
}
