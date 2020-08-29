//
//  ResidentialAssistant.cpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/11/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#include "ResidentialAssistant.hpp"
#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
#include "boost/algorithm/string.hpp"

using namespace boost::algorithm;
using namespace std;

ResidentialAssistant ResidentialAssistant::operator+ (const Student& right) {
    
    ResidentialAssistant RA;
    RA.add_student(right);
    
    
    return RA;
};
void ResidentialAssistant::add_student(const Student& s){
    students.push_back(s);
    
}
vector<Student> ResidentialAssistant::get_students() const{
    return students;
}
string ResidentialAssistant::get_RA_name() const{
    return RA_name;
}
string ResidentialAssistant::get_building() const{
    return building;
}
ToDoList ResidentialAssistant::get_to_do_list() const{
    return to_do_list;
}


void ResidentialAssistant::set_students(vector<Student> students_param){
    students = students_param;
}
void ResidentialAssistant::set_RA_name(string RA_name_param){
    RA_name = RA_name_param;
}
void ResidentialAssistant::set_building(string building_param){
    building = building_param;
}
void ResidentialAssistant::set_to_do_list(ToDoList to_do_list_param){
    to_do_list = to_do_list_param;
}


 

void ResidentialAssistant::get_all_unique_tags_with_students_name(){
    // this outputs all tags with the associated resident
    multimap<string, string> tag_and_student;
       vector<string> temp_tag_holder;
       
       for (int i = 0; i < students.size(); i++)
       {
           temp_tag_holder = students[i].get_tags();
           for(int j = 0; j< temp_tag_holder.size(); j++)
           {
               tag_and_student.insert(std::pair <string, string> (temp_tag_holder[j],
                                                                  students[i].get_name()));
           }
       }
       tag_and_student.erase("empty");
       tag_and_student.erase("");
       multimap <string ,string> :: iterator itr;
       cout << "\nThe multimap tag_and_student is : \n";
       cout << "\tKEY\tELEMENT\n";
    
       for (itr = tag_and_student.begin(); itr != tag_and_student.end(); ++itr)
       {
           cout << left;
           cout << setw(25) << itr->first
                  << itr->second << '\n';
       }
    

    
    
}





void ResidentialAssistant::get_most_compatible_students(){

    
    multimap<string, string> tag_and_student;
    vector<string> temp_tag_holder;
    
    for (int i = 0; i < students.size(); i++)
    {
        temp_tag_holder = students[i].get_tags();
        for(int j = 0; j< temp_tag_holder.size(); j++)
        {
            tag_and_student.insert(std::pair <string, string> (temp_tag_holder[j],
                                                               students[i].get_name()));
        }
    }
    tag_and_student.erase("empty");
    tag_and_student.erase("");
    multimap <string ,string> :: iterator itr;
    
    cout << endl;
    vector<string> final_out_put;
    string temp;
    vector<string> tag_holder_searching;
    int count =0;
    for (int i = 0; i < students.size(); i++)
    {
        cout << "\n";
        temp = students[i].get_name() + " has interst in common with ";
        count =0;
        tag_holder_searching = students[i].get_tags();
        for (int j =0; j< tag_holder_searching.size(); j++)
        {
            auto it = tag_and_student.equal_range(tag_holder_searching[j]);
            for (auto itr = it.first; itr != it.second; ++itr)
            {
                
                if (students[i].get_name() != itr->second)
                {
                    temp += '\t' + itr->second ;
                    count++;
                    
                }
            }
            
        }
        final_out_put.push_back(temp);
    }
    
    for (int i =0; i< final_out_put.size(); i++)
    {
        if (ends_with(final_out_put[i], "with "))
            continue;
                                                  
        else
            cout << final_out_put[i]<< endl<<endl;
     
    }
}


void ResidentialAssistant::most_common_tags_with_count(){
    
    vector<string> all_tags = get_all_tags();
       map<string, int> count_map;
       for (auto & elem : all_tags)
       {
           auto result = count_map.insert(pair<std::string, int>(elem, 1));
           if (result.second == false)
               result.first->second++;
       }
       count_map.erase("empty");
       count_map.erase("");
       for (auto & elem : count_map)
       {
           // If frequency count is greater than 1 then its a duplicate element
           if (elem.second > 1)
           {
               cout << left;
               cout << setw(25) << elem.first << " :: " << elem.second  << endl;
           }
       }
}


vector<string> ResidentialAssistant::get_all_tags(){


    vector<string> temp_tag_holder;
    vector<string> all_tags;

    for (int i = 0; i < students.size(); i++)
    {
        temp_tag_holder = students[i].get_tags();
        for(int j = 0; j< temp_tag_holder.size(); j++)
        {
            all_tags.push_back(temp_tag_holder[j]);
        }
    }
    
    return all_tags;
}


void resident_specific_task(ResidentialAssistant RA){
    vector<Student> vec_students;
    string action_item_temp, conversation_temp;
    
    vec_students = RA.get_students();
    for (int i =0; i < vec_students.size(); i++)
    {
        int count = 0;
        action_item_temp = vec_students[i].get_action_item();
        conversation_temp = vec_students[i].get_conversation();
        
        string final_output;
        if (action_item_temp.compare(0,5,"empty") != 0 ){
            final_output = to_string(i+1) + " " + vec_students[i].get_name() + " action item is " + action_item_temp;
            count++;
        }
        if (conversation_temp.compare(0,5,"empty") == 0){
            if (count == 0)
                final_output = to_string(i+1) + " " + vec_students[i].get_name() + " still needs completed intentional converstion ";
            if (count !=0)
                final_output += to_string(i+1) + " " + vec_students[i].get_name() + " also needs completed intentional converstion";
            count ++;
        }
        if (count != 0)
            cout << final_output<< endl<<endl;
        
        
    }
}
