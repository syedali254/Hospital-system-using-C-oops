#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<cstring>
using namespace std;

class Person {
	protected:
		int counter = 0;
public:
    
    virtual void add_info() = 0;
    virtual void display_info() = 0;
    virtual void details() = 0;
    virtual void total_count() = 0;
    virtual ~Person() {} // Virtual destructor for polymorphism
};

struct doctor1 // Struct that stores doctor info
{
    int id,age,exp;
    char name[20], Q[20], city[20], special[20];
};

struct patient1
{
    int id1,age,room, charg ,bill ;
    char name[20], city[20], dis[20],sym[20], con[20], date[20];
};

class Doctor : public Person{

int docid = 0;

public:
    
    doctor1 arr[10]; // Object of structure doctor1
  
    friend void  doc_salary(Doctor &,int inc,int no,int identity);
    
    void add_info() 
    {
        int en;
        cout << "How Many Entries you want to add: ";
        cin >> en;
        for (int i = 1; i <= en; i++)
        {
            cout << "Enter Doctor's ID                :";
            cin >> arr[docid].id;
            cout << "Enter Doctor's Name              :";
            cin >> arr[docid].name;
            cout << "Enter Doctor's Age               :";
            cin >> arr[docid].age;
            cout << "Enter Doctor's Qualification     :";
            cin >> arr[docid].Q;
            cout << "Enter Doctor's Specialization    :";
            cin >> arr[docid].special;
            cout << "Enter Doctor's Experience        :";
            cin >> arr[docid].exp;
            cout << "Enter Doctor's city              :";
            cin >> arr[docid].city;
            docid++;
            counter++;
            cout << "\n";
            cout << "You filled all Entries of " << i << " doctor successfully" << "\n";
            cout << "Enter value for " << i + 1 << " doctor" << "\n";
        }
    }

    void display_info() 
    {
        system("cls");
        int n, i, index;
        cout << "Enter the doctor's ID  to display Record: ";
        cin >> n;
        if (docid== 0)
        {
            cout << "\n\n                      OOPS!!!!             " << "\n\n";
            cout << "Note:-   No Record To Display Plz Go Back And Enter Some Entries..." << "\n";
        }
        else
        {
            int status = 0;
            for (int i = 0; i < docid; i++)
            {
                if (arr[i].id == n)
                {
                    index = i;
                    status = 1;
                    break;
                }
            }
            if (status == 1)
            {
                system("cls");
                cout << "1.Doctor's ID                 :" << arr[index].id << "\n\n";
                cout << "2.Doctor's Name               :" << arr[index].name << "\n\n";
                cout << "3.Doctor's Age                :" << arr[index].age << "\n\n";
                cout << "4.Doctor's Qualification      :" << arr[index].Q << "\n\n";
                cout << "5.Doctor's Specialization     :" << arr[index].special << "\n\n";
                cout << "6.Doctor's Experience         :" << arr[index].exp << "\n\n";
                cout << "8.Doctor's city               :" << arr[index].city << "\n\n";
                cout << "\nPress Any KEY To choose another Option...";
            }
            else
            {
                cout << "\n\nNo such ID in database " << endl;
                cout << "\nPress Any KEY To choose another Option...";
            }
        }
        getch();
    }

    void details() 
    {
        int i;
        if (docid == 0)
        {
            cout << "\n\n\n                                  OOPS!!!!             " << "\n\n";
            cout << "Note:-   No Record To Display  Plz Go Back And Enter Some Entries..." << "\n";
        }
        else
        {
            cout << "********************************************************************************" << "\n";
            cout << "\t \t \t  Details Of All The Doctors In The Hospital \n";
            cout << "********************************************************************************" << "\n \n";

            cout << "ID" << "\t \t" << "specialization" << "\t \t" << "Qualification" << "\t \t" << "Age";
            cout << "\n \n";

            for (i = 0; i < docid; i++)
            {
                cout << arr[i].id << "\t \t" << arr[i].special << "\t \t \t" << arr[i].Q << "\t  \t \t" << arr[i].age << "\n";
            }
            cout << "\nPress Any Button To choose another Option...";
        }
        getch();
    }

