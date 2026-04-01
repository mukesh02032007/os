#include <stdio.h>
#include <conio.h>

int main() {
    int i, j, k;
    int n, m;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10], safeSeq[10];
    int count, found, flag;

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Need calculation
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    count = 0;

    while(count < n) {
        found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {

                flag = 0;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state!");
            getch();
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe sequence:\n");
    for(i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }

    getch();
    return 0;
}

OUTPUT:
Enter number of processes: 3
Enter number of resources: 3

Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2

Enter Max Matrix:
7 5 3
3 2 2
9 0 2

Enter Available Resources:
3 3 2

System is in SAFE state.
Safe sequence:
P1 P0 P2
