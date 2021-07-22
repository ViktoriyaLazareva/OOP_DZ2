#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

//Task 1.1--------------------------------------------------------------------------

typedef enum Gender{unknown, male, female};

class Person
{
private:
    string p_name;
    int p_age;
    Gender p_gender;
    int p_weight;
public:
    Person(string name, int age, Gender gender, int weight) {
    p_name = name;
    p_age = age;
    p_gender = gender;
    p_weight = weight;
    }
    Person() {}

    void setName(string name) {
    p_name = name;
    }

    void setAge(int age) {
    p_age = age;
    }

    void setGender(Gender gender) {
    p_gender = gender;
    }

    void setWeight(int weight) {
    p_weight = weight;
    }

    string getName() {
    return p_name;
    }

    int getAge() {
    return p_age;
    }

    Gender getGender() {
    return p_gender;
    }

    int getWeight() {
    return p_weight;
    }

  };

  class Student : public Person
  {
private:
      int p_year_study;
      static int counter;
public:
    Student(string name, int age, Gender gender, int weight, int year_study) {
    setName(name);
    setAge(age);
    setGender(gender);
    setWeight(weight);
    p_year_study = year_study;
    counter++;
    }


    void setyear_study(int year) {
    p_year_study = year;
    }

    void setyear_study() {
    p_year_study++;
    }

    int getyear_study() {
    return p_year_study;
    }
    friend void getData(Student& anyStudent);

    static int getCounter(){
    return counter;
    }
  };

  void getData(Student& anyStudent){
    string gender;

    switch(anyStudent.getGender()){
        case male: gender = "male";
        break;
        case unknown: gender = "unknown";
        break;
        case female: gender = "female";
        break;
    }

    cout <<"Task 1--------------------------------" << endl;
    cout << "Name: " << anyStudent.getName() << "\n" << "Gender: " << gender << "\n" << "Age: "
    << anyStudent.getAge() << "\n" << "Weight: " << anyStudent.getWeight() << "\n" << "Year of study: "\
    << anyStudent.getyear_study() << endl << endl;

}
int Student::counter = 0;

//Task 2.1----------------------------------------------------------------------------------------------

class Fruit{
protected:
    string name;
    string color;
public:
    Fruit(){}

    string getName(){
        return name;
    }

    void setColor(string n_color){
    color = n_color;
    }

    string getColor(){
        return color;
    }

};


class Banana : public Fruit{
public:
    Banana(){
        name = "banana";
        color = "yellow";
    }
};

class Apple : public Fruit{
private:

public:
    Apple(string n_color){
        name = "apple";
        color = n_color;
        }

    Apple(){
        name = "Granny Smith apple";
        color = "green";
        }
};

class GrannySmith : public Apple{
public:
    GrannySmith(): Apple(){}
};

int main()
{
//Task 1.2----------------------------------------------------------------------------------------------

    Student Ivan("Ivan", 49, male, 100, 2020);
    Student Vika("Vika", 41, female, 56, 2019);
    Student Vova("Vova", 41, male, 41, 2018);
    Student It("It", 300, unknown, 10, 1812);

    getData(Ivan);
    getData(Vika);
    getData(Vova);
    getData(It);
    cout << "Total students: " << Ivan.getCounter() << endl;
    cout <<"Task 2--------------------------------" << endl;

//Task 2.2----------------------------------------------------------------------------------------------

 Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    system ("Pause");

    return 0;
}