    void total_count() 
    {
        system("cls");
        int no_of_doctors = counter;
        cout << "Total Doctor's in Hospital: " << no_of_doctors << "\n";
        cout << "\nPress Any Button To choose another Option...";
        getch();
    }
};
void doc_salary(Doctor &d,int inc,int no,int identity){
	   int index = -1; 
    
    // Accessing Doctor's data through the passed object
    doctor1 *arr = d.arr; // Accessing the array of doctors
   
    
    // Search for the doctor with the given ID
    for (int i = 0; i < d.docid; i++) {
        if (arr[i].id == identity) {
            index = i;
            break;
        }
    }
    
    // If doctor with given ID is not found, return 0
    if (index == -1) {
        cout << "No such doctor found." << endl;
        getch();
        return;
    }
    
    int salary = inc * no;
    cout << "Salary of Doctor " << arr[index].name << " is " << salary << endl;
   
	
}

class Patient : public Person
{
	int docid1 = 0;
public:
    
    patient1 arr[10];
friend void generate_bill(Patient &,int ide);
    void add_info()
    {
        int i, en;
        cout << "How Many Entries you want to add: ";
        cin >> en;
        for (i = 1; i <= en; i++)
        {
            cout << "1.Enter Patient's ID                                 :";
            cin >> arr[docid1].id1;
            cout << "2.Enter patient's Name                               :";
            cin >> arr[docid1].name;
            cout << "3.Enter patient's Age                                :";
            cin >> arr[docid1].age;
            cout << "4.Enter patient's Disease                            :";
            cin >> arr[docid1].dis;
            cout << "5.Enter patient's Symptoms                           :";
            cin >> arr[docid1].sym;
            cout << "6.Enter Patient's Room No.                           :";
            cin >> arr[docid1].room;
            cout << "7.Enter Patient's condition Before Admit             :";
            cin >> arr[docid1].con;
            cout << "8.Enter Patient's ADMIT Date                         :";
            cin >> arr[docid1].date;
            cout << "9.Enter Patient's Room Charge                        :";
            cin >> arr[docid1].charg;
            cout << "10.Enter Patient's Medicine charge                   :";
            cin >> arr[docid1].bill;
            docid1++;
            counter++;
            cout << "\n";
            cout << "You filled all Entries of " << i << " patient successfully" << "\n";
            cout << "Enter value for " << i + 1 << " patient" << "\n";
        }
    }

    void display_info() 
    {
        system("cls");
        int n, i, index;
        cout << "\nEnter the Patient's ID to display info: ";
        cin >> n;
        if (docid1 == 0)
        {
            cout << "\n\n                      OOPS!!!!             " << "\n \n";
            cout << "Note:-   No Record To Display  Plz Go Back And Enter Some Entries..." << "\n";
            cout << "\nPress Any KEY To choose another Option...";
        }
        else
        {
            int status = 0;
            for (i = 0; i < docid1; i++)
            {
                if (arr[i].id1 == n)
                {
                    index = i;
                    status = 1;
                    break;
                }
            }
            if (status == 1)
            {
                cout << "1.Patient's ID                                      :" << arr[index].id1 << "\n";
                cout << "2.Patient's Name                                    :" << arr[index].name << "\n";
                cout << "3.Patient's Age                                     :" << arr[index].age << "\n";
                cout << "4.Patient's  Disease                                :" << arr[index].dis << "\n";
                cout << "5.Patient's Symptoms                                :" << arr[index].sym << "\n";
                cout << "6.Patient's Room No.                                :" << arr[index].room << "\n";
                cout << "7.Patient's condition Before Admit                  :" << arr[index].con << "\n";
                cout << "8.Patient's ADMIT Date                              :" << arr[index].date << "\n";
                cout << "9.Patient's Room Charge                             :" << arr[index].charg << "\n";
                cout << "10.Patient's Medicine charge                        :" << arr[index].bill << "\n";
                cout << "\nPress Any KEY To choose another Option...";
            }
            else
            {
                cout << " \n\n No such ID in database " << endl;
                cout << " \n Press Any KEY To choose another Option...";
            }
        }
        getch();
    }
    
