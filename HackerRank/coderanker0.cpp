#include <iostream>
#include <sstream>
using namespace std;

class Student{
    int age;
    string first_name;
    string last_name;
    int standard;
 public:
    inline void set_age(int i){this->age = i; };
    inline void set_first_name(string str){this->first_name = str; };
    inline void set_last_name(string str){this->last_name = str; };
    inline void set_standard(int i){this->standard = i; };
    int get_age(){return this->age;};
    string get_first_name(){return this->first_name;};
    string get_last_name(){return this->last_name;};
    int get_standard(){return this->standard;};
    void to_string(){
      cout << age << "," << first_name << "," << last_name << "," << standard;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    st.to_string();

    return 0;
}
