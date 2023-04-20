#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<limits>

using namespace std;

#define fname "booklist.csv"

void display_or_search();
void manage_books();
void menu();
void display_books();
void search_book_menu();
void search_book(int num);
void add_book();
void delete_book();
vector <int> search_bookname(vector <string> bookname);
vector <int> search_author(vector <string> author);
vector <int> search_ISBN(vector <string> ISBN);

vector <int> search_bookname(vector <string> bookname){
    string input;
    vector <int> positions;
    cout<<"Enter the bookname you want to search:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    for (int i = 0; i < bookname.size(); i++) {
        if (bookname[i] == input) {
            positions.push_back(i);
        }
    }

    if(positions.size() == 0) cout<<"Book with name: [ "<<input<<" ]"<<" not found in store."<<endl<<endl;

    return positions;
}

vector <int> search_author(vector <string> author){
    string input;
    vector <int> positions;
    cout<<"Enter the author you want to search:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    for (int i = 0; i < author.size(); i++) {
        if (author[i] == input) {
            positions.push_back(i);
        }
    }

    if(positions.size() == 0) cout<<"Book with author: [ "<<input<<" ]"<<" not found in store."<<endl<<endl;
    return positions;
}

vector <int> search_ISBN(vector <string> ISBN){
    string input;
    vector <int> positions;
    cout<<"Enter the ISBN you want to search:"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    for (int i = 0; i < ISBN.size(); i++) {
        if (ISBN[i] == input) {
            positions.push_back(i);
        }
    }

    if(positions.size() == 0) cout<<"Book with ISBN: [ "<<input<<" ]"<<" not found in store."<<endl<<endl;

    return positions;
}

void search_book(int num){
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
    inFile.close();

    vector <int> positions;
    switch (num){
        case 1:
            positions = search_bookname(bookname);
            break;
        case 2:
            positions = search_author(author);
            break;
        case 3:
            positions = search_ISBN(ISBN);
            break;
    }

    if(positions.size() != 0){
        cout<<"===================================<< BOOK FOUND >>======================================="<<endl;
        for (int i = 0; i < positions.size(); i++) {
            cout<<"Book Name: "<<bookname[positions[i]]<<endl;
            cout<<"Author: "<<author[positions[i]]<<endl;
            cout<<"ISBN: "<<ISBN[positions[i]]<<endl;
            cout<<"Quantity: "<<quantity[positions[i]]<<endl<<endl;
        }
        cout<<endl;
    }

    system("pause");
    menu();
}

void add_book(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"====================================<< ADD BOOK >>========================================"<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"**Do not contain any commas in the data.**"<<endl;
    cout<<"**Do not contain any extra spaces in front of or at the end of the data.**"<<endl<<endl;

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

    ofstream output(fname, ios::app); //append mode
    output<<bookname<<','<<author<<','<<ISBN<<','<<quantity<<endl;
    output.close();
    
    cout<<"Book added!"<<endl<<endl;
    system("pause");
    menu();
}

void delete_book(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"===================================<< DELETE BOOK >>======================================"<<endl;
    cout<<"=========================================================================================="<<endl;


    system("pause");
    menu();
}

void search_book_menu(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"=====================================<< SEARCH BY >>======================================"<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"====================================   1. Book Name   ===================================="<<endl;
    cout<<"====================================   2. Author      ===================================="<<endl;
    cout<<"====================================   3. ISBN        ===================================="<<endl;
    cout<<"====================================   4. Back        ===================================="<<endl;    
    cout<<"=========================================================================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    int input;
    cin>>input;
    switch (input){
        case 1:
            search_book(1);;
        case 2:
            search_book(2);
        case 3:
            search_book(3);
        case 4:
            manage_books();
        default:
            cout<<"Invalid Input"<<endl;
            break;
    }
}

void display_books(){
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
    inFile.close();
    
    for(int i=0;i<bookname.size();i++){
        cout<<"[ "<<i+1<<" ]"<<endl;
        cout<<"Book Name: "<<bookname[i]<<endl;
        cout<<"Author: "<<author[i]<<endl;
        cout<<"ISBN: "<<ISBN[i]<<endl;
        cout<<"Quantity: "<<quantity[i]<<endl<<endl;
    }
    system("pause");
    menu();
}

void display_or_search(){
    system("CLS");
    cout<<"=========================================================================================="<<endl; // = * 90
    cout<<"====================================<< DISPLAY OR SEARCH >>==============================="<<endl;
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
            display_books();;
        case 2:
            search_book_menu();
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
    cout<<"===============================   1. Display Or Search Books   ==========================="<<endl;
    cout<<"===============================   2. Manage Books              ==========================="<<endl;
    cout<<"===============================   3. Exit                      ==========================="<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"=========================================================================================="<<endl;
    int input;
    cin>>input;
    switch (input){
    case 1:
        cout<<"Display Books"<<endl;
        display_or_search();
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