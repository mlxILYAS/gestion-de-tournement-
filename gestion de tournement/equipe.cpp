#include "Equipe.h"
#include <iostream>
#include <string>

using namespace std;

Equipe::Equipe()
    : idEquipe(0),
      nomEquipe(""),
      nombreJoueur(0),
      villeEquipe(""),
      score(0.0f),
      classement(0),
      exsisteintournement(false) {}

Equipe::Equipe(int id, const string& nom, int nbJoueurs, const string& ville, bool exsisteintournement)
    : idEquipe(id), nomEquipe(nom), nombreJoueur(nbJoueurs),
      villeEquipe(ville), score(0.0f), classement(0), exsisteintournement(exsisteintournement) {}

int Equipe::getIdEquipe() const {
    return idEquipe;
}

void Equipe::setIdEquipe(int id) {
    idEquipe = id;
}

string Equipe::getNomEquipe() const {
    return nomEquipe;
}

void Equipe::setNomEquipe(const string& nom) {
    nomEquipe = nom;
}

int Equipe::getNombreJoueur() const {
    return nombreJoueur;
}

void Equipe::setNombreJoueur(int nb) {
    nombreJoueur = nb;
}

string Equipe::getVilleEquipe() const {
    return villeEquipe;
}

void Equipe::setVilleEquipe(const string& ville) {
    villeEquipe = ville;
}

float Equipe::getScore() const {
    return score;
}

void Equipe::setScore(float s) {
    score = s;
}

int Equipe::getClassement() const {
    return classement;
}

void Equipe::setClassement(int c) {
    classement = c;
}

bool Equipe::getExisteDansTournoi() const { return exsisteintournement; }
void Equipe::setExisteDansTournoi(bool existe) { exsisteintournement = existe; }

void Equipe::consultationEquipe() const {
    cout << "ID Equipe: " << idEquipe << endl;
    cout << "Nom: " << nomEquipe << endl;
    cout << "Nombre de joueurs: " << nombreJoueur << endl;
    cout << "Ville: " << villeEquipe << endl;
    cout << "Score: " << score << endl;
    cout << "Classement: " << classement << endl;
    cout << "is team in the tournament: " << exsisteintournement << endl;
}

Equipe Equipe::rechercheEquipe(const string& critere, const string& valeur) {
    if (critere == "id" && to_string(idEquipe) == valeur) {
        consultationEquipe();
        return *this;
    } else if (critere == "nom" && nomEquipe == valeur) {
        consultationEquipe();
        return *this;
    } else if (critere == "ville" && villeEquipe == valeur) {
        consultationEquipe();
        return *this;
    } else if (critere == "score" && to_string(score) == valeur) {
        consultationEquipe();
        return *this;
    } else if (critere == "classement" && to_string(classement) == valeur) {
        consultationEquipe();
        return *this;
    }
    return {};
}
