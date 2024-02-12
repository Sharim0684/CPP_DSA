#include <iostream>
#include <vector>
using namespace std;

class Bully {
public:
    static vector<bool> state;
    int coordinator;

    Bully() {
        coordinator = 0;
    }

    static void up(int processNumber) {
        if (state[processNumber - 1]) {
            cout << "Process " << processNumber << " is already up" << endl;
        } else {
            state[processNumber - 1] = true;
            cout << "Process " << processNumber << " held election" << endl;
            for (int i = processNumber; i < 5; i++) {
                cout << "Election message sent from process " << processNumber << " to process " << (i + 1) << endl;
            }
            for (int i = processNumber + 1; i <= 5; i++) {
                if (!state[i - 1]) {
                    continue;
                }
                cout << "Alive message sent from process " << i << " to process " << processNumber << endl;
                break;
            }
        }
    }

    static void down(int processNumber) {
        if (!state[processNumber - 1]) {
            cout << "Process " << processNumber << " is already down" << endl;
        } else {
            state[processNumber - 1] = false;
        }
    }

    static void message(int processNumber) {
        if (state[processNumber - 1]) {
            if (state[4]) {
                cout << "OK" << endl;
            } else {
                cout << "Process " << processNumber << " election" << endl;
                for (int i = processNumber; i < 5; i++) {
                    cout << "Election message sent from process " << processNumber << " to process " << (i + 1) << endl;
                }
                for (int i = 5; i >= processNumber; i--) {
                    if (!state[i - 1]) {
                        continue;
                    }
                    cout << "Coordinator message sent from process " << i << " to all" << endl;
                    break;
                }
            }
        } else {
            cout << "Process " << processNumber << " is down" << endl;
        }
    }
};

vector<bool> Bully::state(5, true);

int main() {
    int choice;
    for (int i = 0; i < 5; ++i) {
        Bully::state[i] = true;
    }
    cout << "5 active processes are: p1 p2 p3 p4 p5" << endl;
    cout << "Process 5 is coordinator" << endl;
    do {
        cout << "........." << endl;
        cout << "1) Up a process." << endl;
        cout << "2) Down a process" << endl;
        cout << "3) Send a message" << endl;
        cout << "4) Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Bring process up" << endl;
                int up;
                cin >> up;
                if (up == 5) {
                    cout << "Process 5 is co-ordinator" << endl;
                    Bully::state[4] = true;
                    break;
                }
                Bully::up(up);
                break;
            }
            case 2: {
                cout << "Bring down any process." << endl;
                int down;
                cin >> down;
                Bully::down(down);
                break;
            }
            case 3: {
                cout << "Which process will send message" << endl;
                int mess;
                cin >> mess;
                Bully::message(mess);
            }
        }
    } while (choice != 4);
    return 0;
}