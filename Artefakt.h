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
    Artefakt(int id, int godina, string& ime, string& opis, string& lokacija, ArtefaktTip tip);
    ~Artefakt() = default;
};


#endif //SISTEM_PREZERVACIJE_KULTURNOG_NASLJEDJA2_ARTEFAKT_H
