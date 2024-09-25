#include<iostream>
#include<fstream>
#include<cstdio> //For rename and removing file
using namespace std;
class TodoList {
    public:
        int count = 0;
        string task;
        void banner();
        void addTask();
        void showTask();
        void searchTask();
        void deleteTask();
        void updateTask();
};

void TodoList :: banner() {
    cout << "_________________________________" << endl;
    cout << "\t     My Todo" << endl;
    cout << "_________________________________" << endl;
}

void TodoList :: addTask() {
    system("cls");
    banner();
    cin.ignore();
    cout << "Enter new task: " << endl;
    getline(cin, task);
    char save;
    cout << "Save? (y/n): ";
    cin >> save;
    if(save == 'y') {
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout << task << endl;
        fout.close();

        char more;
        cout << "Add more task? (y/n): ";
        cin >> more;
        if(more == 'y' ) {
            addTask();
        }
        else {
            system("cls");
            cout << "Added sucessfully!" << endl;
            return;
        }
    }
}

void TodoList :: showTask() {
    system("cls");
    string taskInput;
    ifstream fin;
    fin.open("todo.txt");
    banner();
    if(!fin.is_open()) {
        cout << "Task is empty!!" << endl; 
    }
    bool flag = false;
    while(!fin.eof()) {
        getline(fin, taskInput);
        if(taskInput != "") {
            flag = true;
            cout << "\t" << ": " << taskInput << endl;
        }
    }
    if(!flag) {
        cout << "\tEmpty!\n\tAdd some task First..!" << endl;
    }
    fin.close();
    char exit;
    cout << "Exit? (y/n): ";
    cin >> exit;
    if(exit != 'y' && exit != 'Y') {
        showTask();
    } 
    system("cls");
}
void TodoList :: searchTask() {
    system("cls");
    banner();
    string store,search;
    ifstream fin;
    fin.open("todo.txt");
    cout << "Enter task to search:- " << endl;
    cin.ignore();
    getline(cin, search);
    bool found = false;
    while(!fin.eof()) {
        getline(fin, store,'\n');
        count ++;
        if(store == search) {
            cout << "Found!!" << endl;
            cout << "AT LINE NO. :: " << count << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Not found...!" << endl;
    }
    fin.close();
    char exit;
    cout << "Exit? (y/n) : ";
    cin >> exit;
    if(exit != 'y' && exit!='Y') {
        searchTask();
    }
    system("cls");
    cout << "Exit successful" << endl;
}
void TodoList :: deleteTask() {
    system("cls");
    banner();
    string Delete, search;
    cout << "Enter task to delete: ";
    cin.ignore();
    getline(cin, Delete);
    ofstream fout;
    ifstream fin;
    fout.open("temp.txt",ios::app);
    fin.open("todo.txt");
    bool flag = false;
    while(!fin.eof()) {
        getline(fin,search);
        if(Delete != search) {
            fout << search << endl;
        }
        else {
            count --;
            flag = true;
        }
    }
    fin.close();
    fout.close();
    if(flag == true) {
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "Delete Successful.." << endl;
    } else {
        remove("temp.txt");
        cout << "Task not found!!" << endl;
    }
    char exit;
    cout << "Exit (y/n): ";
    cin >> exit;
    if(exit != 'y' && exit != 'Y') {
        deleteTask();
    }
    else {
        system("cls");
        cout << "EXIT SUCCESSFUL..!" << endl;
    }
}
void TodoList :: updateTask() {
    cout << "This is update";
}
int main() {
    system("cls");
    TodoList list;
    bool option = true;
    while(option) {
        list.banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Show Task";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. Update Task";
        cout << "\n\t6. Exit";

        int choice;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1 : 
                list.addTask();
                break;
            case 2 : 
                list.showTask();
                break;
            case 3 : 
                list.searchTask();
                break;
            case 4 : 
                list.deleteTask();
                break;
            case 5 : 
                list.updateTask();
                break;
            case 6:
                option = false;
                system("cls");
                cout << "EXIT SUCCESSFUL....!";
                break;
            default:
                system("cls");
                cout << "Invalid Input." << endl;
                break;
        }
    }
    return 0;
}