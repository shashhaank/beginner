#include<iostream>
using namespace std;

void findwt(int processes[],int n, int bt[], int wt[])
{
    wt[0] = 0;

    for(int i=1;i<n;i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
    }

}

void findtat(int processes[],int n, int bt[],int wt[],int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }

}

void findavgt(int processes[],int n, int bt[])
{
    int wt[n],tat[n],totalwt=0,totaltat=0;
    findwt(processes,n,bt,wt);
    findtat(processes,n,bt,wt,tat);

    cout<<"Processes "<<" Burst Time "<<" Waiting Time "<<" Turn Around Time \n";

    for(int i=0;i<n;i++)
    {
        totalwt = totalwt + wt[i];
        totaltat = totaltat + tat[i];

        cout<<"  "<<i+1<<" \t\t"<<bt[i]<<" \t   "<<wt[i]<<" \t\t    "<<tat[i]<<endl;
    }
    
    cout<<" Average Waiting Time = "<<(float)totalwt/(float)n<<endl;
    cout<<" Average Turn Around Time = "<<(float)totaltat/(float)n<<endl;
    
}

int main()
{
    int processes[] = {1,2,3};
    int n =  sizeof processes / sizeof processes[0];

    int bt[] = {10,5,8};

    findavgt(processes,n,bt);

    return 0;

}
