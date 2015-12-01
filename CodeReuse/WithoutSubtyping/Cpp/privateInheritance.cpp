/**
 * @author Dmitry Logvinovich
 *
 * 01.12.2015
 *
 *This code is inended to demonstrate the usage of Private inheritance
 *in C++. Private inheritance allows code reuse without subtyping.
 */ 

#include<iostream>

using namespace std;

class A {
    public:
        A(int a, int b) {
            this->a = a;
            this->b = b;
        }
        int getA() {
            return this->a;
        }
        void setA(int val) {
            this->a = val;
        }
        int getB() {
            return this->b;
        }
        void setB(int val) {
            this->b = val;
        }
    private: 
        int a, b;
};

class B: private A {
    public:
        B(int a): A(a, 2) { //A has to be initialized from within B
            this->a = a;
        }
        //note that A is a supertype of B within B body
        B(int a, B* that): A(a, that->getA()) {
            this->a = a;
            this->b = that;
        }
        A::getA;
        A::setA;
    private:
        int a;
        A* b;
};

int main() {
    B* b1 = new B(1);
    B* b2 = new B(1, b1);
    cout << b1->getA() << endl;
    /*either of those will not compile because outside B's body,
    A is not a supertype of B
    A* b3 = new B(3);
    cout << b1->getB() << endl;
    */
    return 0;
}
        


