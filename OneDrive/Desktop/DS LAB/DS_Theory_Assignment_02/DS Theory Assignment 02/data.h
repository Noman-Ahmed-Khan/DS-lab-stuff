#ifndef data_H
#define data_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct table{
    int id;
    string name;
    int age;
    table(int a,string b,int c);
    table();
};

#include "data.tpp"
#endif