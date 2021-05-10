//
//  UI.hpp
//  laborator4
//
//  Created by Comsa Mihai on 30/03/2020.
//  Copyright © 2020 Comsa Mihai. All rights reserved.
//

#include <stdio.h>
#pragma once
#include "serivice.hpp"

class UI
{
private:
    Service ser;
    int n;
    Payments payments[40];
    void display_menu();
    void op_1();
    void op_2();
    void op_3();
    void op_4();
    void op_5();
    void op_6();
    void op_7();
    void op_8();
    void op_9();
    void op_10();
    void op_11();
    void op_12();
    void op_13();
    void op_14();
    void op_15();
    void op_16();
    void load_undo();
    void undo();
public:
    UI();
    UI(Service& ser);
    ~UI();
    void run_UI();
};
