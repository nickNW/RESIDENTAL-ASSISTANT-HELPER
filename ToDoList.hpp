//
//  ToDoList.hpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/11/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#ifndef ToDoList_hpp
#define ToDoList_hpp

#include <stdio.h>
#include <vector>
#include <iomanip>
#include "Task.hpp"


class ToDoList{
private:
    vector<Task> to_do_list;
    
public:
    void get_info() const;
    
    void set_to_do_list(vector<Task>);
    
    vector<Task> get_to_do_list()  const;
        
    
};
#endif /* ToDoList_hpp */
