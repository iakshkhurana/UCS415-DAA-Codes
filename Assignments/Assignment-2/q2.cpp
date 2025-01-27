#include<iostream>
using namespace std;

// step-1 : sort the data in descending order by submission date
// step-2 : largest deadline = number of spots possible

class job{
    public:
    int id;
    int deadline;
    int profit;
    job(){}
    job(int id,int deadline, int profit){
        this->id=id;
        this->deadline=deadline;
        this->profit=profit;
    }
};

int main(){
    int n=5;
    job jb[n];
    jb[0]=job(1, 2, 60);
    jb[1]=job(2, 1, 100);
    jb[2]=job(3, 3, 20);
    jb[3]=job(4, 2, 40);
    jb[4]=job(5, 1, 20);
    int gnattSize=0;
    for(int i=0; i<n; i++)
        if(gnattSize<jb[i].deadline)
            gnattSize=jb[i].deadline;
    int gantt[gnattSize]={};

    //Sort according to profit
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(jb[i].profit<jb[j].profit)
                swap(jb[i], jb[j]);
        }
    }

    //Schedule jobs
    for(int i=0; i<n; i++)
    {
        int jobTime=jb[i].deadline-1;
        if(gantt[jobTime]==0)
            gantt[jobTime]=jb[i].id;
        else
        {
            for(int j=jobTime-1; j>=0; j--)
                if(gantt[j]==0)
                    gantt[j]=jb[i].id;
        }
    }

    //Print gantt chart
    for(int i=0; i<gnattSize; i++)
        cout<<gantt[i]<<" ";
    cout<<endl;


}