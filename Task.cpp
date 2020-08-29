//
//  Task.cpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/11/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#include "Task.hpp"

string Task::get_due_date() const{
    return due_date;
}

string Task::get_task_name()  const{
    return task_name;
}

void Task::set_due_date(string due_date_param){
    due_date = due_date_param;
}

void Task::set_task_name(string task_name_param){
    task_name = task_name_param;
}
