#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData(int nParam) : m_nData(nParam) {};
	void PrintData(){
//		CMyData *this=pData;
		cout << m_nData << endl;
		cout << CMyData::m_nData << endl;
		cout << this->m_nData << endl;
		cout << this->CMyData::m_nData << endl;
	}

private:
	int m_nData;
};

int main()
{
	CMyData a(5), b(10);
	a.PrintData();
	b.PrintData();

	return 0;
}
 