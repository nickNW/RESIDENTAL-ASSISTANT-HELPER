//
//  ToDoList.cpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/11/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#include "ToDoList.hpp"
#include <iostream>



void ToDoList::get_info() const{
    for (int i = 0 ; i < to_do_list.size(); i++)
    {
        cout << left;
        cout<< setw(25) << to_do_list[i].get_task_name()
         << to_do_list[i].get_due_date();
        cout << endl;
    }
    
}

void ToDoList::set_to_do_list(vector<Task> to_do_list_param){
    to_do_list = to_do_list_param;
}
vector<Task> ToDoList::get_to_do_list()  const{
    return to_do_list;
}


