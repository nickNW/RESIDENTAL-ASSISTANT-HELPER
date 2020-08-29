//
//  main.cpp
//  Residential Assistant Application
//
//  Created by Nicolas Ngwai on 4/9/20.
//  Copyright © 2020 Nicolas Ngwai. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Parent.hpp"
#include "Student.hpp"
#include "Task.hpp"
#include "ToDoList.hpp"
#include "ResidentialAssistant.hpp"
#include <boost/algorithm/string.hpp>

char Menu_Display();
vector<Task> read_task_list();
ResidentialAssistant Read_student_info(string RA_name, string building);
void Write_student_info(vector<Student> students);

using namespace std;
 

int main() {
    
    char choice;
    char contiue_exit;
    ResidentialAssistant RA;
    RA = Read_student_info("nicolas", "MAD-400C");
    ToDoList to_do_list;
    to_do_list.set_to_do_list(read_task_list());
    while (true)
    {
        choice = Menu_Display();
        
        if (choice == 'R' || choice == 'r')
        {
            vector<Student> students;
            Parent parent;
            string name, Unumber ;
            cout << "Enter your childs name ";
            cin.ignore();
            getline(cin, name);
            parent.set_name(name);
            
            cout << "Enter your childs Unumber";
            cin >> Unumber;
            parent.set_ID(Unumber);
            students = RA.get_students();
            int count =0;
            for(int i =0; i < students.size();i++)
            {
                if (parent.get_ID() == students[i].get_ID() )
                {
                    get_info_parent(students[i],parent);
                    
                    parent.get_info();
                    count++;
                }
              
            }
            if (count == 0)
            cout << "Incorrect Unumber";
            char input;
            cout << "Press any key to return to the main menu"<<endl;
            cin.ignore();
            cin >>input;
            continue;
            
        }
        
        if (choice == 'A' || choice == 'a')
        {
            string last_name,first_name,name, ID, room_number, conversation,  action_items;
            vector<string> vec_tags;
            cout << "Add a new student ";
            cout << "Enter first name of student"<<endl;
            cin >> first_name;
            cout << "Enter last name of student" <<endl;
            cin >> last_name;
            cout << "Enter ID of student"<<endl;
            cin >>ID;
            cout << "Enter Room number of student "<<endl;
            cin >>room_number;
            conversation = "empty";
            action_items = "empty";
            vec_tags.push_back("empty");
            name = first_name +last_name;
            
            Student student(name, ID, room_number, conversation, vec_tags, action_items);
            
            //RA = RA + student; // this overloaded function does not work properly so i took it out 
            
            vector<Student> temp_student = RA.get_students();
            temp_student.push_back(student);
            RA.set_students(temp_student);
            
            student.get_info();
            char input;
            cout << "Press any key to return to the main menu"<<endl;
            cin.ignore();
            cin >>input;
            continue;
        }
        
        if (choice == 'U' || choice == 'u')
        {
            
            RA.get_all_unique_tags_with_students_name();
            cout << "Enter y to continue or x to exit";
            cin >> contiue_exit;
            if (contiue_exit == 'y')
                continue;
            if (contiue_exit == 'x')
                break;
        }
        
        if (choice == 'P' || choice == 'p')
        {
            RA.most_common_tags_with_count();
            cout << "Enter y to continue or x to exit";
            cin >> contiue_exit;
            if (contiue_exit == 'y')
                continue;
            if (contiue_exit == 'x')
                break;
            //add search for specific tag option
        }
        if (choice == 'C' || choice == 'c')
        {
            RA.get_most_compatible_students();
            cout << "Enter y to continue or x to exit";
            cin >> contiue_exit;
            if (contiue_exit == 'y')
                continue;
            if (contiue_exit == 'x')
                break;
        }
        if (choice == 'E' || choice == 'e')
           {
               char extra_task;
               to_do_list.get_info();
               
               cout << "Show resident specific task enter D";
               cin >> extra_task;
               if (extra_task == 'D')
               {
                   resident_specific_task(RA);
               }
               else
                   break;
               while (true)
               {
                   char input;
                   int num;
                   char continue_or_not;
                   
                   cout << "To mark action item as complete press -A"<< endl;
                   cout << "To add a intentional conversation press -C"<<endl;
                   cout << "To exit press -X"<<endl;
                   cin >> input;
                   if (input == 'A' || input == 'a')
                   {
                       cout << "input the number of the action item you would like to complete"<< endl;
                       cin >> num;
                       vector<Student> students_temp;
                       students_temp = RA.get_students();
                       students_temp[num-1].set_action_item("empty");
                       RA.set_students(students_temp);
                   }
                   if (input == 'C' || input == 'c')
                   {
                       string temp_conversation;
                       cout << "input the number of the intentional conversation you would like to complete"<< endl;
                       cin >> num;
                       vector<Student> students_temp;
                       students_temp = RA.get_students();
                       cout << "Enter the intentional conversation for " <<
                       students_temp[num-1].get_name()<< endl;
                       cin.ignore();
                       getline(cin,temp_conversation, '\n');
                       students_temp[num-1].set_conversation(temp_conversation);
                       RA.set_students(students_temp);
                       
                   }
                   if (input == 'X' || input =='x')
                   {
                       break;
                   }
                   
                   cout << "If you would you like to complete another task or add an intentioal convestion Press y if not press any other key"<< endl;
                   cin >> continue_or_not;
                   if (continue_or_not != 'y')
                       break;
                   
               }
               cout << "Enter y to return to the main meanu or x to exit";
               cin >> contiue_exit;
               if (contiue_exit == 'y')
                   continue;
               if (contiue_exit == 'x')
                   break;
           }
        
        
        
    }
   
    Write_student_info(RA.get_students());
}

