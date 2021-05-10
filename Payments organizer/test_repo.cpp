//
//  test_repo.cpp
//  laborator4
//
//  Created by Comsa Mihai on 20/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include "test_repo.hpp"
#include "payments.hpp"
#include "repo.hpp"
#include <stdio.h>
#include <ctime>


void test_repo()
{
    char type[] = "Apa";
    Payments p(1, 2, type);
    
    Repo pay;
    
    assert(pay.get_size() == 0);
    pay.add_payment(p);
    assert(pay.get_size() == 1);
    
    Payments* test = new Payments[pay.get_size()];
    test = pay.get_all();
    
    assert(test[0] == p);
    
    cout << "Test repo DONE!" << endl;
}
