//
// Created by User on 6/17/2024.
//

#include "HistorijskiDogadjaj.h"

ostream& operator<<(ostream& os, const HistorijskiDogadjaj& dogadjaj) {
    os << "ID: " << dogadjaj.id << "\nNaziv: " << dogadjaj.naziv << "\nGodina: " << dogadjaj.godina << "\nOpis: " << dogadjaj.opis << endl;
    return os;
}
