int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;
    int i = 0;

    while (tickets[k] > 0) {
        if (tickets[i] > 0) {
            tickets[i]--;
            time++;

            if (i == k && tickets[k] == 0)
                return time;
        }

        i = (i + 1) % ticketsSize;
    }

    return time;
}