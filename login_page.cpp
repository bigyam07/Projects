#include<iostream>
#include<fstream>
using namespace std;

class loginPage {
    public:
        string userName, Email, Password;
        void login();
        void signUp();
        void forgotPassword();

};

//SignUp Function
void loginPage :: signUp() {
    cout << "Enter username: ";
    getline(cin, userName);
    cout << "Enter email: ";
    getline(cin, Email);
    cout << "Enter Password: ";
    cin >> Password;
    //creating file and storing data into it
    ofstream file;
    file.open("LoginPage.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << Password;
    file.close();
}
//Login Function
void loginPage :: login() {
    string searchName, searchPassword;
    cout << "---------LOGIN----------" << endl;
    cout << "Enter your username :: ";
    getline(cin, searchName);
    cout << "Enter you Password :: ";
    getline(cin, searchPassword);

    //Opening a file
    ifstream file;
    file.open("LoginPage.txt");
    //checking if file is opened or not
    if(!file.is_open()) {
        cout << "Failed to open the login file..!" << endl;
        return;
    }
    bool loginSucess = false;
    string fileName, filePassword, fileEmail;
    while(getline(file, fileName, '*') && getline(file,fileEmail,'*') && getline(file, filePassword, '\n')) {
        if(fileName == searchName && filePassword == searchPassword ) {
                cout << "Account Login sucessfull...!" << endl;
                loginSucess = true;
                break;
        }
    }
    if(!loginSucess) {
        cout << "Username or Password invalid" << endl;
    }
    file.close();
}
//ForgetPassword Function
void loginPage:: forgotPassword() {
    string searchName, searchEmail;

    cout << "Enter username to find :: ";
    getline(cin, searchName);
    cout << "Enter your Email :: ";
    getline(cin, searchEmail);
    ifstream file;
    file.open("loginPage.txt");
    if(!file.is_open()) {
        cout << "File is not opened..!";
        return;
    }
    bool loginSucess = false;
    string fileName, fileEmail, filePassword;
    while(getline(file, fileName, '*') && getline(file,fileEmail,'*') && getline(file, filePassword, '\n')) {
        if(fileName == searchName && fileEmail == searchEmail ) {
                cout << "Account Found..!!" << endl;
                cout << "Your password :: [" << filePassword << "]" << endl;
                loginSucess = true;
                break;
        }
    }
    if(!loginSucess) {
        cout << "Account not found..!! Please check your email or usename." << endl;
    }
    file.close();
}

int main() {
    loginPage user;
    int choice;
    cout << "\n1- Login";
    cout << "\n2- Sign up";
    cout << "\n3- Forget Password";
    cout << "\n4- Exit" << endl;
   do {
        cout << "\nChoose your option :: ";
        cin >> choice;
        cout << '\n';
        cin.ignore();
        switch(choice) {
            case 1:
                user.login();
                break;
            case 2:
                user.signUp();
                break;
            case 3:
                user.forgotPassword();
                break;
            case 4:
                cout << "Exit sucessful..";
                break;
            default:
                cout << "Invalid selection!!!"; 
                return 1;
        }
   }while(choice!=4);
    return 0;
}

