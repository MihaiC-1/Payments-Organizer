//
//  serivice.hpp
//  laborator4
//
//  Created by Comsa Mihai on 23/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#pragma once
#include <string>
#include <vector>
#include "repo.hpp"

using namespace std;

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo &repo);
    ~Service();
    void set_repo(Repo repo);
    //CRUD
    void add(int day, int amount, char* type);
    Payments* read();
    void update(int pos, int new_day, int new_amount, char* new_type);
    void delete_payment(Payments& p);
    
    //Ex.
    int get_size();
    void add_today(int amount, char* type);
    void delete_payment_by_day(int day);
    void delete_payment_by_days(int start_day, int end_day);
    void delete_payment_by_type(char* type);
    void print_payments();
    void print_by_type(char* type);
    void print_by_type_over_price(char* type, int amount);
    void print_by_type_eq_price(char* type, int amount);
    void amount_for_one_type(char* type);
    void max_amount_day();
    void amount_per_day();
    void amount_per_day_for_type(char* type);
    void filter_by_type(char* type);
    void filter_by_type_under_amount(char* type, int amount);
    void filter_by_type_equal_amount(char* type, int amount);
};

