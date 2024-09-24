#include<iostream>
#include<fstream>
using namespace std;
class TodoList {
    public:
        int id;
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
        fout.open("todo.txt");
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
    cout << "show task";
}
void TodoList :: searchTask() {
    cout << "This is search";
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
    while(true) {
        list.banner();
        cout << "\n\t1. Add Task";
        cout << "\n\t2. Show Task";
        cout << "\n\t3. Search Task";
        cout << "\n\t4. Delete Task";
        cout << "\n\t5. Update Task";

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
            default:
                break;
        }
    }
    return 0;
}