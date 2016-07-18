/******************************************************
**Program: heat_diff.cpp
**Author: Daniel Kirkpatrick
**Date:
**Description: Holds implementation of functions
**Input:
**Output:
******************************************************/


#include "./heat_diff.h"

using namespace std;

//set default values
heat_diff::heat_diff()
{
    therm_conduct = 0;
    density = 0;
    spec_heat = 0;
    time = 0;
    time_change = 0;
    material_leng = 0;
    sections = 0;
    init_temp = 0;
    bound_cond1 = 0;
    bound_cond2 = 0;
    r = 0;
    dx = 0;
    u.resize(0);
}//********** end heat_diff **********


//open file and fill variables
void heat_diff::open_file()
{
    cout << "in open_file function" << endl;

    ifstream file_in;
    file_in.open("./heat_input.dat");

    if(file_in.is_open())
    {
        while(!file_in.eof())
        {
            file_in >> therm_conduct >> density >> spec_heat >> init_temp >> bound_cond1 >>
            bound_cond2 >> material_leng >> sections >> time >> time_change;
        }

        //resize 2D vector
        u = vector_resize(u);

        //output the data read from file
        cout << endl;
        cout << "Inputted data from file: " << endl;
        cout << therm_conduct << " " << density << " " << spec_heat << endl;
        cout << init_temp << " " << bound_cond1 << " " << bound_cond2 << endl;
        cout << material_leng << " " << sections << endl;
        cout << time << " " << time_change << endl;

        file_in.close();
    }
    else if(!file_in.is_open())
    {
        cout << "File not opened!!" << endl;
    }
}//********** end open_file **********


//set initial conditions
void heat_diff::init_conditions()
{
    //set initial temp to 0 for initial time 0
    for(int i = 0; i < sections; i++)
    {
        u[0][i] = init_temp;
    }

    //set bound conditions
    for(int j = 0; j < sections; j++)
    {
        u[j][0] = bound_cond1;
        u[j][sections-1] = bound_cond2;
    }

    //first iteration when there is no temp change
    for(int x = 0; x < 1; x++)
    {
        cout << "time: " << x << endl;
        for(int y = 0; y < sections; y++)
        {
            cout << u[x][y] << " ";
        }
    }
    cout << endl;
    cout << endl;
}//********** end init_conditions **********


//calculates (k*dt)/(c*p)
void heat_diff::calc_r()
{
    r = (therm_conduct*time_change)/(spec_heat*density);
    cout << "r is: " << r << endl;
    cout << endl;
}//********** end calc_r **********


//heat differential calculations
void heat_diff::heat_diff_calc()
{
    //set change in x change for different delta x
    dx = 1.0;

    for(int i = 1; i < time+1; i++)
    {
        cout << "time: " << i << endl;
        for(int j = 0; j < sections; j++)
        {
            u[i][j] = u[i-1][j] + r*((u[i-1][j+1]-(2*u[i-1][j])+u[i-1][j-1])/(dx*dx));

            //reset bound conditions
            u[i][0] = bound_cond1;
            u[i][sections-1] = bound_cond2;
            cout << fixed;
            cout << setprecision(2) << u[i][j] << " ";
        }
        cout << endl;
        cout << endl;
    }
}//********** end heat_diff_calc **********


//resizes the 2D vector to appropriate dimensions
std::vector<std::vector<float> > heat_diff::vector_resize(vector<vector<float> > vrs)
{
    cout << "***** Resizing 2D vector *****" << endl;
    vrs.resize(time+1);
    for(int i = 0; i < vrs.size(); i++)
    {
        vrs[i].resize(sections+1);
    }

    return vrs;
}//********** end vector_resize **********


//output a binary file for GrADS
void heat_diff::output_file()
{
    ofstream out_file("heat_bin.dat", ios::out | ios::binary);

    if(out_file.is_open())
    {
        for(int i = 0; i < time+1; i++)
        {
            for(int j = 0; j < sections; j++)
            {
                out_file.write((char*)&u[i][j], sizeof(float));
            }
        }
        out_file.close();
    }

}//********** end output_file **********
