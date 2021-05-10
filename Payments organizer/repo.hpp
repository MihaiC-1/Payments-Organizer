//
//  repo.hpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "payments.hpp"
#pragma once
#include <vector>

class Repo
{
private:
    Payments payments[20];
    int n;
public:
    Repo();
    ~Repo();
    Payments* get_all();
    int get_size();
    void add_payment(Payments& p);
    void update_payment(Payments& pay, int day, int amount, char* type);
    int search(const Payments& p);
    int search_day(int day);
    int search_type(char* type);
    //void delete_by_day(int day);
    //void delete_by_type(char* type);
    void delete_payment(Payments& p, int op);
};
