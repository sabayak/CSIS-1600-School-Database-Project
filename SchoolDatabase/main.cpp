#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int slines = 0;
int tlines = 0;
string line;
int currentNumberOfStudents = 0;
int currentNumberOfTeachers = 0;



void getdbSize()
{

    std::string sline, tline;
    std::ifstream sfile("students.txt");
    std::ifstream tfile("teachers.txt");

    while (std::getline(sfile, sline))
        ++slines;
    while (std::getline(tfile, tline))
        ++tlines;


}

struct Students{
    string fname,lname;
    string space = " ";
    int year;
    int active;
    int class1, class2, class3, class4;
    string grade1, grade2, grade3, grade4;
}sdb[10];
struct Teachers{
    string fname, lname;
    string space = " ";
    int class1, class2, class3, class4;
}tdb[10];
struct Courses{
    string courses;
}cdb[10];


void studentMenu();
void adminMenu();
void defaultMenu();
void teacherMenu();
void newStudent();
void addDropClass();
void viewClass();
void viewGrades();
void displayStudentStructure();
void approveStudent();

void displayStudentStructure()
{
    ifstream sdatabaseInFile;

    int testvar = sizeof(sdb)/sizeof(sdb[0]);

    sdatabaseInFile.open("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/students.txt"); // open students.txt

    if(sdatabaseInFile.fail())
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {

        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            sdatabaseInFile>>
            sdb[i].fname>>
            sdb[i].lname>>
            sdb[i].year>>
            sdb[i].active>>
            sdb[i].class1>>
            sdb[i].class2>>
            sdb[i].class3>>
            sdb[i].class4>>
            sdb[i].grade1>>
            sdb[i].grade2>>
            sdb[i].grade3>>
            sdb[i].grade4;
            cout <<"Student no "<<i<<" loaded"<<endl;
        }
        cout <<"All students have been successfully loaded"<<endl;
    }


        for(int i = 0; i < testvar; i++)
        {
            cout <<
            sdb[i].fname<<
            sdb[i].lname<<
            sdb[i].year<<
            sdb[i].active<<
            sdb[i].class1<<
            sdb[i].class2<<
            sdb[i].class3<<
            sdb[i].class4<<
            sdb[i].grade1<<
            sdb[i].grade2<<
            sdb[i].grade3<<
            sdb[i].grade4 << endl;
            //cout <<"Student no "<<i<<" loaded"<<endl;
        }
}

//Load Student Database
void classes_load()
{

    ifstream classesInFile("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/classes.txt");

    if(!classesInFile)
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof(cdb)/sizeof(cdb[0]); i++)
        {
            classesInFile>>
            cdb[i].courses;

        }
        cout <<"All classes have been successfully loaded"<<endl;

        classesInFile.close();
    }
}

