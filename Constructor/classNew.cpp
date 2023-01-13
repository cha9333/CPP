#include <iostream>
using namespace std;

class CTest
{
    int m_nData;

public:
    CTest(int nParam): m_nData(nParam){
        cout << "CTest::CTest()" << m_nData << endl;
    }

    ~CTest(){
        cout << "~CTest::CTest() " << m_nData << endl;
    }
};

int main()
{
    cout << "Begin" << endl;

    CTest *pData=new CTest[3]={1, 2, 3};

    delete [] pData;    

    cout << "End" << endl;
    
    return 0;
}
