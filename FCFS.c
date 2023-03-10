#include<stdio.h>
int main()
{
	int  p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n;
    float avwt=0,avtat=0, sum_tat=0, sum_wt=0;
    printf("\t-------First Come First Serve--------\n");
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter arrival time and burst time for each process.....\n\n");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("Arrival time of process [%d]: ",i+1);
		scanf("%d",&at[i]);		
		printf("Burst time of process [%d]:  ",i+1);
		scanf("%d",&bt[i]);		
		printf("\n");
	}
	for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-i-1);j++)
        {
            if(at[j]>at[j+1])
            {
                temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;                
                temp=at[j+1];
                at[j+1]=at[j];
                at[j]=temp;              
                temp=bt[j+1];
                bt[j+1]=bt[j];
                bt[j]=temp;
            }
        }
    }   
    ct[0]=at[0]+bt[0];   
    for(i=1;i<n;i++)
    {    
        temp=0;
        if(ct[i-1]<at[i])
        {
            temp=at[i]-ct[i-1];
        }
        ct[i]=ct[i-1]+bt[i]+temp;
    }
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        sum_tat=sum_tat+tat[i];
        sum_wt=sum_wt+wt[i];
    }
    avtat=sum_tat/n;
    avwt=sum_wt/n;   
	for(i=0;i<n;i++)
    {
    	printf("\nP%d\t %d\t %d\t %d \t %d \t %d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage turnaround time is %f",avtat);
    printf("\nAverage waiting time is %f",avwt);
    return 0;
}