void sdatabase_load()
{

    ifstream sdatabaseInFile;

    sdatabaseInFile.open("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/students.txt"); // open students.txt

    if(sdatabaseInFile.fail())
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {

        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            sdatabaseInFile>>
            sdb[i].fname>>
            sdb[i].lname>>
            sdb[i].year>>
            sdb[i].active>>
            sdb[i].class1>>
            sdb[i].class2>>
            sdb[i].class3>>
            sdb[i].class4>>
            sdb[i].grade1>>
            sdb[i].grade2>>
            sdb[i].grade3>>
            sdb[i].grade4;
            cout <<"Student no "<<i<<" loaded"<<endl;
        }
        cout <<"All students have been successfully loaded"<<endl;
        sdatabaseInFile.close();
    }
}
void sdatabase_save()
{
    ofstream sdatabaseOutFile("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/students.txt");

    if(!sdatabaseOutFile)
    {
        cout<<"Cannot save file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            sdatabaseOutFile<<
            sdb[i].fname<<
            sdb[i].lname<<
            sdb[i].year<<
            sdb[i].active<<
            sdb[i].class1<<
            sdb[i].class2<<
            sdb[i].class3<<
            sdb[i].class4<<
            sdb[i].grade1<<
            sdb[i].grade2<<
            sdb[i].grade3<<
            sdb[i].grade4;
            cout <<"Student no "<<i<<"saved"<<endl;
        }
        cout <<"All students have been successfully saved"<<endl;
        sdatabaseOutFile.close();
    }
}
void tdatabase_load()
{

    ifstream tdatabaseInFile;

    tdatabaseInFile.open("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/teachers.txt");


    if(!tdatabaseInFile)
    {
        cout<<"Cannot save file"<<endl;
        return;
    }
    else
    {

        for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
        {
            tdatabaseInFile>>
            tdb[i].fname>>
            tdb[i].lname>>
            sdb[i].class1>>
            sdb[i].class2>>
            sdb[i].class3>>
            sdb[i].class4;
            //cout <<"Teacher no "<<i<<"loaded"<<endl;
        }
        cout <<"All teachers have been successfully loaded"<<endl;
        tdatabaseInFile.close();
    }
}
void tdatabase_save()
{
    ofstream tdatabaseOutFile("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/teachers.txt");
    if(!tdatabaseOutFile)
    {
        cout<<"Cannot save file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
        {
            tdatabaseOutFile<<
            tdb[i].fname<<
            tdb[i].space<<
            tdb[i].lname<<
            tdb[i].class1<<
            tdb[i].class2<<
            tdb[i].class3<<
            tdb[i].class4;
            cout <<"Teacher no "<<i<<"saved"<<endl;
            cout << tdb[i].fname << endl;
        }
        cout <<"All teachers have been successfully saved"<<endl;
        tdatabaseOutFile.close();
    }
}
//register as a new student
void newStudent()
{
    string fname;
    string lname;
    char response;

    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    //display the input to user and give user the choice if it is correct or not
    cout << "Your name is " << fname << " " << lname << ".\n"
         << "Is this correct?(y or n): ";
    cin >> response;//user response to yes or no

    //if it is correct then a message display to let user know they can register for classes
    if(tolower(response) == 'y')
    {
        //outFile << fname << " " << lname;
        cout << "Now you can register for classes!" << endl;
    }
    //if it is not correct then user can input their names again
    if(tolower(response) == 'n')
    {
        //this while loop while continue to run as long as response is no or n
        while(response != 'y')
        {
            cout << "Enter your first name: ";
            cin >> fname;
            cout << "Enter your last name: ";
            cin >> lname;
            //display the input to user and give user the choice if it is correct or not
            cout << "Your name is " << fname << " " << lname << ".\n"
                 << "Is this correct?(y or n): ";
            cin >> response;
            if(response == 'y')
            {
                sdb[slines+1].fname = fname;
                sdb[slines+1].lname = lname;
            }
        }
    }
}
//add or drop classes(student)
void addDropClass()
{
    string fname;
    string lname;
    char response;
    int j=0;

    cout << "Please Enter your first name:" << endl;
    cin >> fname;
    cout << "Please enter your last name:" << endl;
    cin >> lname;

    ifstream sdatabaseInFile;

    sdatabaseInFile.open("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/students.txt"); // open students.txt

    if(sdatabaseInFile.fail())
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {

        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            sdatabaseInFile>>
            sdb[i].fname>>
            sdb[i].lname>>
            sdb[i].year>>
            sdb[i].active>>
            sdb[i].class1>>
            sdb[i].class2>>
            sdb[i].class3>>
            sdb[i].class4>>
            sdb[i].grade1>>
            sdb[i].grade2>>
            sdb[i].grade3>>
            sdb[i].grade4;
            //cout <<"Student no "<<i<<" loaded"<<endl;
        }
        //cout <<"All students have been successfully loaded"<<endl;
    }

    int i=0;
    while (i <sizeof(sdb)/sizeof(sdb[0]))
    {
        if (sdb[i].fname == fname)
        {
            if (sdb[i].lname == lname)
            {
                if (sdb[i].active == 0)
                {
                    cout << "You have not been approved to add classes yet. Please check with an administrator." << endl;
                    studentMenu();
                }
            }
        }
        i++;
    }

    sdatabaseInFile.close();
    char input;
    cout << "Do you want to add or drop class?\n"
         << "To add class enter (a) and to drop class enter (d) (a or d): ";
    cin >> input;
    if(input == 'a')
    {
        int numb;
        char choice;
        cout << "Here is the list of classes offer this semester: " << endl;
        //here will be the classes file

        ifstream classesInFile("/Volumes/Banksy/Users/kirbatron/HDD-Documents/QT Projects/Group_Project/classes.txt");

        while (getline(classesInFile,line))
        {
            cout << line << endl;
        }


        cout << "Please enter the number of the class you want to take: ";
        cin >> numb;
        //I will put in if-else statement here to get the class that user chose

        //the for loop here is to limit the classes student can take to 4
        for(int i = 0; i < 3; i++)
        {
            cout << "Would you like to add another class(y or n): ";
            cin >> choice;
            if(choice == 'y')
            {
                //redisplay the class again
                cout << "Enter the number of the class you want to take: ";
                cin >> numb;
                //if-else statement here to get the class user chose
            }
            if(choice == 'n')
            {
                cout << "Now you can check your schedule!" << endl;
                break;
            }
        }

        if(input == 'd')
        {
            ifstream inFile;
            int cnum;
            inFile.open("classes.txt");
            if(inFile.fail())
            {
                cout << "You have not yet register for any classes!" << endl;
                exit(1);
            }

            cout << "Which class would you like to drop(enter the number): ";
            cin >> cnum;
            //here would be codes to delete the class of student choice
        }


    }
}

