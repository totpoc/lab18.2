#include <iostream>
#include <string>

using namespace std;

template<typename G>
G getCorrectNubmer(G inputType)
{
    G inputNumber;
    while (!(cin >> inputNumber) || (cin.peek() != '\n') || (inputNumber < 0))
    {
        cin.clear();
        while (cin.get() != '\n')
        {
            cin.ignore();
            cout << "Введите корректное число: ";
        }
    }
    return inputNumber;
}

class SLAVE
{
    string _fullName, _position;
    double _salary;

public:

    SLAVE() {
        _fullName = "";
        _position = "";
        _salary = 0;
    }
    SLAVE(string fullName, string position, double salary)
    {
        this->_fullName = fullName;
        this->_position = position;
        this->_salary = salary;
    }
    SLAVE(const SLAVE& temp)
    {
        _fullName = temp._fullName;
        _position = temp._position;
        _salary = temp._salary;
    }
    ~SLAVE(){}

    void setFullName()
    {
        cout << "Введите ФИО: ";
        cin.ignore(0, '\n');
        getline(cin, _fullName);
    }
    void setPosition()
    {
        cout << "Введите должность: ";
        cin.ignore(0,'\n');
        getline(cin, _position);
    }
    void setSalary()
    {
        cout << "Введите зарплату: ";
        _salary = getCorrectNubmer(_salary);
        
    }

    string getFullName()  { return _fullName; }
    string getPosition()  { return _position; }
    double getSalary()    { return _salary; }

    void printData()
    {
        cout << "ФИО: " << _fullName << endl;
        cout << "Должность: " << _position << endl;
        cout << "Зарплата: " << _salary << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Rus");
    SLAVE objectFirst, objectSecond("Aaaa Aaaa Aaaa", "A", 222.2), objectThird(objectSecond);

    objectFirst.setFullName();
    objectFirst.setPosition();
    objectFirst.setSalary();

    cout << endl;
    objectFirst.printData();
    cout << endl;
    objectSecond.printData();
    cout << endl;
    objectThird.printData();
    cout << endl;

    return 0;
}

