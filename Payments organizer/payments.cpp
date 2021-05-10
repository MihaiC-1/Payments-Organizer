//
//  payments.cpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "payments.hpp"
#include <iostream>
#include <ostream>
#include <string.h>
#include <cstddef>
#include <cstring>
#include <string>

using namespace std;

Payments::Payments()
{
    this->day = 0;
    this->amount = 0;
    this->type = NULL;
}

Payments::Payments(int day, int amount, char* type)
{
    this->day = day;
    this->amount = amount;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Payments::Payments(const Payments& p)
{
    this->day = p.day;
    this->amount = p.amount;
    this->type = new char[strlen(p.type) + 1];
    strcpy(this->type, type);
}

Payments::~Payments()
{
    if (this->type)
    {
        delete[] this->type;
        this->type = NULL;
    }
}

int Payments::get_day()
{
    return this->day;
}

int Payments::get_amount()
{
    return this->amount;
}

char* Payments::get_type()
{
    return this->type;
}

void Payments::set_day(int day)
{
    this->day = day;
}

void Payments::set_amount(int amount)
{
    this->amount = amount;
}

void Payments::set_type(char *type)
{
    if (this->type)
    {
        delete[] this->type;
    }
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

Payments& Payments::operator = (const Payments& p)
{
    this->set_day(p.day);
    this->set_amount(p.amount);
    this->set_type(p.type);
    return *this;
}

bool Payments::operator == (const Payments& p)
{
    return this->day == p.day && this->amount == p.amount && strcmp(this->type, p.type) == 0;
}

ostream& operator<<(ostream& os, const Payments& p) {
    os << p.day << " " << p.amount << " " << p.type;
    return os;
}
