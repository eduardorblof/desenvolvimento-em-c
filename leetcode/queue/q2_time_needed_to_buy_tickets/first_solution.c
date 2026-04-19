#include <string.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    int size = ticketsSize;

    while (tickets[k] > 0) {
        if (tickets[0] > 0) {
            tickets[0]--;
            time++;

            if (k == 0 && tickets[0] == 0)
                return time;
        }

       
        int temp = tickets[0];
        memmove(tickets, tickets + 1, (size - 1) * sizeof(int));
        tickets[size - 1] = temp;

       
        if (k == 0)
            k = size - 1;
        else
            k--;
    }

    return time;
}