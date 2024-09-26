#include<iostream>
#include<fstream> //For reading and writing from file
#include<cstdio> //For rename and removing file
using namespace std;

void banner();
class TodoList {
    public:
        string task;
        void addTask();
        void showTask();
        void searchTask();
        void deleteTask();
        void updateTask();
};

void banner() {
    cout << "_________________________________" << endl;
    cout << "\t     My Todo" << endl;
    cout << "_________________________________" << endl;
}

void TodoList :: addTask() {
    system("cls");
    banner();
    cin.ignore(); //Ignore input buffer
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
    else {
        system("cls");
    }
}

void TodoList :: showTask() {
    system("cls");
    string taskInput;
    ifstream fin;
    fin.open("todo.txt");
    banner();
    if(!fin.is_open()) {
        system("cls");
        cout << "Unable to read file!!" << endl; 
        return;
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
    int count = 0;
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
    fout.open("temp.txt",ios::app); // creating temporary file to store content from original
    fin.open("todo.txt"); // opening OG file
    bool flag = false;
    while(!fin.eof()) {
        getline(fin,search);
        if(Delete != search) { // if task to delete is not in file then /
            fout << search << endl; // Store them in temporary file.
        }
        else {
            flag = true;  // if task found then skipped it.
        }
    }
    fin.close();
    fout.close();
    if(flag == true) { // if task is found
        remove("todo.txt"); //remove Original file 
        rename("temp.txt", "todo.txt"); //replace Original file with temp file
        cout << "Delete Successful.." << endl;
    } else {
        remove("temp.txt"); // if task not found then 
        //just remove the temp file cause it's not any use
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
    system("cls");
    banner();
    string update, searchTask, searchFromFile;
    cout << "which task you want to update? Please enter: ";
    cin.ignore();
    getline(cin, searchTask);
    ifstream fin;
    ofstream fout;
    fin.open("todo.txt");
    fout.open("temp.txt");
    int flag = 0;
    while(!fin.eof()) {
        getline(fin, searchFromFile);
        if(searchFromFile != searchTask) {
            fout << searchFromFile << endl;
        }
        else {
            cout << "Enter task to update: "; // if task is found then, 
            getline(cin, update); 
            fout << update << endl; // replace it with updated task
            flag = 1;
        }
    }
    fin.close();
    fout.close();
    if(flag) {
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "Updated Successful...!" << endl;
    } else {
        remove("temp.txt");
        cout << "Task not found...!" << endl;
    }
    char exit;
    cout << "Exit? (y/n): ";
    cin >> exit;
    if(exit !='y' && exit != 'Y') {
        updateTask();
    } else {
        system("cls");
        cout << "Exit Successful" << endl;
    }

}
int main() {
    system("cls");
    TodoList list;
    bool option = true;
    while(option) {
        banner();
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