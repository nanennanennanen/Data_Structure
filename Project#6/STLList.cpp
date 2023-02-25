#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <list>


using namespace std;

int main()
{
    double GPA;
    double highestGPA;
    string name;

    list<string> strList;

    ifstream readFile;

    readFile.open("HighestGPAData.txt");     

    cout << "<List Mode>" << endl;

    if (!readFile)                           
    {
        cout << "The input file does not "
            << "exist. Program terminates!"
            << endl;
        return 1;
    }

    cout << fixed << showpoint;              
    cout << setprecision(2);                 

    readFile >> GPA >> name;                 

    highestGPA = GPA;                        

    while (readFile)                         
    {
        if (GPA > highestGPA)                
        {
            strList.clear();

            if (strList.empty())        
                strList.emplace_back(name);

            highestGPA = GPA;                
        }
        else if (GPA == highestGPA)          
                strList.emplace_back(name);
            //else
            //{
            //    cout << "Stack overflows. "
            //        << "Program terminates!"
            //        << endl;
            //    return 1;  //exit program
            //}
        readFile >> GPA >> name;             
    }

    cout << "Highest GPA = " << highestGPA
        << endl;                             
    cout << "The students holding the "
        << "highest GPA are:" << endl;

    while (!strList.empty())            
    {
        cout << strList.front() << endl;
        strList.pop_front();
    }

    cout << endl;

    return 0;
}