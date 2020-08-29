//
//  Parent.hpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/10/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#ifndef Parent_hpp
#define Parent_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class Student;

using namespace std;

class Parent{
private:
    string name;
    string ID;
    
public:
    string get_name() const;
    string get_ID() const;
    
    void set_name(string);
    void set_ID(string);
    
   friend void get_info_parent(Student& a , Parent& b );
    virtual void get_info();
};

#endif /* Parent_hpp */
