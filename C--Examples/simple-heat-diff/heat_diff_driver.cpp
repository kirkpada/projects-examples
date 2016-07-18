/******************************************************
**Program: heat_diff_driver.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Driver for heat differential program
**Input:
**Output:
******************************************************/

#include <iostream>
#include <fstream>

#include "./heat_diff.h"

using namespace std;


int main()
{
    heat_diff hd;

    hd.heat_diff::open_file();
    hd.heat_diff::calc_r();
    hd.heat_diff::init_conditions();
    hd.heat_diff::heat_diff_calc();
    hd.heat_diff::output_file();

    return 0;
}