    void details() 
    {
        int i;
        if (docid1 == 0)
        {
            cout << " \n\n\n\n\n                                  OOPS!!!!             " << "\n\n\n";
            cout << "Note:-   No Record To Display  Plz Go Back And Enter Some Entries...... " << "\n";
        }
        else
        {
            cout << "********************************************************************************" << "\n";
            cout << "\t \t \t  Details Of All The Pateint In The Hospital \n";
            cout << "********************************************************************************" << "\n \n";
            cout << "ID" << "\t \t" << "illness" << "\t \t" << "ADMITTED Date" << "\t \t" << "Age";
            cout << "\n \n";
            for (i = 0; i < docid1; i++)
            {
                cout << arr[i].id1 << "\t \t" << arr[i].dis << "\t \t \t" << arr[i].date << "\t  \t \t" << arr[i].age << "\n";
            }
            cout << " \n Press Any KEY To choose another Option.... ";
        }
        getch();
    }

    void total_count() 
    {
        system("cls");
        int no_of_patients = counter;
        cout << "Total Patients in Hospital    :   " << no_of_patients << "\n";
        cout << "\nPress Any KEY To choose another Option.... ";
        getch();
    }

    void patient_report()
    {
        system("cls");
        int i, n;
        cout << "\nEnter the Patient's ID to Display  Report: ";
        cin >> n;
        int status = 0;
        for (i = 0; i < docid1; i++)
        {
            if (arr[i].id1 == n)
            {
                status = 1;
                break;
            }
        }
        if (status)
        {
            cout << "------------------------------------------" << endl;
            cout << "Patient's Report" << "\n";
            cout << "------------------------------------------" << endl << endl;
            cout << "1. Patient's Name: " << arr[i].name << "\n";
            cout << "2. Patient's Age: " << arr[i].age << "\n";
            cout << "3. Patient symptoms: " << arr[i].sym << "\n";
            cout << "4. Patient Disease: " << arr[i].dis << "\n";
            cout << "5. Patient Admit Date: " << arr[i].date << "\n";
            cout << "6. Patient condition At The Time Of Discharge: " << arr[i].con << "\n";
            cout << "Press Any Key To Go Back...";
        }
        else
        {
            cout << " \n\n No such ID in database " << endl;
            cout << " \n Press Any KEY To choose another Option...";
        }
        getch();
    }
//
   
};
void generate_bill(Patient &p, int ide) {
    int index, status = 0;

    // Search for the patient with the given ID
    for (int i = 0; i < p.docid1; i++) {
        if (p.arr[i].id1 == ide) {
            status = 1;
            index = i;
            break;
        }
    }

    // If patient with given ID is not found, return 0
    if (status == 0) {
        cout << "No such Account " << endl;
        cout << "Press any key to return to the main menu...";
        getch(); 
        return; 
    }

    
    int total = p.arr[index].bill + p.arr[index].charg; 
    cout << "Total Bill for patient " << p.arr[index].name << ": " << total << endl;

    cout << "\nPress any key to return to the main menu...";
    getch(); // Wait for user input
}


