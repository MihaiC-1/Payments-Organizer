//
//  repo.cpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "repo.hpp"
#include <ctime>

using namespace std;

Repo::Repo()
{
    this->n = 0;
}
Repo::~Repo()
{
    this->n = 0;
}
void Repo::add_payment(Payments& p)
{
    this->payments[this->n++] = p;
}

Payments* Repo::get_all()
{
    return this->payments;
}

int Repo::get_size()
{
    return this->n;
}

void Repo::update_payment(Payments& pay, int day, int amount, char *type)
{
    pay.set_day(day);
    pay.set_amount(amount);
    pay.set_type(type);
}

int Repo::search(const Payments& p)
{
    int n = this->get_size();
    for (int i = 0; i < n; i++)
    {
        if (this->payments[i] == p)
            return i;
    }
    return -1;
}

int Repo::search_day(int day)
{
    int n = this->get_size();
    for (int i = 0; i < n; i++)
    {
        if (this->payments[i].get_day() == day)
            return i;
    }
    return -1;
}

int Repo::search_type(char* type)
{
    int n = this->get_size();
    for (int i = 0; i < n; i++)
    {
        if (strcmp(this->payments[i].get_type(), type) == 0)
            return i;
    }
    return -1;
}
/*
void Repo::delete_by_day(int day)
{
    int pos = this->search_day(day);
    int nr = this->get_size();
    if (pos != -1)
    {
        for (int i = pos; i < nr - 1; i++)
            this->payments[i] = this->payments[i+1];
        this->n = nr - 1;
    }
}

void Repo::delete_by_type(char *type)
{
    int pos = this->search_type(type);
    int nr = this->get_size();
    if (pos != -1)
    {
        for (int i = pos; i < nr - 1; i++)
            this->payments[i] = this->payments[i + 1];
        this->n = nr - 1;
    }
}
*/
void Repo::delete_payment(Payments& p, int op)
{
    int pos;
    if (op == 1)
    {
        pos = this->search(p);
    }
    else if (op == 2)
    {
        pos = this->search_day(p.get_day());
    }
    else
    {
        pos = this->search_type(p.get_type());
    }
    int nr = this->get_size();
    if (pos != -1)
    {
        for (int i = pos; i < nr - 1; i++)
            this->payments[i] = this->payments[i + 1];
        this->n = nr - 1;
    }
}
