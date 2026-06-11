#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Constants for Rubric Compliance (10+ records using arrays)[cite: 1]
const int MAX = 20;

// Data Storage Arrays (Parallel Arrays)[cite: 1]
string names[MAX];
string serviceType[MAX]; // "Security", "Game", "IQ"
int finalScores[MAX];
string status[MAX];      // "Granted/Denied", "Completed", or IQ Label
float revenue[MAX];

int totalRecords = 0;

// Function Prototypes for Modularity[cite: 1]
void mainMenu();
void securityModule();
void gameModule(); // Integrated Simulation Version
void iqModule();
void adminPanel();
void searchRecord();
void deleteRecord();
void generateBusinessReport();

int main() {
    int choice;
    do {
        mainMenu();
        cin >> choice;
        
        // Input Validation[cite: 1]
        if(cin.fail() || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << ">> Error: Invalid Option. Access Denied." << endl;
            continue;
        }

        switch(choice) {
            case 1: securityModule(); break;
            case 2: gameModule(); break;
            case 3: iqModule(); break;
            case 4: adminPanel(); break;
            case 5: cout << "System Shutting Down..." << endl; break;
        }
    } while (choice != 5);
    return 0;
}

void mainMenu() {
    cout << "\n==========================================" << endl;
    cout << "          CIPHER NEXUS TERMINAL           " << endl;
    cout << "==========================================" << endl;
    cout << "1. [Module 1] Security Services" << endl;
    cout << "2. [Module 2] Escape Room Simulation" << endl;
    cout << "3. [Module 3] IQ Testing Services" << endl;
    cout << "4. [Admin] Shared Management Panel" << endl;
    cout << "5. Exit System" << endl;
    cout << "Select Operation: ";
}

// - MODULE 1: SECURITY SERVICES -
void securityModule() {
    if(totalRecords >= MAX) return;
    
    cout << "\n[SEC] Client Registration for Vault Access" << endl;
    cout << "Enter Name: "; cin >> names[totalRecords];
    serviceType[totalRecords] = "Security";
    revenue[totalRecords] = 500.0; // Flat security fee[cite: 1]
    
    int challenge;
    cout << "SECURITY CHALLENGE: Solve 49 / 7 + 3: ";
    cin >> challenge;
    
    if(challenge == 10) {
        status[totalRecords] = "ACCESS_GRANTED";
        cout << ">> CODE GENERATED: NX-8821" << endl;
    } else {
        status[totalRecords] = "BREACH_ATTEMPT";
        cout << ">> LOCKOUT TRIGGERED. LOGGED." << endl;
    }
    finalScores[totalRecords] = (challenge == 10) ? 100 : 0;
    totalRecords++;
}

