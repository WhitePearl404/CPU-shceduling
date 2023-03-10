#include<stdio.h>
int main()
{
    int i,j,temp, n, p[20], at[20], bt[20], ct[20], tat[20], wt[20];
	float sum_tat=0,sum_wt=0,avg_tat,avg_wt,ps;
    printf(" -------Shortest Job First Scheduling-------\n");
    printf("Enter the number of processes : ");
	scanf("%d", &n);
    printf("\nEnter details of each process.....\n\n");

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
        for(j=1;j<n-i-1;j++)
        {
           if (bt[j] > bt[j+1])
            {
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                
            } 
        }
    }    
     printf(" RESULT:-");
    printf("\nProcess\t AT\t BT\t CT\t TAT\t WT\t\n");
     if(at[0]>0)
	{
	    ps=at[0];
	}
	for(i=0; i<n; i++)
	{
        ps+=bt[i];
        
        ct[i]=ps;
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
      
        sum_tat=sum_tat+tat[i];
        sum_wt=sum_wt+wt[i];
    }
    avg_tat=sum_tat/n;
    avg_wt=sum_wt/n;
   
    for(i=0;i<n;i++)
    {
     printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }   
    printf("\n AVERAGE TURN AROUND TIME : %f",avg_tat);
    printf("\n\n AVERAGE WAITING TIME : %f",avg_wt);
    return 0;
}