//
// Created by User on 6/15/2024.
//

#include "Artefakt.h"

ostream& operator<<(ostream& os, const Artefakt& artefakt) {
    os << "ID: " << artefakt.id << "\nGodina: " << artefakt.godina << "\nIme: " << artefakt.ime << "\nOpis: " << artefakt.opis << "\nLokacija: " << artefakt.lokacija << "\nTip: " << static_cast<int>(artefakt.tip) << endl;
    return os;
}
