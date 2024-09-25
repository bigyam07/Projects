#include<iostream>
#include<fstream>
using namespace std;
class TodoList {
    public:
        int id = 0;
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
        id ++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout << "\n" << id;
        fout << "\n" << task;
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
    while(!fin.eof()) {
        fin >> id;
        fin.ignore();
        getline(fin, taskInput);
        if(taskInput != "") {
            cout << "\t" << id << ": " << taskInput << endl;
        }
        else {
            cout << "\tEmpty!" << endl;
        }
    }
    fin.close();
    char exit;
    cout << "Exit? (y/n)";
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
        if(store == search) {
            cout << "Found!!" << endl;
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
    cout << "This is delete";
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
            default:
                break;
        }
    }
    return 0;
}