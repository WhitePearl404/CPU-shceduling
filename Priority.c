#include<stdio.h> 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pri[20],i,j,n,pos,temp;
    float avg_wt, avg_tat,total=0;
    printf(" -------Priority Scheduling-------\n");
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("\nEnter details of each process.....\n\n");
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("Priority time of process [%d]: ",i+1);
		scanf("%d",&pri[i]);		
		printf("Burst time of process [%d]:  ",i+1);
		scanf("%d",&bt[i]);		
		printf("\n");
    }   
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[j]<pri[pos])
                pos=j;
        }
        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;       
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    } 
    avg_wt=total/n;      
    total=0;
        
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
    }
    avg_tat=total/n;     
    printf("\nProcess\t\tPriority\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        printf("\np[%d] \t\t %d \t\t %d \t\t %d \t\t %d",p[i],pri[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    printf("\n\nAverage Waiting Time=%f",avg_wt);
 
    return 0;
}
