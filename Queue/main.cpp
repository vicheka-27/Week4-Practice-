#include "queue.hpp"
#include <iostream>
using namespace std;

int main() {
    Queue helpdesk;
    initQueue(helpdesk);

    int n;
    cout << "Enter number of tickets: ";
    cin >> n;
    cin.ignore();

    for(int i = 1; i <= n; i++){
        string ticket;
        cout << "Enter ticket " << i << ": ";
        getline(cin, ticket);
        enqueue(helpdesk, ticket);
    }

    cout << "\nAll tickets added.\n";
    display(helpdesk);

    cout << "\nProcessing tickets...\n\n";
    while(!isEmpty(helpdesk)) {
        dequeue(helpdesk);
    }

    cout << "\nAll tickets processed. Queue is now empty.\n";
    freeQueue(helpdesk);

    return 0;
}
