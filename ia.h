#ifndef IA_H
#define IA_H

#include <iostream>

class IA {
protected:
    int NbAction;
    int JAction;
    int JAction2;
public:
    IA();
    ~IA();
    int chooseIA_action();
    void getJAction();
    int getIA_action();
    static int IAaction;
};

class specIA {
protected:
    int m_lifeIA;
    int m_typeIA;
public:
    specIA(int lifeIA, int typeIA);
    ~specIA();
    int getLifeIA();
    int updateLifeIA(int value);
    int getTypeIA();
};


#endif // IA_H
