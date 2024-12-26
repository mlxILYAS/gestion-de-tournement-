#include "Equipe.h"
#include <iostream>
#include <vector>
#include <algorithm> // pour std::shuffle
#include <random> // pour std::default_random_engine
#include <ctime> // pour std::time

using namespace std;

void startTournement(vector<Equipe>& equipes);

void afficherMenuEquipe() {
    cout << "\n====== GESTION DES EQUIPES ======" << endl;
    cout << "1. Ajouter une equipe" << endl;
    cout << "2. Afficher les equipes" << endl;
    cout << "3. Rechercher une equipe" << endl;
    cout << "4. Démarrer le tournoi" << endl;
    cout << "0. Retour" << endl;
    cout << "Choix: ";
}

void gererEquipes(vector<Equipe>& equipes) {
    int choix;
    do {
        afficherMenuEquipe();
        cin >> choix;
        switch (choix) {
        case 1: {
            int id, nbJoueurs;
            string nom, ville;
            bool existeTournoi;
            cout << "ID de l'équipe: ";
            cin >> id;
            cout << "Nom de l'équipe: ";
            cin.ignore();
            getline(cin, nom);
            cout << "Nombre de joueurs: ";
            cin >> nbJoueurs;
            cout << "Ville: ";
            cin.ignore();
            getline(cin, ville);
            cout << "Est-ce que l'équipe existe dans le tournoi (1 pour Oui, 0 pour Non): ";
            cin >> existeTournoi;
            equipes.emplace_back(id, nom, nbJoueurs, ville, existeTournoi);
            cout << "Équipe ajoutée avec succès!" << endl;
            break;
        }
        case 2: {
            if (equipes.empty()) {
                cout << "Aucune équipe enregistrée." << endl;
            } else {
                for (const auto& equipe : equipes) {
                    equipe.consultationEquipe();
                    cout << "------------------------" << endl;
                }
            }
            break;
        }
        case 3: {
            string critere, valeur;
            cout << "Rechercher par (id/nom/ville/score/classement): ";
            cin >> critere;
            cout << "Entrez la valeur du critère: ";
            cin.ignore();
            getline(cin, valeur);
            bool found = false;
            for (auto& equipe : equipes) {
                if (!equipe.rechercheEquipe(critere, valeur).getNomEquipe().empty()) {
                    found = true;
                }
                cout << "------------------------" << endl;
            }
            if (!found) {
                cout << "Aucune équipe trouvée avec ce critère." << endl;
            }
            break;
        }
        case 4: {
            startTournement(equipes);
            break;
        }
        }
    } while (choix != 0);
}

void startTournement(vector<Equipe>& equipes) {
    vector<Equipe> tournoi;
    for (const auto& equipe : equipes) {
        if (equipe.getExisteDansTournoi()) {
            tournoi.push_back(equipe);
        }
    }

    if (tournoi.size() < 16) {
        cout << "Pas assez d'équipes pour le tournoi (minimum 16 équipes)." << endl;
        return;
    }

    cout << "Début du tournoi avec " << tournoi.size() << " équipes." << endl;

    // Mélanger les équipes
    std::shuffle(tournoi.begin(), tournoi.end(), std::default_random_engine(std::time(0)));

    // Simulation des phases de groupe (16 équipes -> 8 équipes)
    for (int i = 0; i < 8; ++i) {
        cout << "Groupe " << (i + 1) << " : " << tournoi[i*2].getNomEquipe() << " vs " << tournoi[i*2+1].getNomEquipe() << endl;
    }
//shuffe shuffels mabinat elements f vecteur 
    // Phase éliminatoire
    std::vector<Equipe> phaseFinale(tournoi.begin(), tournoi.begin() + 8);
    std::shuffle(phaseFinale.begin(), phaseFinale.end(), std::default_random_engine(std::time(0)));

    cout << "Phase finale :" << endl;
    for (size_t i = 0; i < phaseFinale.size(); i += 2) {
        cout << phaseFinale[i].getNomEquipe() << " vs " << phaseFinale[i+1].getNomEquipe() << endl;
    }
//easter egg a zebi 
    
    // Terminer le tournoi
    while (phaseFinale.size() > 1) {
        std::vector<Equipe> nextRound;
        std::shuffle(phaseFinale.begin(), phaseFinale.end(), std::default_random_engine(std::time(0)));
        for (size_t i = 0; i < phaseFinale.size(); i += 2) {
            cout << phaseFinale[i].getNomEquipe() << " élimine " << phaseFinale[i+1].getNomEquipe() << endl;
            nextRound.push_back(phaseFinale[i]); // Simuler la victoire du premier de chaque paire
        }
        phaseFinale = nextRound;
    }

    cout << "L'équipe gagnante est : " << phaseFinale.front().getNomEquipe() << "!" << endl;
}

int main() {
    int choix;
    vector<Equipe> equipes;

    do {
        cout << "\n====== MENU PRINCIPAL ======" << endl;
        cout << "1. Gérer les équipes" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {
        case 1:
            gererEquipes(equipes);
            break;
        case 0:
            cout << "Au revoir!" << endl;
            break;
        default:
            cout << "Choix invalide, réessayez." << endl;
        }
    } while (choix != 0);

    return 0;
}
