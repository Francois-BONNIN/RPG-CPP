#include <iostream>
#include "ia.h"

using namespace std;
int IA::IAaction;

// Constructeur IA

IA::IA() {
    windows::listMageIA.reserve(3);
    windows::listMageIA.emplace_back(100, 2);
    windows::listMageIA.emplace_back(100, 3);
    windows::listMageIA.emplace_back(100, 1);
    getJAction();
    chooseIA_action();
}

// Destructeur IA

IA::~IA() {
}

// Permet d_acceder au action faites precedemment ( 1 ou 2 ) par le joueur

void IA::getJAction() {
    if (windows::list_attack.size() != 0) {
        NbAction = windows::list_attack.size();
        JAction = NbAction - 1;
        if (NbAction > 1)
            JAction2 = NbAction - 2;
    } else
        NbAction = 0;
}

// Permet a l_ia de choisir une action ( en fonction de ce que le joueur a deja fait )

int IA::chooseIA_action() {
    if (NbAction < 2) {
        IAaction = rand() % 3 + 1;
    } else {
        if (windows::list_attack[JAction] == windows::list_attack[JAction2]) {
            IAaction = (windows::list_attack[JAction] + 1) % 3;
            if (IAaction == 0)
                IAaction = 3;
        } else {
            IAaction = windows::list_attack[JAction];
        }
    }
    return (0);
}

// Attribue des stats a l_ia / constructeur

specIA::specIA(int life, int type) {
    m_lifeIA = life;
    m_typeIA = type;
}

// Destructeur SpecIA

specIA::~specIA() {

}

// Met a jour la stat de vie

int specIA::updateLifeIA(int value) {
    m_lifeIA += value;
    return (0);
}

// Retourne la stat de vie

int specIA::getLifeIA() {
    return m_lifeIA;
}

// Retourne la stat de type

int specIA::getTypeIA() {
    return m_typeIA;
}
