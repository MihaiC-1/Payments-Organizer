//
//  main.cpp
//  laborator4
//
//  Created by Comsa Mihai on 16/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <iostream>
#include "test_payments.hpp"
#include "test_repo.hpp"
#include "test_service.hpp"
#include "UI.hpp"


using namespace std;

int main()
{
    test_getter();
    test_setter();
    test_eq();
    test_repo();
    test_service();
    
    UI u;
    u.run_UI();
    
    return 0;
}
