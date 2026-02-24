//fcfs
#include <stdio.h>
int main() {
    int n, i;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    return 0;
}
/*Enter number of processes: 4
Enter Burst Times:
P1: 5
P2: 3
P3: 8
P4: 6
Process   BT   WT   TAT
P2        3    0    3
P1        5    3    8
P4        6    8    14
P3        8    14   22

Average Waiting Time = 6.25
Average Turnaround Time = 11.75
*/
//sjf
#include <stdio.h>
int main() {
    int n, i, j;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst Times:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }
    // Sort burst times
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    return 0;
}

//Priority Scheduling (Non-Preemptive)
#include <stdio.h>
int main() {
    int n, i, j;
    int bt[20], pr[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i+1);
        scanf("%d", &pr[i]);
    }
    // Sort by priority
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    return 0;
}

//rr
#include <stdio.h>
int main() {
    int n, i, time = 0, remain, tq;
    int bt[20], temp[20];
    float wt = 0, tat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    for(i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    for(time = 0, i = 0; remain != 0;) {
        if(temp[i] <= tq && temp[i] > 0) {
            time += temp[i];
            temp[i] = 0;
            remain--;
            printf("P%d finished at time %d\n", i+1, time);
        }
        else if(temp[i] > 0) {
            temp[i] -= tq;
            time += tq;
        }
        if(i == n-1)
            i = 0;
        else
            i++;
    }
    printf("\nTotal Time: %d\n", time);
    return 0;
}
