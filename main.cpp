#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include "Artefakt.h"

using namespace std;

class MuzejskiArtefakt : public Artefakt {
private:
    string muzejskiNaziv;

public:
    MuzejskiArtefakt(int id, int godina, const string& ime, const string& opis, const string& lokacija, ArtefaktTip tip, const string& muzejskiNaziv)
            : Artefakt(id, godina, ime, opis, lokacija, tip), muzejskiNaziv(muzejskiNaziv) {}

    void prikaziDetalje() const override {
        Artefakt::prikaziDetalje();
        cout << "Muzejski naziv: " << muzejskiNaziv << endl;
    }
};

void sacuvajUFajl(const vector<unique_ptr<Artefakt>>& artefakti, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Greska prilikom otvaranja datoteke za pisanje." << endl;
        return;
    }

    for (const auto& artefakt : artefakti) {
        outFile << *artefakt << endl;
    }

    outFile.close();
}

void meni() {
    cout << "----- MENI -----" << endl;
    cout << "1. Prikazi detalje artefakta" << endl;
    cout << "2. Sacuvaj u datoteku" << endl;
    cout << "3. Izlaz" << endl;
    cout << "----------------" << endl;
}

int main() {
    vector<unique_ptr<Artefakt>> artefakti;

    // Dummy data for testing
    artefakti.push_back(make_unique<MuzejskiArtefakt>(1, 1200, "Amfora", "Stara amfora iz antičkog perioda.", "Atina", ArtefaktTip::KERAMIKA, "Muzej grčke umjetnosti"));
    artefakti.push_back(make_unique<Artefakt>(2, 300, "Bronzani mač", "Bronzani mač iz doba željeza.", "Rim", ArtefaktTip::ORUZJE));

    int choice;
    do {
        meni();
        cout << "Izaberite opciju: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Unesite ID artefakta: ";
                int id;
                cin >> id;
                bool found = false;
                for (const auto& artefakt : artefakti) {
                    if (artefakt->getId() == id) {
                        artefakt->prikaziDetalje();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Artefakt sa ID " << id << " nije pronadjen." << endl;
                }
                break;
            case 2:
                sacuvajUFajl(artefakti, "artefakti.txt");
                cout << "Podaci sacuvani u datoteku artefakti.txt" << endl;
                break;
            case 3:
                cout << "Izlaz iz programa." << endl;
                break;
            default:
                cout << "Nepostojeca opcija. Pokusajte ponovo." << endl;
        }
    } while (choice != 3);

    return 0;
}
