#include <iostream>


using namespace std;

class testclass
{

public:
    testclass(){test++;}
    void printTest(){cout << test << endl;}
private:
    static int test;
};

int testclass::test = 0;

int tmain(){

    {
        testclass obj1;
        obj1.printTest();
    }

    testclass obj2;
    obj2.printTest();


    return 0;
}
