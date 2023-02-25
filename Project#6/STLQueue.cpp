#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>


using namespace std;

int main()
{
    double GPA;
    double highestGPA;
    string name;

    queue<string> strQueue;

    ifstream readFile;

    readFile.open("HighestGPAData.txt");      

    cout << "<Queue Mode>" << endl;

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
            while(!strQueue.empty())
                strQueue.pop();            
                    
                strQueue.push(name);

            highestGPA = GPA;                 
        }
        else if (GPA == highestGPA)           
                strQueue.push(name);
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

    while (!strQueue.empty())              
    {
        cout << strQueue.front() << endl;
        strQueue.pop();
    }

    cout << endl;

    return 0;
}