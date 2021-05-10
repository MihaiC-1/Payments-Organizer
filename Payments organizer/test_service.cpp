//
//  test_service.cpp
//  laborator4
//
//  Created by Comsa Mihai on 23/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//
#include <iostream>
#include "test_service.hpp"
#include "serivice.hpp"
#include "string.h"
#include "repo.hpp"
#include <assert.h>

void test_service() {
    Service s;
    
    char* type_1 = new char[10];
    strcpy(type_1, "Gaz");
    char* type_2 = new char[10];
    strcpy(type_2, "Mancare");
    
    s.add(1, 100, type_1);
    Payments p_1(1, 100, type_1), p_2(2, 400, type_2);
    
    assert(*s.read() == p_1);
    strcpy(type_1, "Haine");
    s.update(0, 2, 200, type_1);
    
    assert(s.read()[0].get_day() == 2);
    assert(s.read()[0].get_amount() == 200);
    assert(strcmp(s.read()[0].get_type(), "Haine") == 0);
    
    s.add(2, 400, type_2);
    s.add(2, 500, type_2);
    s.add(1, 400, type_2);
    
    assert(s.get_size() == 4);
    
    s.delete_payment(p_2);
    assert(s.get_size() == 3);
    
    s.delete_payment_by_day(2);
    assert(s.get_size() == 2);
    
    s.filter_by_type(type_1);
    assert(s.get_size() == 0);
    
    s.add(1, 10, type_1);
    s.add(1, 100, type_1);
    s.add(12, 10, type_1);
    s.add(12, 100, type_2);
    
    s.filter_by_type_under_amount(type_1, 100);
    assert(s.get_size() == 2);
    
    s.filter_by_type_equal_amount(type_1, 30);
    assert(s.get_size() == 0);
    
    s.add_today(2, type_2);
    assert(s.get_size() == 1);
    
    cout << "Test service DONE!" << endl;
}
