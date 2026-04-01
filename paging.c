#include <stdio.h>
#include <conio.h>

int main() {
    int pageTable[10];
    int n, i;
    int pageNumber, offset;
    int physicalAddress;

    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input page table
    printf("Enter page table (frame numbers):\n");
    for(i = 0; i < n; i++) {
        printf("Page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    // Input logical address
    printf("\nEnter page number: ");
    scanf("%d", &pageNumber);

    printf("Enter offset: ");
    scanf("%d", &offset);

    // Check valid page
    if(pageNumber >= n) {
        printf("\nInvalid Page Number!");
    } else {
        physicalAddress = pageTable[pageNumber] * 100 + offset;
        printf("\nPhysical Address = %d", physicalAddress);
    }

    getch();
    return 0;
}