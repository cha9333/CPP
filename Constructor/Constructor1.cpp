#include <iostream>
using namespace std;

class CTest
{
    int m_nData;

public:
    CTest(){
        cout << "CTest::CTest()" << endl;
    }

    ~CTest(){
        cout << "~CTest::CTest() " << m_nData << endl;
    }
};

int main()
{
    cout << "Begin" << endl;
    
    // CTest a(1);
    // cout << "Before b" << endl;
    // CTest b(2);
    // cout << "End" << endl;

    CTest *pData=new CTest();
    cout << "Test" << endl;

    delete pData;
    cout << "End" << endl;
    
    return 0;
}
