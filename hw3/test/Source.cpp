#include<iostream>
using namespace std;
class Base {
public:
    virtual void f(int) { cout << "Base\n"; }
    char i;
    int j;
    int k;
    int l;
    int m;
    int n;
};
class Derived : public Base {
public:
    void f(int) { cout << "Derived\n"; }
};
int main() {
    Derived* d = new Derived();
    Base* b = d;
    //d->f(3.14F);
    cout << (int)(b -> i);
    //cout << b->j;
    //cout << b->k;
    //cout << b->l;
    //cout << b->m;
    //cout << b->n;
}