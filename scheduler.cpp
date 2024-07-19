#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

struct Task {
    string name;
    string priority;
    string dueDate;
};

map<int, Task> tasks;
int taskId = 1;

//function to add a task

void addTask() {
    Task task;
    cout << "Enter task name: ";
    getline(cin, task.name);

    while (task.name.empty()) {
        cout << "Task name cannot be empty. Please try again." << endl;
        cout << "Enter task name: ";
        getline(cin, task.name);
    }

    while (true) {
        cout << "Enter task priority (high, medium, low): ";
        string priority;
        getline(cin, priority);

        if (priority == "high" || priority == "medium" || priority == "low") {
            task.priority = priority;
            break;
        } else {
            cout << "Invalid priority. Please enter high, medium, or low." << endl;
        }
    }

    while (true) {
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, task.dueDate);

        if (task.dueDate.size() == 10 && task.dueDate[4] == '-' && task.dueDate[7] == '-') {
            break;
        } else {
            cout << "Invalid due date format. Please enter YYYY-MM-DD." << endl;
        }
    }

    tasks[taskId] = task;
    taskId++;
    cout << "Task added successfully!" << endl;
}

//function to remove a task

void removeTask() {
    cout << "Available tasks:" << endl;
    for (auto& task : tasks) {
        cout << "ID: " << task.first << endl;
        cout << "Name: " << task.second.name << endl;
        cout << "Priority: " << task.second.priority << endl;
        cout << "Due Date: " << task.second.dueDate << endl;
        cout << "------------------------" << endl;
    }

    int id;
    cout << "Enter task ID to remove: ";
    cin >> id;
    cin.ignore();

    if (tasks.find(id)!= tasks.end()) {
        tasks.erase(id);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Task not found." << endl;
    }
}

//function to list all tasks

void listTasks() {
    cout << "Task List:" << endl;
    for (auto& task : tasks) {
        cout << "ID: " << task.first << endl;
        cout << "Name: " << task.second.name << endl;
        cout << "Priority: " << task.second.priority << endl;
        cout << "Due Date: " << task.second.dueDate << endl;
        cout << "------------------------" << endl;
    }
}

//function to change the priority assigned to a task

void changePriority() {
    cout << "Pending tasks:" << endl;
    for (auto& task : tasks) {
        cout << "ID: " << task.first << endl;
        cout << "Name: " << task.second.name << endl;
        cout << "Priority: " << task.second.priority << endl;
        cout << "Due Date: " << task.second.dueDate << endl;
        cout << "------------------------" << endl;
    }

    int id;
    cout << "Enter task ID to change priority: ";
    cin >> id;
    cin.ignore();

    if (tasks.find(id)!= tasks.end()) {
        while (true) {
            string priority;
            cout << "Enter new priority (high, medium, low): ";
            getline(cin, priority);

            if (priority == "high" || priority == "medium" || priority == "low") {
                tasks[id].priority = priority;
                cout << "Priority changed successfully!" << endl;
                break;
            } else {
                cout << "Invalid priority. Please enter high, medium, or low." << endl;
            }
        }
    } else {
        cout << "Task not found." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Task Scheduler" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Remove task" << endl;
        cout << "3. List all tasks" << endl;
        cout << "4. Change task priority" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                removeTask();
                break;
            case 3:
                listTasks();
                break;
            case 4:
                changePriority();
                break;
            case 5:
                cout << "Exiting..." << endl;
                exit(0);
        }         
    }

return 0;
}