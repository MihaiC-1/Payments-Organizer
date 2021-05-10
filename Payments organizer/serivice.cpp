//
//  serivice.cpp
//  laborator4
//
//  Created by Comsa Mihai on 23/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "serivice.hpp"
#include <iostream>
#include "repo.hpp"
#include "payments.hpp"
#include <ctime>
#include <ostream>
#include <vector>

using namespace std;

Service::Service()
{
}

Service::Service(Repo &repo)
{
    this->repo = repo;
}

Service::~Service()
{
}

void Service::set_repo(Repo repo)
{
    this->repo = repo;
}

int Service::get_size()
{
    return this->repo.get_size();
}

void Service::add(int day, int amount, char* type) {
    Payments pay(day, amount, type);
    this->repo.add_payment(pay);
}

Payments* Service::read()
{
    return this->repo.get_all();
}

void Service::update(int pos, int new_day, int new_amount, char* new_type) {
    repo.update_payment(this->repo.get_all()[pos], new_day, new_amount, new_type);
}

void Service::delete_payment(Payments& p)
{
    int n = this->repo.get_size();
    for (int i = 0; i < n; i++) {
        if (this->repo.get_all()[i] == p) {
            this->repo.delete_payment(p, 1);
        }
    }
}

void Service::add_today(int amount, char *type)
{
    time_t now = time(0);
    tm *day = localtime(&now);
    Payments pay(day->tm_mday, amount, type);
    this->repo.add_payment(pay);
}

void Service::delete_payment_by_day(int day)
{
    int n = this->repo.get_size();
    for (int i = 0; i < n; i++)
    {
        if (this->repo.get_all()[i].get_day() == day)
        {
            this->repo.delete_payment(repo.get_all()[i], 2);
        }
    }
}

void Service::delete_payment_by_days(int start_day, int end_day)
{
    int n = this->repo.get_size();
    for (int d = start_day; d <= end_day; d++)
    {
        for (int i = 0; i < n; i ++)
        {
            if (this->repo.get_all()[i].get_day() == d)
            {
                this->repo.delete_payment(repo.get_all()[i], 2);
            }
        }
    }
}

void Service::delete_payment_by_type(char* type)
{
    int n = this->get_size();
    for (int i = 0; i < n; i++)
    {
        if (strcmp(this->read()[i].get_type(), type) == 0)
        {
            this->repo.delete_payment(this->read()[i], 3);
        }
    }
}

void Service::print_payments()
{
    cout << "Size = "  << this->get_size() << endl;
    
    for (int i = 0; i < this->get_size(); i++)
    {
        if (i == this->get_size() - 1)
        {
            cout << this->read()[i].get_day() << " " << this->read()[i].get_amount() << " RON " << this->read()[i].get_type() << endl;
        }
        else
        {
            cout << this->read()[i].get_day() << " " << this->read()[i].get_amount() << " RON " << this->read()[i].get_type() << " | ";
        }
    }
}

void Service::print_by_type(char* type)
{
    cout << "Payments for <" << type << "> are : ";
    
    for (int i = 0; i < this->get_size(); i++)
    {
        if (strcmp(this->read()[i].get_type(), type) == 0)
        {
            cout << this->read()[i].get_day() << " " << this->read()[i].get_amount() << " RON " << this->read()[i].get_type() << " | ";
        }
    }
    
    cout << endl;
}

void Service::print_by_type_over_price(char *type, int amount)
{
    cout << "Payments for <" << type << "> over " << amount << " RON are : ";
    
    for (int i = 0; i < this->get_size(); i++)
    {
        if ((strcmp(this->read()[i].get_type(), type) == 0) &&
            (this->read()[i].get_amount() > amount))
        {
            cout << this->read()[i].get_day() << " " << this->read()[i].get_amount() << " RON " << this->read()[i].get_type() << " | ";
        }
    }
    
    cout << endl;
}

