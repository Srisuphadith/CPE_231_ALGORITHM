#include <iostream>
#include <vector>
using namespace std;

// Function to find the stable matching
void stable_interview(int** company, int** student, int n) {
    vector<int> studentPartner(n, -1); // Stores the company each student is assigned to
    vector<bool> companyFree(n, true); // Tracks whether a company is free
    vector<int> companyNext(n, 0);     // Tracks the next student each company will propose to
    int freeCount = n;                 // Count of free companies

    while (freeCount > 0) {
        int freeCompany = -1;

        // Find the first free company
        for (int i = 0; i < n; i++) {
            if (companyFree[i]) {
                freeCompany = i;
                break;
            }
        }

        if (freeCompany == -1) break; // All companies matched

        int studentID = company[freeCompany][companyNext[freeCompany]++];
        // If student is not assigned, assign to the company
        if (studentPartner[studentID] == -1) {
            studentPartner[studentID] = freeCompany;
            companyFree[freeCompany] = false;
            freeCount--;
        } else {
            // Check if the student prefers the new company over the current one
            int currentCompany = studentPartner[studentID];
            int currentRank = -1, newRank = -1;

            for (int i = 0; i < n; i++) {
                if (student[studentID][i] == currentCompany) currentRank = i;
                if (student[studentID][i] == freeCompany) newRank = i;
            }

            if (newRank < currentRank) {
                // Replace the current company with the new one
                studentPartner[studentID] = freeCompany;
                companyFree[freeCompany] = false;
                companyFree[currentCompany] = true;
            }
        }
    }

    // Output the pairs
    for (int i = 0; i < n; i++) {
        cout << i << " " << studentPartner[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int** company = new int*[n];
    int** student = new int*[n];

    for (int i = 0; i < n; i++) {
        company[i] = new int[n];
        student[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> company[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> student[i][j];
        }
    }

    stable_interview(company, student, n);

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] company[i];
        delete[] student[i];
    }
    delete[] company;
    delete[] student;

    return 0;
}
