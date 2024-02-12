#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#define MAX_USERS 100
#define MAX_LOGS 1000
#define MAX_INCIDENTS 100

string usernames[MAX_USERS];
string passwords[MAX_USERS];
int roles[MAX_USERS];

string logs[MAX_LOGS]; // Assuming the username is at most 50 characters
string actions[MAX_LOGS];
string timestamps[MAX_LOGS];

string incidents[MAX_INCIDENTS];
string reportedBy[MAX_INCIDENTS];
string incidentTimestamps[MAX_INCIDENTS];

int userCount = 0;
int logCount = 0;
int incidentCount = 0;

void addUser() {
    string username;
    string password;
    int role;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter role (0 for admin, 1 for user): ";
    cin >> role;

    usernames[userCount] = username;
    passwords[userCount] = password;
    roles[userCount] = role;
    userCount++;
}

void logAction() {
    string username;
    string action;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter action: ";
    cin >> action;

    logs[logCount] = username;
    actions[logCount] = action;

    // Getting current time
    time_t currentTime = time(nullptr);
    timestamps[logCount] = ctime(&currentTime);

    logCount++;
}

void reportIncident() {
    string report;
    string reportedByUser;

    cout << "Enter report: ";
    cin >> report;
    cout << "Enter reported by: ";
    cin >> reportedByUser;

    incidents[incidentCount] = report;
    reportedBy[incidentCount] = reportedByUser;

    // Getting current time
    time_t currentTime = time(nullptr);
    incidentTimestamps[incidentCount] = ctime(&currentTime);

    incidentCount++;
}

void viewLogs() {
    for (int i = 0; i < logCount; i++) {
        cout << timestamps[i] << " - " << logs[i] << ": " << actions[i] << endl;
    }
}

void viewIncidents() {
    for (int i = 0; i < incidentCount; i++) {
        cout << incidentTimestamps[i] << " - " << reportedBy[i] << " reported: " << incidents[i] << endl;
    }
}

int main() {
    int choice;
     cout << " __          __  _                            " << endl;
        cout << " \\ \\        / / | |                           " << endl;
        cout << "  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___   " << endl;
        cout << "   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\  " << endl;
        cout << "    \\  /\\  /  __/ | (_| (_) | | | | | |  __/  " << endl;
        cout<< "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  " << endl;
         system("color 0A");
        
    do {
        cout << "\nSecurity Management System\n";
        cout << "1. Add User\n";
        cout << "2. Log Action\n";
        cout << "3. Report Incident\n";
        cout << "4. View Logs\n";
        cout << "5. View Incidents\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                logAction();
                break;
            case 3:
                reportIncident();
                break;
            case 4:
                viewLogs();
                break;
            case 5:
                viewIncidents();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
