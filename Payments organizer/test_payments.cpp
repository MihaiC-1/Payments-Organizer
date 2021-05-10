//
//  test_payments.cpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "test_payments.hpp"
#include "payments.hpp"
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

void test_getter()
{
    Payments payments[3];
    char* type_1 = new char[10];
    char* type_2 = new char[10];
    char* type_3 = new char[10];
    
    strcpy(type_1, "Food");
    strcpy(type_2, "Clothes");
    strcpy(type_3, "Transport");
    
    Payments pay_1(3, 200, type_1);
    Payments pay_2(10, 1200, type_2);
    Payments pay_3(28, 70, type_3);
    
    assert(pay_1.get_day() == 3);
    assert(pay_2.get_day() == 10);
    assert(pay_3.get_day() == 28);
    
    assert(pay_1.get_amount() == 200);
    assert(pay_2.get_amount() == 1200);
    assert(pay_3.get_amount() == 70);
    
    assert(strcmp(pay_1.get_type(), type_1) == 0);
    assert(strcmp(pay_2.get_type(), type_2) == 0);
    assert(strcmp(pay_3.get_type(), type_3) == 0);
    
    cout << "Test getter from Payments DONE!" << endl;
}

void test_setter()
{
    Payments payments[1];
    char* type = new char[10];
    char* new_type = new char[10];
    
    strcpy(type, "Food");
    Payments pay(20, 300, type);
    
    pay.set_day(10);
    assert(pay.get_day() == 10);
    
    pay.set_amount(150);
    assert(pay.get_amount() == 150);
    
    strcpy(new_type, "Internet");
    pay.set_type(new_type);
    assert(strcmp(pay.get_type(), "Internet") == 0);
    
    cout << "Test setter from Payments DONE!" << endl;
}

void test_eq()
{
    Payments payments[2];
    char* type_1 = new char[10];
    
    strcpy(type_1, "Internet");
    
    Payments pay_1(10, 100, type_1),
            pay_2(10, 100, type_1);
    
    assert(pay_1 == pay_2);
}
