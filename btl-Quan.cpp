#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;

#define MAX_EMPLOYEES 1000

struct Employee {
    int id;
    string name,position,birth_place;
    double salary,benefits;
    int workDays;
    double performanceRating;// rate=so ngay cham cong/ so ngay cua thang dang xet 
};

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;
int nextId = 1;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        cout << "Maximum number of employees reached. Cannot add more employees.\n";
        return;
    }
    Employee& emp = employees[employeeCount++];
    emp.id = nextId++;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter position: ";
    getline(cin, emp.position);
    cout << "Enter salary: ";
    cin >> emp.salary;
    cout << "Enter benefits: ";
    cin >> emp.benefits;
    emp.workDays = 0;
    emp.performanceRating = 0;
    cout << "Employee added successfully!\n";
}

void displayEmployees() {
    if (employeeCount == 0) {
        cout << "No employees found.\n";
        return;
    }
    for (int i = 0; i < employeeCount; i++) {
        Employee& emp = employees[i];
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Position: " << emp.position
             << ", Salary: " << emp.salary << ", Benefits: " << emp.benefits
             << ", Work Days: " << emp.workDays << ", Performance Rating: " << emp.performanceRating << "\n";
    }
}

void updateAttendance(int id, int days) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            employees[i].workDays += days;
            cout << "Attendance updated for Employee ID " << id << "\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void evaluatePerformance(int id, double rating) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            employees[i].performanceRating = rating;
            cout << "Performance updated for Employee ID " << id << "\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void calculatePay(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            double totalPay = employees[i].salary + employees[i].benefits;
            cout << "Total pay for Employee ID " << id << " is: " << totalPay << "\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}


void today_date(){
    // Tạo biến để lưu trữ thời gian hiện tại
    time_t t;
    struct tm *current_time;

    // Lấy thời gian hiện tại
    time(&t);
    current_time = localtime(&t);

    // In ra ngày tháng năm hiện tại
    cout<<"Today is: "<<
    current_time->tm_mday<<"/"<<
    current_time->tm_mon + 1<<"/"<<current_time->tm_year + 1900<<endl;  
    // tm_mon bắt đầu từ 0 nên cần cộng 1
    // tm_year là số năm kể từ 1900
 }
int main() {
    cout<<"Hello Boss !"<<endl;
    today_date();
    int choice;
    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Update Attendance\n";
        cout << "4. Evaluate Performance\n";
        cout << "5. Calculate Pay\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3: {
                int id, days;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter number of work days to update: ";
                cin >> days;
                updateAttendance(id, days);
                break;
            }
            case 4: {
                int id;
                double rating;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter performance rating (0 to 5): ";
                cin >> rating;
                evaluatePerformance(id, rating);
                break;
            }
            case 5: {
                int id;
                cout << "Enter employee ID: ";
                cin >> id;
                calculatePay(id);
                break;
            }
            case 6:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
