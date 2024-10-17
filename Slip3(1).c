/* 
Slip No 3
Q1)
Write the simulation program to implement demand paging and show the page
scheduling and total number of page faults according to the LRU (using
counter method) page replacement algorithm. Assume the memory of n
frames.
Reference String : 3,5,7,2,5,1,2,3,1,3,5,3,1,6,2 
*/

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define MAX_FRAMES 10
#define MAX_REFERENCES 15

// Function to find the index of the least recently used page
int findLRU(int frame[], int time[], int n) {
    int minimum = time[0], index = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            index = i;
        }
    }
    return index;
}

// Function to implement LRU page replacement algorithm
void simulateLRU(int referenceString[], int n, int frames) {
    int frame[MAX_FRAMES], time[MAX_FRAMES];
    int pageFaults = 0;

    // Initialize frames and time
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int found = 0;

        // Check if page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                time[j] = i; // Update the time of this page
                break;
            }
        }

        // If page not found, we have a page fault
        if (!found) {
            int lruIndex = findLRU(frame, time, frames);
            frame[lruIndex] = page; // Replace the LRU page
            time[lruIndex] = i; // Update the time of the new page
            pageFaults++;
        }

        // Print the current state of frames
        printf("Reference: %d | Frames: ", page);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf("%d ", frame[j]);
            }
        }
        printf("\n");
    }

    printf("Total number of page faults: %d\n", pageFaults);
}

int main() {
    int referenceString[MAX_REFERENCES] = {3, 5, 7, 2, 5, 1, 2, 3, 1, 3, 5, 3, 1, 6, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int frames;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    if (frames > MAX_FRAMES) {
        printf("Maximum number of frames is %d\n", MAX_FRAMES);
        return 1;
    }

    simulateLRU(referenceString, n, frames);

    getch();
}