int main()
{
    system("color 73");
    bool repeat = true;//bool variable and intialized to true used for iteration or looping behavior
    int ch1, ch2, ch3, ch4;
    Person* people[2]; // 2 Array of pointers to Person objects
    Doctor d;
    Patient p;
    people[0] = &d; // Assigning Doctor object to the base class pointer
    
    people[1] = &p; // Assigning Patient object to the base class pointer
xyz:
    
system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
	cout<<"\t\t\t\t\t@@|                                WELCOME TO                                             |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                          HOSPITAL MANAGEMENT SYSTEM                                   |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
	cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
 	cout << "Press any key to continue";
  	getch();
  	system("cls");
    cout<<"------------------------------------------"<<endl;
    cout<<"Welcome to the Hospital Management System"<<endl;
    cout<<"------------------------------------------"<<endl<<endl;
    cout<<"1. Menu"<<"\n\n";;
    cout<<"2. Exit"<<"\n\n";
    cout<<"Enter Your Choice: ";
    cin>>ch1;

    if (ch1 == 1)
    {
xyz2:
        system("cls");
        cout << "1.Enter into Doctor's DataBase" << endl << endl;
        cout << "2.Enter into Patient's DataBase" << endl << endl;
        cout << "3.Generate Patient's Report" << endl << endl;
        cout << "4.Generate Patient's Bill" << endl << endl;
        cout <<"5.Calculate Doctors Salary "<<endl<<endl;
        cout << "6.EXIT" << "\n\n";
        cout << "Enter Your choice: ";
        cin >> ch2;
        while (repeat == true)
        {
            switch (ch2)
            {
            case 1:
            {
            	
                cout << "------------------------------------------" << endl;
                cout << "Welcome To Doctor's DataBase" << "\n";
                cout << "------------------------------------------" << endl << endl;
                cout << "1. Add New Doctor's Information" << endl << endl;
                cout << "2. Display Doctor's Information" << endl << endl;
                cout << "3. Display All Doctor's Details" << endl << endl;
                cout << "4. Total Number of Doctor's in Hospital" << endl << endl;
                cout << "5. Main Menu" << endl << endl;
                cout << "Enter Your choice: ";
                cin >> ch3;

                switch (ch3)
                {
                case 1: 
                system("cls");
				people[0]->add_info();//doctor function as ptr people[0]store refrence of doctors object
				 break;
                case 2: people[0]->display_info(); break;
                case 3:
                	system("cls");
				 people[0]->details(); 
				 break;
                case 4: people[0]->total_count(); break;
                case 5: goto xyz2; break;
                }
                break;
            }
            case 2:
            { system("cls");
                cout << "------------------------------------------" << endl;
                cout << "Welcome To Patient's DataBase" << "\n";
                cout << "------------------------------------------" << endl << endl;
                cout << "1. Add New Patient's Information" << endl << endl;
                cout << "2. Display Patient's Information" << endl << endl;
                cout << "3. Display All Patient's Details" << endl << endl;
                cout << "4. Total Number of Patient's in Hospital" << endl << endl;
                cout << "5. Main Menu" << endl << endl;
                cout << "Enter Your choice: ";
                cin >> ch4;

                switch (ch4)
                {
                case 1: 
				system("cls");
				people[1]->add_info();//calls patients functionality
				 break;
                case 2: people[1]->display_info(); break;
                case 3:
				system("cls"); 
				people[1]->details();
				 break;
                case 4: people[1]->total_count(); break;
                case 5: goto xyz2; break;
                }
                break;
            }
            case 3:
            {
                p.patient_report();
                break;
            }
            case 4:
            {
	
                int id;
                cout << "Enter Patient ID to generate bill: ";
                cin >> id;
                 generate_bill(p, id);
                 getch();
                 goto xyz2;
            }
            case 5:{
            	int income_patient,no_of_patients_week,identity;
            	   cout << "Enter Doctor id to calculate salary: ";
                      cin >> identity;
            		cout<<"Enter Doctors Income Per patient "<<endl;
    	cin>>income_patient;
    	cout<<"Enter no of patients Doctor Treated "<<endl;
    	cin>>no_of_patients_week;
            	doc_salary(d,income_patient,no_of_patients_week,identity);
            	
            	cout << "\nPress Any KEY To choose another Option.... ";
            	
                getch();
				goto xyz2;
				
			}
            case 6:
            {
                cout << "\n\nTHANK YOU FOR USING THE SOFTWARE";
                exit(0);
            }
            }
        }
    }
    else if (ch1 == 2)
    {
	system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                           		                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                THANK YOU FOR USING                                    |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                          HOSPITAL MANAGEMENT SYSTEM                                   |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
	cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
	cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
 	
 	
        return 0;
    }
    else
    {
        cout << "Please Enter a valid choice";
        goto xyz;
    }

    return 0;
}