void Service::print_by_type_eq_price(char *type, int amount)
{
    cout << "Payments for <" << type << "> equal with " << amount << " RON are : ";
    
    for (int i = 0; i < this->get_size(); i++)
    {
        if ((strcmp(this->read()[i].get_type(), type) == 0) &&
            (this->read()[i].get_amount() == amount))
        {
            cout << this->read()[i].get_day() << " " << this->read()[i].get_amount() << " RON " << this->read()[i].get_type() << " | ";
        }
    }
    
    cout << endl;
}

void Service::amount_for_one_type(char *type)
{
    int sum = 0;
    int n = this->get_size();
    for (int i = 0; i < n; i++)
    {
        if(strcmp(this->read()[i].get_type(), type) == 0)
        {
            sum += this->read()[i].get_amount();
        }
    }
    
    cout << "The amount spent on <" << type << "> is : " << sum << endl;
}

void Service::max_amount_day()
{
    int max_day = 0;
    int max_amount = 0;
    int n = this->get_size();
    for (int d = 1; d <= 31; d++)
    {
        int amount_day = 0;
        for (int i = 0; i < n; i++)
        {
            if (this->read()[i].get_day() == d)
                amount_day += this->read()[i].get_amount();
        }
        if (amount_day > max_amount)
        {
            max_amount = amount_day;
            max_day = d;
        }
    }
    
    cout << "The day you spent the most money is : " << max_day << endl;
}

void Service::filter_by_type(char *type)
{
    int i = 0;
    
    while (i < this->get_size())
    {
        if (strcmp(this->read()[i].get_type(), type) != 0)
        {
            this->delete_payment(this->read()[i]);
        }
        else
        {
            i++;
        }
    }
}

void Service::filter_by_type_under_amount(char *type, int amount)
{
    int i = 0;
    
    while (i < this->get_size())
    {
        if ((strcmp(this->read()[i].get_type(), type) != 0) ||
            (this->read()[i].get_amount() >= amount))
        {
            this->delete_payment(this->read()[i]);
        }
        else
        {
            i++;
        }
    }
}

void Service::filter_by_type_equal_amount(char *type, int amount)
{
    int i = 0;
    while (i < this->get_size())
    {
        if ((strcmp(this->read()[i].get_type(), type) != 0) ||
            (this->read()[i].get_amount() != amount))
        {
            this->delete_payment(this->read()[i]);
        }
        else
        {
            i++;
        }
    }
}

void Service::amount_per_day()
{
    int n = this->get_size();
    int sum[32] = {0};
    
    for (int d = 1; d < 31; d++)
    {
        for (int i = 0; i < n; i++)
        {
            if (this->read()[i].get_day() == d)
                sum[d] += this->read()[i].get_amount();
        }
    }
    
    int max = -1, max_d = 0;;
    
    while (max != 0)
    {
        max = -1;
        for (int i = 1; i < 32; i++)
        {
            if (sum[i] > max)
            {
                max = sum[i];
                max_d = i;
            }
        }
        if (max != 0)
            cout << "DAY : " << max_d << " , AMOUNT : " << max << endl;
        sum[max_d] = 0;
    }
}

void Service::amount_per_day_for_type(char *type)
{
    int n = this->get_size();
    int sum[32] = {0};
    
    for (int d = 1; d < 31; d++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((this->read()[i].get_day() == d) &&
                (strcmp(this->read()[i].get_type(), type) == 0))
                sum[d] += this->read()[i].get_amount();
        }
    }
    
    int min = 1000000, min_d = 0;;
    cout << "For the type <" << type << "> : ";
    while (min != 0)
    {
        min = 1000000;
        for (int i = 1; i < 32; i++)
        {
            if ((sum[i] < min) &&  (sum[i] != 0))
            {
                min = sum[i];
                min_d = i;
            }
        }
        if (min != 1000000)
            cout << "DAY : " << min_d << " , AMOUNT : " << min << endl;
        else
            min = 0;
        sum[min_d] = 0;
    }
}
