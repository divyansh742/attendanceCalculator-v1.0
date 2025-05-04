// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
using namespace std;
void createSchedule(int today,int schedule, int currPresent , int currClasses, vector<int> & classOnDay,vector<bool> presentOrNot){
    for(int i = 0; i< schedule; i++){
        if(presentOrNot[i]){
            currPresent += classOnDay[(today-1+i)%5];
        }
        currClasses += classOnDay[(today-1+i)%5];
    }
    cout<<"Final Attendance "<<endl;
    cout<<currPresent<<'/'<<currClasses<<endl;
    cout<<"Percentage "<<currPresent*100/(float)currClasses<<endl;
}
int main()
{
    int today;
    cout<<"Enter start day (monday - 1 .. friday - 5) : ";
    cin>>today;
    int currPresent;
    int currClasses;
    cout<<"Enter your Total Present <space> Total Classes: ";
    cin>>currPresent>>currClasses;
    vector<int> classOnDay = {8,6,8,5,5};
    int schedule;
    cout<<"Enter the no of Days to find attendance (excluding saturdays and sundays):";
    cin>>schedule;
    vector<bool> presentOrNot(schedule);
    cout<<"Mark 1 for Present 0 for Absent for "<<schedule<<" days "<<endl;
    for(int i = 0; i < schedule; i++){
        bool temp;
        cin>>temp;
        presentOrNot[i] = temp;
    }
    createSchedule(today,schedule,currPresent,currClasses,classOnDay,presentOrNot);
    return 0;
}