ResidentialAssistant Read_student_info(string RA_name, string building)
{
    ifstream input_file;
    input_file.open("student_info.txt");
    ResidentialAssistant RA;
    string ID, last_name, first_name, room_number, conversation, tags, action_items;
    vector<Student> list_of_students;

    if (input_file)
    {
       
        //cout << fixed << setprecision(1);
        while (!input_file.eof() )
        {
            getline(input_file,ID, '\t');
            getline(input_file,last_name, '\t');
            getline(input_file,first_name, '\t');
            getline(input_file,room_number, '\t');
            getline(input_file,conversation, '\t');
            getline(input_file,tags, '\t');
            getline(input_file,action_items, '\n');
            /*
            cout<< setw(10) << ID << setw(10) << last_name << setw(10) << first_name <<setw(10)<< room_number << setw(10) << conversation << setw(30) << tags << setw(10) << action_items << endl;
            */
            
            
            vector<string> vec_tags;
               boost::split (vec_tags, tags, boost::is_any_of("#"));
                              
               string name = first_name + " " + last_name;
            
            Student student(name, ID, room_number, conversation, vec_tags, action_items);
            
           
            
            list_of_students.push_back(student);
            
            //figure out the overloaded operator
        }
    }
    
    ToDoList temp_used_to_set_RA;
    temp_used_to_set_RA.set_to_do_list(read_task_list());
    RA.set_students(list_of_students);
    RA.set_RA_name(RA_name);
    RA.set_building(building);
    RA.set_to_do_list(temp_used_to_set_RA);
    return RA;
}

void Write_student_info(vector<Student> students){
    ofstream output_file("student_info.txt");
    if (output_file) {
        for (int i =0; i< students.size(); i++)
        {
            Student student = students[i];
            string name = student.get_name();
            vector<string> vec_name;
            boost::split (vec_name, name, boost::is_any_of(" "));
            string first_name = vec_name[0];
            string last_name = vec_name[1];
            vector<string> temp_tags = student.get_tags();
            string tags;
            for (int j =0; j< temp_tags.size(); j++)
            {
                if (temp_tags[j]!= "")
                tags += "#" + temp_tags[j];
            }
        
            output_file
                << student.get_ID() << '\t'
                << last_name << '\t'
                << first_name << '\t'
            << student.get_building() << '\t'
            << student.get_conversation() << '\t'
            << tags << '\t'
            << student.get_action_item() << '\n';
        
                
        }
        output_file.close();
    }
    
}

vector<Task> read_task_list(){
    ifstream input_file;
    input_file.open("task_list.txt");
    string task_name, due_date;
    vector<Task> task_list;
    if (input_file)
    {
        while (!input_file.eof() )
        {
            getline(input_file,task_name, '\t');
            getline(input_file,due_date, '\n');
            Task task;
            task.set_due_date(due_date);
            task.set_task_name(task_name);
            
            task_list.push_back(task);
        }
    }
    return task_list;
}



char Menu_Display()
{
    
    char choice ='M';
    cout << "Residential Assistant Application"<< endl;
    cout << "This program will help with the daily functions of an RA"<< endl;
    
    
   while (true){
       
       switch (choice) {
           case 'm':
           case 'M':
               cout << "M - Main Menu"<< endl;
               cout << "S - Search Resident Data" <<endl;
               cout << "T - Task to complete" << endl;
               cout << "R - Parent information Request" << endl;
               cout << "A - Add a new student" << endl;
               cin >> choice;
               break;
           case 's':
           case 'S':
               cout << "M - Main Menu"<< endl;
               cout << "U - Show all unique interest about residents" <<endl;
               cout << "C - Show most compatible students" << endl;
               cout << "P - Show most common interest" << endl;

               cin >> choice;
               if (choice == 'U' || choice == 'u' || choice == 'C' || choice == 'c'
                   || choice == 'P' || choice == 'p')
                   return choice;
               break;
           case 't':
           case 'T':
               cout << "M - Main Menu"<< endl;
               cout << "E - Show all upcoming Task" << endl;
               
               cin >> choice;
               if (choice == 'E' || choice == 'e' || choice == 'D' || choice == 'd')
                   return choice;
               break;
               
           case 'A':
           case 'a':
               return choice;
               break;
           case 'R':
           case 'r':
               return choice;
               break;
       
           default:
               cout << "Incorrect Input"<< endl;
               choice = 'M';
               break;
               
       }
   
       if (choice == 'M' || choice == 'S' || choice == 'T' )
           continue;
   }
    
    
}