//view class schedule
void viewClass()
{
    //after all the add or drop classes the class schedule will display
}
//view grades
void viewGrades()
{
    //the grades will be display with the file upload by the teacher
}
void teacherMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Teacher Menu - Choose your role:\n";
               cout << "  ====================================\n";
               cout << "  1.  View Class Schedule\n";
               cout << "  2.  View Student Schedule\n";
               cout << "  3.  Assign Grades\n";
               cout << "  4.  Back to Main Menu\n";
               cout << "\n";
               cout << "  5.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //View Class Schedule
                       studentMenu();
                       break;

                   case '2':
                       //View Student Schedule
                       teacherMenu();
                       break;
                   case '3':
                       //Assign Grades
                       viewGrades();
                       break;
                   case '4':
                       defaultMenu();
                       break;
                   case '5':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}

void studentMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Student Menu:\n";
               cout << "  ====================================\n";
               cout << "  1.  Register\n";
               cout << "  2.  Add/Remove Classes\n";
               cout << "  3.  View Class Schedule\n";
               cout << "  4.  View Grades\n";
               cout << "  5.  Back to Main Menu\n";
               cout << "\n";
               cout << "  6.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //Register
                       newStudent();
                       break;

                   case '2':
                       //Add/Remove Classes
                       addDropClass();
                       break;
                   case '3':
                       //View Class Schedule
                       viewClass();
                       break;
                   case '4':
                       //View Grades
                       adminMenu();
                       break;
                   case '5':
                       defaultMenu();
                       break;
                   case '6':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}

void adminMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Admin Menu:\n";
               cout << "  ====================================\n";
               cout << "  1.  Add/Remove Students\n";
               cout << "  2.  Add/Remove Teachers\n";
               cout << "  3.  Approve/Reject Students\n";
               cout << "  4.  Back to Main Menu\n";
               cout << "\n";
               cout << "  5.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //Add/Remove Students
                       studentMenu();
                       break;

                   case '2':
                       //Add/Remove Teachers
                       teacherMenu();
                       break;
                   case '3':
                       //Approve/Reject Students
                       adminMenu();
                       break;
                   case '4':
                       defaultMenu();
                       break;
                   case '5':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}

void defaultMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Main Menu - Choose your role:\n";
               cout << "  ====================================\n";
               cout << "  1.  Student.\n";
               cout << "  2.  Teacher\n";
               cout << "  3.  Admin\n";
               cout << "\n";
               cout << "  4.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //Student
                       studentMenu();
                       break;

                   case '2':
                       //Teacher
                       teacherMenu();
                       break;
                   case '3':
                       //Admin
                       adminMenu();
                       break;
                   case '4':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}


int main()
{
    displayStudentStructure();
    getdbSize();

    sdatabase_load();

    tdatabase_load();
    classes_load();
    tdatabase_save();
    //Test print the database after initialization
    /*
    for(int j = 0; j < 5; j++)
        {
        cout<<sdatabase[j].fname<<sdatabase[j].lname;
        cout<<tdatabase[j].fname<<tdatabase[j].lname;
        }
    */
   defaultMenu();
}
