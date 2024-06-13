//AYUSH JHA--->230258
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Define the Student class as per the given question
class Student {
private:
    string name;
    int rollNumber;
    string course;
    float totalMarks;

public:
    // Constructo(jaise apan ne oops mein seeekha)
    Student(string name, int rollNumber, string course, float totalMarks)
        : name(name), rollNumber(rollNumber), course(course), totalMarks(totalMarks) {}

    
    int getRollNumber() const {
        return rollNumber;      // getter setter wala concept
    }

    
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

struct RemoveByRollNumber {
    int rollNumber;
    RemoveByRollNumber(int roll) : rollNumber(roll) {}

    bool operator()(const Student& student) const {
        return student.getRollNumber() == rollNumber;
    }
};


struct FindByRollNumber {
    int rollNumber;
    FindByRollNumber(int roll) : rollNumber(roll) {}

    bool operator()(const Student& student) const {
        return student.getRollNumber() == rollNumber;
    }
};


class StudentRecordSystem {
private:
    vector<Student> records;

public:
    // Function to insert a new student record
    void insertRecord() {
        string name, course;
        int rollNumber;
        float totalMarks;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name); 
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        while (cin.fail()) {
            cout << "Invalid input. Enter a valid Roll Number: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> rollNumber;
        }
        cout << "Enter Course: ";
        cin.ignore();
        getline(cin, course); 
        cout << "Enter Total Marks: ";
        cin >> totalMarks;
        while (cin.fail()) {
            cout << "Invalid input. Enter valid Total Marks: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> totalMarks;
        }

        records.push_back(Student(name, rollNumber, course, totalMarks));
        cout << "Record inserted successfully!" << endl;
    }

    
    void deleteRecord(int rollNumber) {
        vector<Student>::iterator it = remove_if(records.begin(), records.end(), RemoveByRollNumber(rollNumber));

        if (it != records.end()) {
            records.erase(it, records.end());
            cout << "Record deleted successfully!" << endl;
        } else {
            cout << "No record found with Roll Number: " << rollNumber << endl;
        }
    }

    
    void searchRecord(int rollNumber) const {
        vector<Student>::const_iterator it = find_if(records.begin(), records.end(), FindByRollNumber(rollNumber));

        if (it != records.end()) {
            it->display();
        } else {
            cout << "No record found with Roll Number: " << rollNumber << endl;
        }
    }

    
    void showAllRecords() const {
        if (records.empty()) {
            cout << "No records to display!" << endl;
            return;
        }
        for (vector<Student>::const_iterator it = records.begin(); it != records.end(); ++it) {
            it->display();
            cout << "-----------------------------" << endl;
        }
    }
};

int main() {
    StudentRecordSystem srs;
    int choice, rollNumber;

    do {
        cout << "\nStudent Record Management System" << endl;
        cout << "1. Insert Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Show Record" << endl;
        cout << "4. Search Record" << endl;
        cout << "5. Show All Records" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail()) {
            cout << "Invalid input. Enter a valid choice: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }

        switch (choice) {
            case 1:
                srs.insertRecord();
                break;
            case 2:
                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;
                while (cin.fail()) {
                    cout << "Invalid input. Enter a valid Roll Number: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> rollNumber;
                }
                srs.deleteRecord(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number to show: ";
                cin >> rollNumber;
                while (cin.fail()) {
                    cout << "Invalid input. Enter a valid Roll Number: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> rollNumber;
                }
                srs.searchRecord(rollNumber);
                break;
            case 4:
                cout << "Enter Roll Number to search: ";
                cin >> rollNumber;
                while (cin.fail()) {
                    cout << "Invalid input. Enter a valid Roll Number: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> rollNumber;
                }
                srs.searchRecord(rollNumber);
                break;
            case 5:
                srs.showAllRecords();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
