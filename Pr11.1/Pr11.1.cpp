#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <Windows.h>

using namespace std;

void Create(char* fname);
void Process(char* fname, char* gname);
void Print(char* gname);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char fname[100];
    cout << "������ ����� ������� �����: ";
    cin >> fname;

    Create(fname);

    char gname[100];
    cout << "������ ����� ������� �����: ";
    cin >> gname;

    Process(fname, gname);

    cout << "�������� �� �� � ���������� ������� sin(x):" << endl;
    Print(gname);
}

void Create(char* fname) {
    ofstream fout(fname, ios::binary);

    char ch;
    double num;

    do {
        cin.sync();

        cout << "������ ���� ��������: ";
        cin >> num;

        fout.write(reinterpret_cast<const char*>(&num), sizeof(num));

        cout << "����������? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    cout << endl;
}

void Process(char* fname, char* gname) {
    ifstream f(fname, ios::binary);
    ofstream g(gname, ios::binary);

    double number;
    while (f.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        if (number < -1.0 || number > 1.0)
            g.write(reinterpret_cast<char*>(&number), sizeof(number));
    }
    f.close();
    g.close();
}

void Print(char* gname) {
    ifstream gin(gname, ios::binary);

    double number;
    while (gin.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        cout << number << endl;
    }
    cout << endl;
    gin.close();
}