#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<limits>

using namespace std;

#define fname "booklist.csv"

void display_books();
void manage_books();
void menu();
void get_booklist();
void search_book();
void add_book();
void delete_book();
void search_bookname();
void search_author();
void search_ISBN();

void search_bookname(){
    cout<<"search_bookname"<<endl;
    menu();
}

void search_author(){
    cout<<"search_author"<<endl;
    menu();
}

void search_ISBN(){
    cout<<"search_ISBN"<<endl;
    menu();
}

void add_book(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"====================================<< ADD BOOK >>========================================"<<endl;
    cout<<"=========================================================================================="<<endl;

    string bookname;
    string author;
    string ISBN;
    string quantity;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Enter the book name: ";
    getline(cin, bookname);

    cout<<"Enter the author: ";
    getline(cin, author);

    cout<<"Enter ISBN: ";
    getline(cin, ISBN);
    
    cout<<"Enter the quantity: ";
    getline(cin, quantity);

    cout<<endl<<"bookname "<<bookname<<endl;
    cout<<"author "<<author<<endl;
    cout<<"isbn "<<ISBN<<endl;
    cout<<"quantity "<<quantity<<endl;

    ofstream output(fname, ios::app); //append mode
    output<<bookname<<','<<author<<','<<ISBN<<','<<quantity<<endl;
    output.close();
    
    cout<<"Book added!"<<endl;
    system("pause");
    menu();
}

void delete_book(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"===================================<< DELETE BOOK >>======================================"<<endl;
    cout<<"=========================================================================================="<<endl;
    
    menu();
}

void search_book(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"====================================<< SEARCH BY >>======================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"=====================================   1. Book Name   ==================================="<<endl;
    cout<<"=====================================   2. Author      ==================================="<<endl;
    cout<<"=====================================   3. ISBN        ==================================="<<endl;
    cout<<"=====================================   4. Back        ==================================="<<endl;    
    cout<<"=========================================================================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    int input;
    cin>>input;
    switch (input){
        case 1:
            get_booklist();;
        case 2:
            display_books();
        case 3:
            menu();
        case 4:
            manage_books();
        default:
            cout<<"Invalid Input"<<endl;
            break;
    }
}

void get_booklist(){
    system("CLS");
    vector <string> bookname;
    vector <string> author;
    vector <string> ISBN;
    vector <string> quantity;
    vector <string> line;
    string temp1, temp;
    int count;

	fstream inFile (fname, ios::in);
	if(inFile.is_open()){
        while(getline(inFile, temp1)){
            stringstream line(temp1);
            count = 0;
            while(getline(line, temp, ',')){
                switch(count){
                    case 0:
                        bookname.push_back(temp);
                        break;
                    case 1:
                        author.push_back(temp);
                        break;
                    case 2:
                        ISBN.push_back(temp);
                        break;
                    case 3:
                        quantity.push_back(temp);
                        break;
                }
                count += 1;
                if(count == 4) break;
            }
        }
	}
	else{
        cout<<"Could not open the file.\n";
        cout<<"Please check if there is booklist.csv in the folder.\n";
        exit(1);
    }
    
    for(int i=0;i<bookname.size();i++){
        cout<<"[ "<<i+1<<" ]"<<endl;
        cout<<"Book Name: "<<bookname[i]<<endl;
        cout<<"Author: "<<author[i]<<endl;
        cout<<"ISBN: "<<ISBN[i]<<endl;
        cout<<"Quantity: "<<quantity[i]<<endl<<endl;
    }
    system("pause");
}

void display_books(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"====================================<< DISPLAY BOOKS >>==================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"==================================   1. Display All Books    ============================="<<endl;
    cout<<"==================================   2. Search For A Book    ============================="<<endl;
    cout<<"==================================   3. Back To Menu         ============================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    int input;
    cin>>input;
    switch (input){
        case 1:
            get_booklist();;
        case 2:
            display_books();
        case 3:
            menu();
        default:
            cout<<"Invalid Input"<<endl;
            break;
    }
}

void manage_books(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"====================================[[ MANAGE BOOKS ]]===================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"==================================   1. Add Book       ==================================="<<endl;
    cout<<"==================================   2. Delete Book    ==================================="<<endl;
    cout<<"==================================   3. Back To Menu   ==================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    int input;
    cin>>input;
    switch (input){
    case 1:
        add_book();
        break;
    case 2:
        delete_book();
        break;
    case 3:
        menu();
    default:
        cout<<"Invalid Input"<<endl;
        break;
    }
}

void menu(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"===============================** BOOKSHOP MANAGEMENT SYSTEM **==========================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"==================================   1. Display Books   =================================="<<endl;
    cout<<"==================================   2. Manage Books    =================================="<<endl;
    cout<<"==================================   3. Exit            =================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    int input;
    cin>>input;
    switch (input){
    case 1:
        cout<<"Display Books"<<endl;
        display_books();
        break;
    case 2:
        cout<<"Manage Books"<<endl;
        manage_books();
        break;
    case 3:
        system("CLS");
        cout<<"Quit Bookstore Management System."<<endl;
        exit(1);
    default:
        break;
    }
}


int main(){
    while(1){
        menu();
    }
    return 0;
}