// - MODULE 2: GAME SIMULATION (ESCAPE ROOM) - REWRITTEN SIMULATION -
void gameModule() {
    if(totalRecords >= MAX) return;

    string teamLead;
    int hintsUsed = 0;
    int puzzleAns;

    cout << "\n [SIM] CIPHER NEXUS ESCAPE ROOM " << endl;
    cout << "Enter Team Leader Name: "; cin >> teamLead;
    names[totalRecords] = teamLead;
    serviceType[totalRecords] = "Game";

    cout << "\nSYSTEM INITIALIZED: You are locked in the 'Digital Vault'." << endl;
    cout << "You must solve 3 levels to find the exit code." << endl;

    // LEVEL A: VISUAL LOGIC
    cout << "\n[LEVEL A: VISUAL LOGIC]" << endl;
    cout << "A sequence appears on the screen: 3, 9, 27, 81, ..." << endl;
    cout << "Enter the next number to unlock the first bolt: ";
    cin >> puzzleAns;
    if (puzzleAns != 243) {
        cout << "WRONG. Using automated hint... (+1 hint penalty)" << endl;
        hintsUsed++;
    } else {
        cout << "BOLT 1: DISENGAGED." << endl;
    }

    // LEVEL B: CRYPTIC MATH
    cout << "\n[LEVEL B: CRYPTIC MATH]" << endl;
    cout << "Solve for X: (X * 5) - 10 = 40" << endl;
    cout << "Enter X: ";
    cin >> puzzleAns;
    if (puzzleAns != 10) {
        cout << "WRONG. Using automated hint... (+1 hint penalty)" << endl;
        hintsUsed++;
    } else {
        cout << "BOLT 2: DISENGAGED." << endl;
    }

    // LEVEL C: THE FINAL CIPHER
    cout << "\n[LEVEL C: CREATIVE THINKING]" << endl;
    cout << "I speak without a mouth and hear without ears. I have no body, but I come alive with wind." << endl;
    cout << "1. Shadow | 2. Echo | 3. Whisper | 4. Cloud" << endl;
    cout << "Select the correct number: ";
    cin >> puzzleAns;
    if (puzzleAns != 2) {
        cout << "WRONG. Security lockout avoided by emergency hint (+1 hint penalty)." << endl;
        hintsUsed++;
    } else {
        cout << "BOLT 3: DISENGAGED." << endl;
    }

    // Business Logic: Fee + Penalties[cite: 1]
    float baseFee = 1500.0;
    revenue[totalRecords] = baseFee - (hintsUsed * 100.0); 
    
    int score = 100 - (hintsUsed * 20);
    finalScores[totalRecords] = score;
    
    if (score >= 60) {
        status[totalRecords] = "ESCAPED";
        cout << "\nCONGRATULATIONS " << teamLead << "! The door is open." << endl;
        cout << "FINAL UNLOCK CODE: NEXUS-" << (score * 12) << endl;
    } else {
        status[totalRecords] = "TRAPPED";
        cout << "\nTIME EXPIRED. You are trapped in the vault." << endl;
    }

    totalRecords++;
}

// MODULE 3: IQ TESTING SERVICES 
void iqModule() {
    if(totalRecords >= MAX) return;
    
    cout << "\n[IQ] Clinical Subject Registration" << endl;
    cout << "Subject Name: "; cin >> names[totalRecords];
    serviceType[totalRecords] = "IQ";
    revenue[totalRecords] = 300.0; // Test fee[cite: 1]

    int a, b, c;
    cout << "Level A (Visual): "; cin >> a;
    cout << "Level B (Math): "; cin >> b;
    cout << "Level C (Logic): "; cin >> c;

    // Proper Formula Logic[cite: 1]
    int iqEstimate = 70 + (a + b + c) / 3;
    finalScores[totalRecords] = iqEstimate;

    if(iqEstimate >= 130) status[totalRecords] = "Genius";
    else if(iqEstimate >= 110) status[totalRecords] = "Above Average";
    else if(iqEstimate >= 90) status[totalRecords] = "Average";
    else status[totalRecords] = "Below Average";

    cout << "Final Report: Subject is classified as " << status[totalRecords] << endl;
    totalRecords++;
}

//  SHARED ADMIN PANEL 
void adminPanel() {
    int adminChoice;
    cout << "\n SHARED ADMIN PANEL " << endl;
    cout << "1. View All Records" << endl;
    cout << "2. Search Subject" << endl;
    cout << "3. Delete Record" << endl;
    cout << "4. Business Revenue Report" << endl;
    cout << "Return to main menu (0): ";
    cin >> adminChoice;

    if(adminChoice == 1) {
        cout << left << setw(15) << "NAME" << setw(12) << "SERVICE" << setw(10) << "SCORE" << "STATUS" << endl;
        for(int i=0; i<totalRecords; i++) {
            cout << left << setw(15) << names[i] << setw(12) << serviceType[i] << setw(10) << finalScores[i] << status[i] << endl;
        }
    } else if(adminChoice == 4) {
        generateBusinessReport();
    }
}

void generateBusinessReport() {
    float totalRevenue = 0;
    int secCount = 0, gameCount = 0, iqCount = 0;

    for(int i=0; i<totalRecords; i++) {
        totalRevenue += revenue[i];
        if(serviceType[i] == "Security") secCount++;
        else if(serviceType[i] == "Game") gameCount++;
        else if(serviceType[i] == "IQ") iqCount++;
    }

    cout << "\n FINANCIAL PERFORMANCE " << endl;
    cout << "Total Nexus Revenue: $" << totalRevenue << endl;
    cout << "Service Distribution: SEC[" << secCount << "] GAME[" << gameCount << "] IQ[" << iqCount << "]" << endl;
}
