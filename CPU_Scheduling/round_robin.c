#include <stdio.h>

int i, n, quantum; 

void read(int b[]) {
    for (i = 0; i < n; ++i) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &b[i]);
    }
}

void findWaitingtime(int b[], int wt[]) {
    int b_rem[20];
    for (i = 0; i < n; ++i) {
        b_rem[i] = b[i];                        
    }
    int time = 0;                               

    while (1)
    {
        

        int flag = 0;

        for (i = 0; i < n; ++i) {

            if (b_rem[i] > 0) {                 
                flag = 1;                       
                if (b_rem[i] > quantum) {
                    time += quantum;            
                    b_rem[i] -= quantum;        
                }
                else {                          
                    time += b_rem[i];           
                    wt[i] = time - b[i];        
                    b_rem[i] = 0;               
                }
            }
        }
        if (flag == 0) {                        
            break;
        }
    }
}

void findTurnAroundtime(int tat[], int b[], int wt[]) {
    for (i = 0; i < n; ++i) {
        tat[i] = b[i] + wt[i];
    }
}

void display(int b[], int wt[], int tat[]) {
    int wtSum = 0, tatSum = 0;
    printf("Process\tBurstTime WaitingTime  TurnAroundTime\n");
    for (i = 0; i < n; ++i) {
        wtSum += wt[i];
        tatSum += tat[i];
        printf("%d\t%d\t\t%d\t%d\n", i, b[i], wt[i], tat[i]);
    }
    printf("average waiting time: %f", (float)wtSum / n);
    printf("\naverage turnaround time: %f", (float)tatSum / n);
    printf("\n");
}

void calcTime(int b[], int wt[], int tat[]) {
    findWaitingtime(b, wt);
    findTurnAroundtime(tat, b, wt);
    display(b, wt, tat);
}

void main()
{
    int b[20], tat[20], wt[20];
    printf("Number of Processes:");
    scanf("%d", &n);
    read(b);
    printf("Enter time quantum:");
    scanf("%d", &quantum);
    calcTime(b, wt, tat);
}

