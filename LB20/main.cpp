#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age{};

    [[nodiscard]] string get_name() const
    {
        return name + "\n";
    }
};

void print(const Person* person)
{
    cout << person->name << " is " << person->age << " years old" << endl;
}

void task1()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    cout << "Meet " << person.get_name();
    print(&person);

    Person liam;
    liam.age = 20;
    liam.name = "Liam";
    cout << "Meet " << liam.get_name();
    print(&liam);

    Person sophie;
    sophie.name = "Sophie";
    sophie.age = 19;
    cout << "Meet " << sophie.get_name();
    print(&sophie);

    Person noah;
    noah.name = "Noah";
    noah.age = 18;
    cout << "Meet " << noah.get_name();
    print(&noah);
}


class Square
{
public:
    explicit Square(double side);

    void set_side(const double side)
    {
        if (side >= 0)
        {
            this->side = side;
            area = side * side;
        }
    }

    void print() const
    {
        cout << "Square: side=" << this->side << " area=" << this->area << endl;
    }

private:
    double side;
    double area;
};

Square::Square(const double side)
{
    this->side = side;
    this->area = side * side;
}

void task2()
{
    Square s(4);
    s.print();
    s.set_side(2.0);
    s.print();
    s.set_side(-33.0);
    s.print();
}


class AdHocSquare
{
public:
    explicit AdHocSquare(const double side)
    {
        set_side(side);
    };

    void set_side(const double side)
    {
        if (side >= 0)
        {
            this->side = side;
        }
    };

    [[nodiscard]] double getArea() const
    {
        return this->side * this->side;
    };

    void print() const
    {
        cout << "Square: side=" << this->side << " area=" << this->getArea() << endl;
    }

private:
    double side{};
};

class LazySquare
{
public:
    explicit LazySquare(const double side)
    {
        set_side(side);
        this->side_changed = true;
    };

    void set_side(const double side)
    {
        if (side >= 0)
        {
            this->side = side;
            this->side_changed = true;
        }
    };

    double get_area()
    {
        if (this->side_changed)
        {
            this->side_changed = false;
            this->area = this->side * this->side;
        }
        return this->area;
    };

    void print()
    {
        cout << "Square: side=" << this->side << " area=" << this->get_area() << endl;
    }

private:
    double side{};
    double area{};
    bool side_changed;
};

void task3()
{
    cout << "AdHocSquare" << endl;
    AdHocSquare ad_hoc_square(4);
    ad_hoc_square.print();
    ad_hoc_square.set_side(2.0);
    ad_hoc_square.print();
    ad_hoc_square.set_side(-33.0);
    ad_hoc_square.print();

    cout << endl << endl;
    cout << "LazySquare" << endl;
    LazySquare lazy_square(5);
    lazy_square.print();
    lazy_square.set_side(2.0);
    lazy_square.print();
    lazy_square.set_side(-33.0);
    lazy_square.print();
}

int main()
{
    // task1();
    // task2();
    task3();
    return 0;
}
