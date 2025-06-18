#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void displayMenu(){
    cout <<"1. ADD A TASK\n";
    cout <<"2. VIEW ALL TASKS\n";
    cout <<"3. DELETE A TASK\n";
    cout <<"4. MARK TASKS AS COMPLETED\n";
    cout <<"5. EDIT A TASK\n";
    cout <<"6. SAVE & EXIT\n";

    cout <<"Enter your choice:";

}

void addTask(vector<string>& tasks){
    cout <<"Enter a new task:";
    string task;
    cin.ignore();
    getline(cin,task);
    tasks.push_back(task);
}

void viewTasks(const vector<string>& tasks){
    if(tasks.empty()){
        cout <<"No tasks to display\n";
        return;
    }

    cout <<"Tasks:\n";
    for(size_t i=0; i<tasks.size(); i++){
        cout <<i+1 << "." << tasks[i] << '\n';
    }
}

void deleteTask(vector<string>& tasks){
    cout <<"Enter the task number to be deleted:";
    size_t taskNum;
    cin >>taskNum;
    if (taskNum >= 1 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
    } else {
        cout << "Invalid task number\n";
    }
}


void markAsCompleted(vector<string>& tasks){

    if(tasks.empty()){
        cout <<"No tasks to be marked as completed!" <<endl;
        return;

    }

    cout <<"Enter the task number to be marked as completed:";
    size_t taskNum;
    cin >>taskNum;
    if(taskNum>=1 && taskNum<=tasks.size()){
        tasks[taskNum-1] += " [COMPLETED]";
        cout <<"Task marked as completed!" <<endl;
    }
    else{
        cout <<"Invalid task number" << endl;

    }

}

void editTask(vector<string>& tasks){
    cout <<"Enter the task number to be edited:";
    size_t taskNum;
    cin >>taskNum;
    if(taskNum>=1 && taskNum<=tasks.size()){
        cout <<"Enter the new task:";
        string newTask;
        cin.ignore();
        getline(cin,newTask);
        tasks[taskNum-1] = newTask;

    }
    else {
        cout << "Invalid task number\n";
    }
}


void saveTasks(const vector<string>& tasks){
    ofstream outFile("To-do_list.cpp");
    for(const auto & task: tasks){
        outFile << task << '\n';
    }
    cout <<"Tasks saved successfully\n";
}

int main(){
    vector<string> tasks;

    while(true){
        displayMenu();
        int choice;
        cin >>choice;

        switch(choice) {
            case 1:
                addTask(tasks);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                deleteTask(tasks);
                break;

            case 4:
                markAsCompleted(tasks);
                break;

            case 5:
                editTask(tasks);
                return 0;

            case 6:
                saveTasks(tasks);
                break;

            default:
                cout <<"Invalid choice\n";
                break;


        }
    }

    return 0;
}
