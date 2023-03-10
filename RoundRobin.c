#include<stdio.h>

int main()
{
    int i,j,n,max, quantam_time;
    int wt[10], tat[10], bt[10], ct[10];
    float avg_wt=0, avg_tat=0, temp=0;
    printf(" -------Round Robin Scheduling-------\n");
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    printf("\nEnter details of each process.....\n\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter Burst Time for processes number %d: ",i+1);
        scanf("%d", &bt[i]);
        ct[i]=bt[i];
    }
    printf("Enter the size of time slice: ");
    scanf("%d",&quantam_time);

    max=bt[0];
    for(i=1;i<n;i++)
    {
        if(max<bt[i])
        max=bt[i];
        for(j=0;j<(max/quantam_time)+1;j++)
        {
            for(i=0;i<n;i++)
             {
                 if (bt[i]!=0)
                if (bt[i]<=quantam_time)
                {
                    tat[i]=temp+bt[i];
                    temp=temp+bt[i];
                    bt[i]=0;
                }
                else{
                    bt[i]=bt[i]-quantam_time;
                    temp=temp+quantam_time;
                }
             }              
        }     
    }
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-ct[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }  
    printf("\n\nProcess|\tBrust Time|\tTrunaround Time|\tWaiting Time\n\n");

    for(i=0;i<n;i++)
    {
       printf("P[%d]|\t\t %d\t|\t\t%d\t|\t\t%d\n", i+1,ct[i],tat[i],wt[i]);   
    }
    printf("\nAverage Turnaround Time: %f",avg_tat/n);
    printf("\nAverage Waiting Time: %f",avg_wt/n);

}