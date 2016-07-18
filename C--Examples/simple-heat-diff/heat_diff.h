/******************************************************
**Program: heat_diff.h
**Author: Daniel Kirkpatrick
**Date:
**Description: Hold function prototypes and member vars
**Input:
**Output:
******************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#ifndef HEAT_DIFF_H
#define HEAT_DIFF_H
class heat_diff
{
    public:
        heat_diff();
        void open_file();
        void init_conditions();
        void calc_r();
        void heat_diff_calc();
        std::vector<std::vector<float> > vector_resize(std::vector<std::vector<float> >);
        void output_file();

    private:
        float therm_conduct;
        float density;
        float spec_heat;
        float time;
        float time_change;
        float material_leng;
        float sections;
        float init_temp;
        float bound_cond1;
        float bound_cond2;
        float r;
        float dx;
        std::vector<std::vector<float> > u;
};

#endif // HEAT_DIFF_H
