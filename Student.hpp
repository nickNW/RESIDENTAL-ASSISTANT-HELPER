//
//  Student.hpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/10/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Parent.hpp"

using namespace std;


class Student : public Parent{
    
private:
    string building;
    string conversation;
    vector<string> tags;
    string action_item;
    static int student_count;
public:
    
    Student(string name, string ID, string building, string conversations, vector<string> tags, string action_items);
    
    string get_building() const;
    string get_conversation() const;
    vector<string> get_tags() const;
    string get_action_item() const;
    
    void set_building(string);
    void set_conversation(string);
    void set_tags(vector<string>);
    void set_action_item(string);
    
    
    friend void get_info_parent(Student& a , Parent& b );
    void get_info();
    
    static int get_student_count(){
        return student_count;
    }                                   
    

    
};
#endif /* Student_hpp */
