#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ID = 0;

struct todolist{
    int id;
    string task;
};

void banner(){
    cout<<"_________________________________"<<endl;
    cout<<"\n\t   My ToDo List"<<endl;
    cout<<"_________________________________"<<endl;
}

void addTask(){
    system("cls");
    banner();
    todolist todo;
    cout<<"Enter new task: "<<endl;
    cin.ignore();
    getline(cin, todo.task);
    char save;
    cout<<"Save? (y/n): ";
    cin>>save;
    if(save='y'){
        ID++;
        todo.id = ID;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout<<todo.id<<"."<<todo.task<<endl;
        fout.close();
        char more;
        cout<<"Add more task? (y/n): ";
        cin>>more;
        if(more=='y'){
            addTask();
        }else{
            system("cls");
            cout<<"Added Successfully!"<<endl;
            return;
        }
    }
    system("cls");
}

void showTask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"Task: "<<endl;
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        cout << "\t" << todo.id << ": " << todo.task << endl;
    }
    fin.close();
    char exit;
    cout<<"Exit? (y/n): ";
    cin>>exit;
    if(exit!='y'){
        showTask();
    }
    system("cls");
}

int searchTask(){
    system("cls");
    banner();
    int id;
    cout<<"Enter task id: ";
    cin >> id;
    todolist todo;
    ifstream fin("todo.txt");
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id) {
            system("cls");
            cout << "\t" << todo.id << ": " << todo.task << endl;
            return id;
        }
    }
    system("cls");
    cout<<"Not found!"<<endl;
    return 0;
}

void deleteTask(){
    system("cls");
    int id=searchTask();
    if(id!=0){
        char del;
        cout<<"\n\tDelete? (y/n): ";
        cin>>del;
        if(del=='y'){
            todolist todo;
            ofstream tempFile;
            tempFile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");
            while (fin >> todo.id) {
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != id) {
                    tempFile << todo.id << ". " << todo.task << endl;
                }
            }
            fin.close();
            tempFile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout<<"\n\tDeleted Successfully!"<<endl;
        }else{
            system("cls");
            cout<<"Not Deleted!"<<endl;
        }
    }
}

int main(){
    system("cls");
    while(true){
        banner();
        cout<<"\n\t1. Add Task";
        cout<<"\n\t2. Show Task";
        cout<<"\n\t3. Search Task";
        cout<<"\n\t4. Delete Task";

        int choice;
        cout<<"\n\tEnter Choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            addTask();
            break;
            case 2:
            showTask();
            break;
            case 3:
            searchTask();
            break;
            case 4:
            deleteTask();
            break;
            default:
            break;
        }
    }
    return 0;
}