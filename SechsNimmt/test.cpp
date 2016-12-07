#include <iostream>


using namespace std;

class testclass
{

public:
    testclass(){test++;}
    int getTest(){cout << test << endl;}
private:
    static int test;
};

int testclass::test = 0;

int tmain(){

    {
        testclass obj1;
        obj1.getTest();
    }

    testclass obj2;
    obj2.getTest();


    return 0;
}
