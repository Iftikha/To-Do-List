#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <ctime>
#include <conio.h>
#include <iomanip>


using namespace std;

void cinInt(int* nInt){
	while(!(cin>> *nInt)){
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n');
		cout<<"\nINVALID INPUT! Re-Enter: ";
	}
}

string getCurrentDate() {
    // Get the current time
    time_t now = time(0);

    // Convert to tm struct
    tm* localTime = localtime(&now);

    // Extract and format the date
    int year = 1900 + localTime->tm_year; // tm_year is years since 1900
    int month = 1 + localTime->tm_mon;   // tm_mon is 0-based
    int day = localTime->tm_mday;

    // Return formatted date as a string
    return to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

struct tasks{
	int taskID;
	string taskDesc;
	string dateAdd;
	bool check;
};

int nextID = 1;

vector<tasks> task;

int menu(){
	system("cls");
	int choice;
	cout<<"To-Do-List";
	cout<<"\n\t 1. Add Task";
	cout<<"\n\t 2. View Task";
	cout<<"\n\t 3. Mark Done";
	cout<<"\n\t 4. Remove Tasks";
	cout<<"\n\t 5. Exit";
	cout<<"\n\t Enter your choice: ";
	cinInt(&choice);
	return choice;
	
}

void addTask(){
	system("cls");
	tasks new_task;
	char con;
	new_task.taskID = nextID++;
	
	cin.ignore();
	
	cout<<"Task Description: ";
	getline(cin, new_task.taskDesc);
	
	new_task.dateAdd = getCurrentDate();
	new_task.check = false;
	
	cout<<"\nDo you want to add task to the list?";
	cin>>con;
	if(con == 'y' || con == 'Y'){
		task.push_back(new_task);
		cout<<"\nTask Added!";
		getch();
		return;
	}
	cout<<"Operation cancelled!";
	getch();
	return;
	
}

void markDone(){
	system("cls");
	if(task.size() == 0){
		cout<<"List is Empty!";
		getch();
		return;
	}
	int searchID;
	char con;
	cout<<"Enter the task ID: ";
	cinInt(&searchID);
	for(int i = 0; i < task.size(); i++){
		if(task.at(i).taskID == searchID){
			cout<<"\nTask found: "<<task.at(i).taskDesc << endl;
			cout<<"Do you want to mark done (y/n)?";
			cin>>con;
			if(con == 'y' || con == 'Y'){
				cout<<"\nDone!";
				task.at(i).check = true;
				getch();
				return;
			}
		}
	}
	cout<<"ID not found!";
	getch();
	return;
	
}

void viewTasks(){
	system("cls");
	if(task.size() == 0){
		cout<<"List is empty";
		getch();
		return;
	}
	cout<<left<<setw(10)<<"Task ID"
			  <<setw(50)<<"Task Description"
			  <<setw(5)<<"Done"
			  <<setw(15)<<"Date"
			  <<endl;
	cout<<setfill('-')<<setw(10)<<""
					 <<setw(50)<<""
					 <<setw(5)<<""
					 <<setw(15)<<""
					 <<endl;
	cout<<setfill(' ');
	for(int i = 0; i < task.size(); i++){
		cout<<left<<setw(10)<<task.at(i).taskID
				  <<setw(50)<<task.at(i).taskDesc
				  <<setw(5)<<((task.at(i).check)?"Yes":"No")
				  <<setw(10)<<task.at(i).dateAdd
				  <<endl;
	}
	getch();
	return;
}

void reassignTaskIDs() {
    for (int i = 0; i < task.size(); i++) {
        task[i].taskID = i + 1; 
    }
}


void deleteTask(){
	system("cls");
	if(task.size() == 0){
		cout<<"List is empty!";
		getch();
		return;
	}
	int searchID;
	char con;
	
	cout<<"Search by ID: ";
	cinInt(&searchID);
	for(int i = 0; i < task.size(); i++){
		if(task.at(i).taskID == searchID){
			cout<<"Task found!\n";
			cout<<task.at(i).taskDesc<<endl;
			cout<<"Do you want to continue (y/n)?";
			cin>>con;
			if(con == 'y' || con == 'Y'){
				task.erase(task.begin()+i);
				cout<<"Task Deleted!";
				reassignTaskIDs();
				getch();
				return;
				
			}
		}
	}
	
	cout<<"ID not found!";
	
}




int main() {
    int choice1;

    while (true) {
        choice1 = menu(); 

        switch (choice1) {
            case 1:
                addTask();    
                break;
            case 2:
                viewTasks();  
                break;
            case 3:
                markDone();   
                break;
            case 4:
                deleteTask(); 
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;     
            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    }

}






