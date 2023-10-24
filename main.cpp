#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int studentNumber;
    int koreanScore;
    int englishScore;
    int mathScore;

public:
    Student(const string& name, int studentNumber, int koreanScore, int englishScore, int mathScore)
        : name(name), studentNumber(studentNumber), koreanScore(koreanScore), englishScore(englishScore), mathScore(mathScore) {}

    double calculateAverage() const {
        return static_cast<double>(koreanScore + englishScore + mathScore) / 3;
    }

    const string& getName() const {
        return name;
    }

    int getStudentNumber() const {
        return studentNumber;
    }

    int getKoreanScore() const {
        return koreanScore;
    }

    int getEnglishScore() const {
        return englishScore;
    }

    int getMathScore() const {
        return mathScore;
    }
};

bool compareByAverage(const Student& a, const Student& b) {
    return a.calculateAverage() > b.calculateAverage();
}

void printStudentInfo(const Student& student) {
    cout << "�̸�: " << student.getName() << endl;
    cout << "�й�: " << student.getStudentNumber() << endl;
    cout << "���� ����: " << student.getKoreanScore() << endl;
    cout << "���� ����: " << student.getEnglishScore() << endl;
    cout << "���� ����: " << student.getMathScore() << endl;
    cout << "��� ����: " << student.calculateAverage() << endl;
}

int main() {
    list<Student> students;
    char choice;

    do {
        cout << "�޴�:" << endl;
        cout << "1. �л� ���� �Է�" << endl;
        cout << "2. ��� �л� ���� ���" << endl;
        cout << "3. �̸����� �˻�" << endl;
        cout << "4. ��ȣ�� �˻�" << endl;
        cout << "5. �̸����� ��հ� ��� ���" << endl;
        cout << "6. ������� ���� ������ �̸� ���" << endl;
        cout << "q. ����" << endl;

        cout << "���ϴ� �۾��� �����ϼ���: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string name;
            int studentNumber, koreanScore, englishScore, mathScore;

            cout << "�̸� �Է�: ";
            cin >> name;

            cout << "�й� �Է�: ";
            cin >> studentNumber;

            cout << "���� ���� �Է�: ";
            cin >> koreanScore;

            cout << "���� ���� �Է�: ";
            cin >> englishScore;

            cout << "���� ���� �Է�: ";
            cin >> mathScore;

            students.push_back(Student(name, studentNumber, koreanScore, englishScore, mathScore));
            break;
        }
        case '2': {
            for (const Student& student : students) {
                printStudentInfo(student);
                cout << endl;
            }
            break;
        }
        case '3': {
            string searchName;
            cout << "�˻��� �̸� �Է�: ";
            cin >> searchName;

            auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
                return student.getName() == searchName;
                });

            if (it != students.end()) {
                printStudentInfo(*it);
            }
            else {
                cout << "�̸� " << searchName << " ��(��) ���� �л��� �����ϴ�." << endl;
            }
            break;
        }
        case '4': {
            int searchNumber;
            cout << "�˻��� �й� �Է�: ";
            cin >> searchNumber;

            auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
                return student.getStudentNumber() == searchNumber;
                });

            if (it != students.end()) {
                printStudentInfo(*it);
            }
            else {
                cout << "�й� " << searchNumber << " ��(��) ���� �л��� �����ϴ�." << endl;
            }
            break;
        }
        case '5': {
            string searchName;
            cout << "�̸� �Է�: ";
            cin >> searchName;

            auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
                return student.getName() == searchName;
                });

            if (it != students.end()) {
                printStudentInfo(*it);
                int rank = 1;
                for (const Student& student : students) {
                    if (student.calculateAverage() > it->calculateAverage()) {
                        rank++;
                    }
                }
                cout << "���: " << rank << endl;
            }
            else {
                cout << "�̸� " << searchName << " ��(��) ���� �л��� �����ϴ�." << endl;
            }
            break;
        }
        case '6': {
            list<Student> sortedStudents = students;
            sortedStudents.sort(compareByAverage);
            cout << "������� ���� ������ �л� �̸� ���:" << endl;
            for (const Student& student : sortedStudents) {
                cout << student.getName() << endl;
            }
            break;
        }
        case 'q':
        case 'Q':
            cout << "�����մϴ�..." << endl;
            break;
        default:
            cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �����ϼ���." << endl;
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}