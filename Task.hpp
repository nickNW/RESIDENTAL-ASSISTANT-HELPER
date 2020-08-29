//
//  Task.hpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/11/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Task{
private:
    string due_date;
    string task_name;
    
public:
    string get_due_date() const;
    string get_task_name()  const;
    
    void set_due_date(string);
    void set_task_name(string);
    
    
    
    
};
#endif /* Task_hpp */
