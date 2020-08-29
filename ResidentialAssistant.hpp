//
//  ResidentialAssistant.hpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/11/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#ifndef ResidentialAssistant_hpp
#define ResidentialAssistant_hpp

#include <stdio.h>
#include "Student.hpp"
#include "ToDoList.hpp"


class ResidentialAssistant{
    
private:
    vector<Student> students;
    string RA_name;
    string building;
    ToDoList to_do_list;
    
public:
   ResidentialAssistant operator+ (const Student& right);
    void add_student(const Student& s);
    
    
   
    
    void get_all_unique_tags_with_students_name();
    void get_most_compatible_students();
    void most_common_tags_with_count();
    vector<string> get_all_tags();          //helper function
    friend void resident_specific_task(ResidentialAssistant RA);
    
    
    vector<Student> get_students() const;
    string get_RA_name() const;
    string get_building() const;
    ToDoList get_to_do_list() const;
    
    
    void set_students(vector<Student>);
    void set_RA_name(string);
    void set_building(string);
    void set_to_do_list(ToDoList);
    
    
};
#endif /* ResidentialAssistant_hpp */
