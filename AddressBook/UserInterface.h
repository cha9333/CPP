class CMyList;

class CUserInterface
{
public:
    CUserInterface(void);
    CUserInterface(CMyList &rList);
    ~CUserInterface(void);
    void Add(void);

protected:
    // CMyList &M_List;

public:
    void Search(void);
    void Remove(void);
    int PrintUI(void);
    
    int Run(void);
};