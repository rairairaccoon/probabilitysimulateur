#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int totalsuccess = 0;
int totalfail = 0;

void delay(int numbofsecs) {
    int milli = 1000 * numbofsecs;
    clock_t start_time = clock();
    while (clock() < start_time + milli) {
        ;
    }
}

void simulate(int percentage, int iterations) {
    int i = 0;
    int result;
    while (i < iterations) {
        result = rand() % 101;
        if (result <= percentage) {
            printf("\nfinished iteration ");
            printf("%d", i);
            printf(" of ");
            printf("%d", iterations);
            totalsuccess = totalsuccess + 1;
        }
        else if (result > percentage) {
            printf("\nfinished iteration ");
            printf("%d", i);
            printf(" of ");
            printf("%d", iterations);
            totalfail = totalfail + 1;
        }
        i = i + 1;
    }
    printf("\n\nsimulation finished with ");
    printf("%d", totalsuccess);
    printf(" successes and ");
    printf("%d", totalfail);
    printf(" failures \n");
}

int main(void) {
    int running = 1;
    while (running == 1) {
        int iterations = 0;
        float percentage = 0;
        printf("what is the likelyhood something would happen in percentage?: ");
        scanf("%f", &percentage);
        printf("how many times would you like to simulate this?: ");
        scanf("%d", &iterations);
        printf("starting simulation...");
        simulate(percentage, iterations);
        printf("\npress 1 to run another simulation, press 0 to quit: ");
        scanf("%d", &running);
    }
    return 0;
}