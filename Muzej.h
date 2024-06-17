//
// Created by User on 6/17/2024.
//

#ifndef SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_MUZEJ_H
#define SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_MUZEJ_H


#include "Artefakt.h"
#include "HistorijskiDogadjaj.h"
#include <vector>
#include <fstream>
#include <stdexcept>

class Muzej {
private:
    vector<shared_ptr<Artefakt>> artefakti;
    vector<shared_ptr<HistorijskiDogadjaj>> dogadjaji;

public:
    void dodajArtefakt(shared_ptr<Artefakt> artefakt) {
        artefakti.push_back(artefakt);
    }

    void dodajDogadjaj(shared_ptr<HistorijskiDogadjaj> dogadjaj) {
        dogadjaji.push_back(dogadjaj);
    }

    void prikaziSve() const {
        for (const auto& artefakt : artefakti) {
            artefakt->prikazi();
            cout << "------------------" << endl;
        }

        for (const auto& dogadjaj : dogadjaji) {
            dogadjaj->prikazi();
            cout << "------------------" << endl;
        }
    }

    void sacuvaj(const string& filename) const {
        ofstream file(filename);
        if (!file) throw runtime_error("Ne mogu otvoriti fajl za pisanje.");
        for (const auto& artefakt : artefakti) {
            file << *artefakt << "\n";
        }
        for (const auto& dogadjaj : dogadjaji) {
            file << *dogadjaj << "\n";
        }
        file.close();
    }

    void ucitaj(const string& filename) {
        ifstream file(filename);
        if (!file) throw runtime_error("Ne mogu otvoriti fajl za citanje.");
        // Add code to read artefacts and events from file
        // Not implemented here for brevity
        file.close();
    }
};



#endif //SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_MUZEJ_H
