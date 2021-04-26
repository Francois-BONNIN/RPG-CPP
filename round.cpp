#include "round.h"
#include <iostream>
#include "ia.h"

using namespace std;

// Charger les valeurs necessaire au bon fonctionnement du tour

int tour::ActonJoueur = 0;
int tour::ActionIA = 0;
vector<specIA> windows::listMageIA;
vector<int> windows::listAttack;

// Constructeur / Enregistre les valeurs

round::round(int action, int NTour, int P, int IA) {
    NbTour = NTour;
    m_P = P;
    m_IA = IA;
    cout << "|| Tour : " << NbTour << " ||" << endl;
    actionJ = action;
    startTour(actionJ);
}

// Destructeur tour

round::~round() {
}

// Recupere les action effectue par l_ia

void round::checkIAAction() {
    IA();
    actionIA = IA::IAaction;
    if (NbTour == 0 && windows::list_attack.size() == 0) {
        actionIA = 0;
    }
}

// Demarre le tour et verifie que des actions ne doivent pas s_effectuer en amont

int round::startTour(int actionJ) {

    checkIAAction();
    windows::list_attack.push_back(actionJ);

    action(actionJ, actionIA, m_P, m_IA);
    return (0);
}

// -------------------------------------------------

// Constructeur / Enregistre les valeurs pour effectuer les actions

action::action(int actionJ, int actionIA, int P, int IA) {
    m_actionJ = actionJ;
    m_actionIA = actionIA;
    m_P = P;
    m_IA = IA;
    applyAction();
    cout << "Action joueur : " << m_actionJ << '\n' << "Action IA : " << actionIA << endl;
}

// Affiche les action du joueur et de l_ia

void action::printAction() {
}

// Compare les action du joueur et de l_ia

int action::applyAction() {
    if (m_actionJ == 0 && m_actionIA == 0) {
        //
    }
    else if (m_actionJ == 0 && m_actionIA == 1) {
        listMage[m_P].updateLife(- 20);
    }
    else if (m_actionJ == 0 && m_actionIA == 2) {
        //
    }
    else if (m_actionJ == 1 && m_actionIA == 0) {
        listMageIA[m_IA].updateLifeIA(- 20);
    }
    else if (m_actionJ == 1 && m_actionIA == 1) {
        listMageIA[m_IA].updateLifeIA(- 20);
        listMage[m_P].updateLife(- 20);
    }
    else if (m_actionJ == 1 && m_actionIA == 2) {
        //
    }
    else if (m_actionJ == 2 && (m_actionIA == 0 || m_actionIA == 1 || m_actionIA == 2)) {
        //
    }
    printAction();
    return (0);
}

// Destructeur action

action::~action() {
}
