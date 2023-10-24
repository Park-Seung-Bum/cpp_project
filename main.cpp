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
    cout << "이름: " << student.getName() << endl;
    cout << "학번: " << student.getStudentNumber() << endl;
    cout << "국어 점수: " << student.getKoreanScore() << endl;
    cout << "영어 점수: " << student.getEnglishScore() << endl;
    cout << "수학 점수: " << student.getMathScore() << endl;
    cout << "평균 점수: " << student.calculateAverage() << endl;
}

int main() {
    list<Student> students;
    char choice;

    do {
        cout << "메뉴:" << endl;
        cout << "1. 학생 정보 입력" << endl;
        cout << "2. 모든 학생 정보 출력" << endl;
        cout << "3. 이름으로 검색" << endl;
        cout << "4. 번호로 검색" << endl;
        cout << "5. 이름으로 평균과 등수 출력" << endl;
        cout << "6. 평균점수 높은 순으로 이름 출력" << endl;
        cout << "q. 종료" << endl;

        cout << "원하는 작업을 선택하세요: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            string name;
            int studentNumber, koreanScore, englishScore, mathScore;

            cout << "이름 입력: ";
            cin >> name;

            cout << "학번 입력: ";
            cin >> studentNumber;

            cout << "국어 점수 입력: ";
            cin >> koreanScore;

            cout << "영어 점수 입력: ";
            cin >> englishScore;

            cout << "수학 점수 입력: ";
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
            cout << "검색할 이름 입력: ";
            cin >> searchName;

            auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
                return student.getName() == searchName;
                });

            if (it != students.end()) {
                printStudentInfo(*it);
            }
            else {
                cout << "이름 " << searchName << " 을(를) 가진 학생이 없습니다." << endl;
            }
            break;
        }
        case '4': {
            int searchNumber;
            cout << "검색할 학번 입력: ";
            cin >> searchNumber;

            auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
                return student.getStudentNumber() == searchNumber;
                });

            if (it != students.end()) {
                printStudentInfo(*it);
            }
            else {
                cout << "학번 " << searchNumber << " 을(를) 가진 학생이 없습니다." << endl;
            }
            break;
        }
        case '5': {
            string searchName;
            cout << "이름 입력: ";
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
                cout << "등수: " << rank << endl;
            }
            else {
                cout << "이름 " << searchName << " 을(를) 가진 학생이 없습니다." << endl;
            }
            break;
        }
        case '6': {
            list<Student> sortedStudents = students;
            sortedStudents.sort(compareByAverage);
            cout << "평균점수 높은 순으로 학생 이름 출력:" << endl;
            for (const Student& student : sortedStudents) {
                cout << student.getName() << endl;
            }
            break;
        }
        case 'q':
        case 'Q':
            cout << "종료합니다..." << endl;
            break;
        default:
            cout << "유효하지 않은 선택입니다. 다시 선택하세요." << endl;
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}