//
//  payments.hpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//
#pragma once
#include <iostream>
#include <ostream>
using namespace std;

class Payments
{
private:
    int day;
    int amount;
    char* type;
public:
    Payments();
    Payments(int day, int amount, char* type);
    Payments(const Payments& p);
    ~Payments();
    int get_day();
    int get_amount();
    char* get_type();
    void set_day(int day);
    void set_amount(int amount);
    void set_type(char* type);
    Payments& operator = (const Payments& p);
    bool operator == (const Payments& p);
    friend ostream& operator << (ostream& os, const Payments& p);
};
