//
// Created by User on 6/17/2024.
//

#ifndef SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_HISTORIJSKIDOGADJAJ_H
#define SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_HISTORIJSKIDOGADJAJ_H

#include <iostream>
#include <string>

using namespace std;

class HistorijskiDogadjaj {
private:
    int id;
    string naziv;
    int godina;
    string opis;

public:
    HistorijskiDogadjaj(int id, const string& naziv, int godina, const string& opis)
            : id(id), naziv(naziv), godina(godina), opis(opis) {}

    // Getters
    int getId() const { return id; }
    string getNaziv() const { return naziv; }
    int getGodina() const { return godina; }
    string getOpis() const { return opis; }

    // Setters
    void setId(int newId) { id = newId; }
    void setNaziv(const string& newNaziv) { naziv = newNaziv; }
    void setGodina(int newGodina) { godina = newGodina; }
    void setOpis(const string& newOpis) { opis = newOpis; }

    void prikazi() const {
        cout << "ID: " << id << "\nNaziv: " << naziv << "\nGodina: " << godina << "\nOpis: " << opis << endl;
    }

    friend ostream& operator<<(ostream& os, const HistorijskiDogadjaj& dogadjaj);
};

#endif //SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_HISTORIJSKIDOGADJAJ_H
