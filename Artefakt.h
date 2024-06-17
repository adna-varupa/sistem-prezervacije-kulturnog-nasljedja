//
// Created by User on 6/15/2024.
//

#ifndef SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_ARTEFAKT_H
#define SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_ARTEFAKT_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

enum class ArtefaktTip { KERAMIKA, ALAT, TEKSTIL, ORUZJE, NAKIT };

class Artefakt {
protected:
    int id;
    int godina;
    string ime;
    string opis;
    string lokacija;
    ArtefaktTip tip;

public:
    Artefakt(int id, int godina, const string& ime, const string& opis, const string& lokacija, ArtefaktTip tip)
            : id(id), godina(godina), ime(ime), opis(opis), lokacija(lokacija), tip(tip) {}

    virtual ~Artefakt() = default;

    // Getters
    int getId() const { return id; }
    int getGodina() const { return godina; }
    string getIme() const { return ime; }
    string getOpis() const { return opis; }
    string getLokacija() const { return lokacija; }
    ArtefaktTip getTip() const { return tip; }

    // Setters
    void setId(int newId) { id = newId; }
    void setGodina(int newGodina) { godina = newGodina; }
    void setIme(const string& newIme) { ime = newIme; }
    void setOpis(const string& newOpis) { opis = newOpis; }
    void setLokacija(const string& newLokacija) { lokacija = newLokacija; }
    void setTip(ArtefaktTip newTip) { tip = newTip; }

    virtual void prikazi() const {
        cout << "ID: " << id << "\nGodina: " << godina << "\nIme: " << ime << "\nOpis: " << opis << "\nLokacija: " << lokacija << "\nTip: " << static_cast<int>(tip) << endl;
    }

    friend ostream& operator<<(ostream& os, const Artefakt& artefakt);
};

#endif //SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_ARTEFAKT_H
