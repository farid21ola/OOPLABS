#include <iostream>
#include <vector>

class Detail {
protected:
    Detail() {}
public:
    template<typename T>
    friend void addToVector(std::vector<Detail*>& v);
    virtual ~Detail() {}
};

class Assembly: public Detail{
protected:
    Assembly() {}
public:
    template<typename T>
    friend void addToVector(std::vector<Detail*>& v);
    ~Assembly() {}
};

template<typename T>
void addToVector(std::vector<Detail*>& v) {
    v.push_back(new T());
}


int main()
{
    std::vector<Detail*> details;
    addToVector<Detail>(details);
    addToVector<Detail>(details);
    addToVector<Detail>(details);
    addToVector<Detail>(details);
    addToVector<Assembly>(details);
    addToVector<Assembly>(details);
    std::cout << "Count of details:" << details.size()<<"\n";
    for (Detail* x : details) {
        delete x;
    }
    details.clear();
    return 0;
}
