#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SUBJECTS = 5;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[n][SUBJECTS];
    int rollNumber[n];
    int total[n];
    float average[n];
    string grade[n];

    // Input
    for (int i = 0; i < n; i++) {
        rollNumber[i] = i + 1;
        cout << "\nEnter marks for Student " << rollNumber[i] << " (5 subjects):\n";
        for (int j = 0; j < SUBJECTS; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    // Compute total and average
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            sum += marks[i][j];
        }
        total[i] = sum;
        average[i] = sum / (float)SUBJECTS;
    }

    // Assign grade
    for (int i = 0; i < n; i++) {
        if (average[i] >= 90) grade[i] = "A+";
        else if (average[i] >= 80) grade[i] = "A";
        else if (average[i] >= 70) grade[i] = "B";
        else if (average[i] >= 60) grade[i] = "C";
        else if (average[i] >= 50) grade[i] = "D";
        else grade[i] = "F";
    }

    // Display individual report cards
    cout << "\n--- Individual Report Cards ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nRoll No: " << rollNumber[i] << endl;
        for (int j = 0; j < SUBJECTS; j++)
            cout << "  Subject " << j + 1 << ": " << marks[i][j] << endl;
        cout << "  Total: " << total[i]
             << " | Average: " << fixed << setprecision(2) << average[i]
             << " | Grade: " << grade[i] << endl;
    }

    // Sort by total marks (descending) - Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (total[j] < total[j + 1]) {
                swap(total[j], total[j + 1]);
                swap(rollNumber[j], rollNumber[j + 1]);
                swap(average[j], average[j + 1]);
                swap(grade[j], grade[j + 1]);
            }
        }
    }

    // Display merit list
    cout << "\n--- Merit List (Ranked by Total Marks) ---\n";
    cout << left << setw(6) << "Rank" << setw(10) << "Roll No"
         << setw(10) << "Total" << setw(10) << "Average" << setw(6) << "Grade" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << i + 1
             << setw(10) << rollNumber[i]
             << setw(10) << total[i]
             << setw(10) << fixed << setprecision(2) << average[i]
             << setw(6) << grade[i] << endl;
    }

    return 0;
}