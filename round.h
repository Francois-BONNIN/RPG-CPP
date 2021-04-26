#ifndef ROUND_H
#define ROUND_H

#include <iostream>

class round {
protected:
    int actionJ;
    int actionIA;
    int m_P;
    int m_IA;
    int NbTour = 0;
public:
    round(int actionJ, int NTour, int SJ, int SIA, int P, int IA);
    int startTour(int actionJ);
    void checkIAAction();
    ~round();
};

class action : public windows {
protected:
    int m_actionJ;
    int m_actionIA;
    int m_P;
    int m_IA;
public:
    action(int actionJ, int actionIA, int P, int IA);
    ~action();
    int applyAction();
    void compareAction();
    void printAction();
    int getAJ();
    int getAIA();
};

#endif // ROUND_H
