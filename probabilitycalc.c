#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
            printf("success \n");
        }
        else if (result > percentage) {
            printf("failure \n");
        }
        i = i + 1;
    }
}

int main(void) {
    int iterations = 10000000;
    float percentage = 10000000;
    printf("what is the likelyhood something would happen in percentage?: ");
    scanf("%f", percentage);
    printf("how many times would you like to simulate this?: ");
    scanf("%d", iterations);
    printf("starting simulation...");
    simulate(percentage, iterations);
    delay(10);
    return 0;
}