//
//  Parent.cpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/10/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#include "Parent.hpp"


string Parent::get_name() const{
    return name;
}
string Parent::get_ID() const{
    return ID;
}
   
void Parent::set_name(string name_param){
    name = name_param;
}
void Parent::set_ID(string ID_param){
    ID = ID_param;
}

void Parent::get_info(){
    cout <<" The address for Magnoila apartments is USF Magnolia Drive, Tampa, FL 33620 "<<endl;
    cout << "Go Bulls"<<endl;
}

