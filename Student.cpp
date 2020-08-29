//
//  Student.cpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/10/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#include "Student.hpp"
#include <iostream>


string Student::get_building() const{
    return building;
    
}
string Student::get_conversation() const{
    return conversation;
}
vector<string> Student::get_tags() const{
    return tags;
}
string Student::get_action_item() const{
    return action_item;
}

void Student::set_building(string building_param){
    building = building_param;
}
void Student::set_conversation(string conversation_param){
    conversation = conversation_param;
}
void Student::set_tags(vector<string> tags_param){
    tags = tags_param;
}
void Student::set_action_item(string action_item_param){
    action_item = action_item_param;
}



int Student::student_count = 0;

Student::Student(string name, string ID, string building, string conversations,                          vector<string> tags,string action_item){
    set_name(name);
    set_ID(ID);
    set_building(building);
    set_conversation(conversations);
    set_tags(tags);
    set_action_item(action_item);
    ++student_count;
    
}
void get_info_parent(Student& a, Parent& b){

    cout << "Your child " << b.get_name() << "Room number is " << a.get_building() <<
    "there are " << a.get_student_count() << " students living on his floor"<<endl;

    
}
void Student::get_info(){
    cout << get_name() <<"\t"<< get_ID() <<"\t"<< building << endl;
    
}

