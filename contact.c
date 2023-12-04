//
// Created by Yeto.wrld on 12/3/2023.
//

#include "contact.h"
Contact createContact(const char *nom, const char *prenom) {
    Contact newContact;
    newContact.nom = strdup(nom);
    newContact.prenom = strdup(prenom);
    return newContact;
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
void rechercherContactAvecCompletion(t_d_listagenda* agenda, const char* recherche) {
    // Convertir la recherche en minuscules
    char rechercheMinuscules[256];
    strcpy(rechercheMinuscules, recherche);
    toLowerCase(rechercheMinuscules);

    // Parcourir les contacts et proposer des suggestions
    for (int level = agenda->max_levels - 1; level >= 0; level--) {
        t_d_cellagenda* current = agenda->head[level];
        while (current != NULL) {
            // Convertir le nom en minuscules
            char nomMinuscules[256];
            strcpy(nomMinuscules, current->contact.nom);
            toLowerCase(nomMinuscules);

            // Vérifier si le nom commence par la recherche
            if (strncmp(nomMinuscules, rechercheMinuscules, strlen(rechercheMinuscules)) == 0) {
                printf("Suggestion : %s %s\n", current->contact.nom, current->contact.prenom);
            }

            current = current->next[level];
        }
    }
}
void afficherRendezVousContact(t_d_listagenda* agenda, const char* nom, const char* prenom) {
    // Convertir le nom et le prénom en minuscules
    char nomMinuscules[256];
    strcpy(nomMinuscules, nom);
    toLowerCase(nomMinuscules);

    char prenomMinuscules[256];
    strcpy(prenomMinuscules, prenom);
    toLowerCase(prenomMinuscules);

    // Parcourir les niveaux pour trouver le contact
    for (int level = agenda->max_levels - 1; level >= 0; level--) {
        t_d_cellagenda* current = agenda->head[level];
        while (current != NULL) {
            // Convertir le nom et le prénom du contact en minuscules
            char nomContactMinuscules[256];
            strcpy(nomContactMinuscules, current->contact.nom);
            toLowerCase(nomContactMinuscules);

            char prenomContactMinuscules[256];
            strcpy(prenomContactMinuscules, current->contact.prenom);
            toLowerCase(prenomContactMinuscules);

            // Vérifier si le contact correspond
            if (strcmp(nomContactMinuscules, nomMinuscules) == 0 &&
                strcmp(prenomContactMinuscules, prenomMinuscules) == 0) {
                // Afficher les rendez-vous du contact
                RendezVous* rendezvous = current->listeRendezVous;
                while (rendezvous != NULL) {
                    printf("Date: %02d/%02d/%04d\n", rendezvous->date.jour, rendezvous->date.mois, rendezvous->date.annee);
                    printf("Heure de début: %02d:%02d\n", rendezvous->heure_debut.heure, rendezvous->heure_debut.minute);
                    printf("Durée: %02d:%02d\n", rendezvous->duree.heure, rendezvous->duree.minute);
                    printf("Objet: %s\n", rendezvous->objet);
                    printf("\n");

                    rendezvous = rendezvous->suivant;
                }

                return;  // Finir la recherche une fois les rendez-vous affichés
            }

            current = current->next[level];
        }
    }

    // Si le contact n'est pas trouvé
    printf("Contact non trouvé.\n");
}
void creerEtInsererContact(t_d_listagenda* agenda, const char* nom, const char* prenom) {
    // Créer une nouvelle entrée d'agenda (contact)
    t_d_cellagenda* nouvelleEntree = (t_d_cellagenda*)malloc(sizeof(t_d_cellagenda));
    nouvelleEntree->contact.nom = strdup(nom);
    nouvelleEntree->contact.prenom = strdup(prenom);
    nouvelleEntree->next[0] = NULL;
    nouvelleEntree->next[1] = NULL;
    nouvelleEntree->next[2] = NULL;
    nouvelleEntree->next[3] = NULL;
    // Convertir en minuscules pour la comparaison
    toLowerCase(nouvelleEntree->contact.nom);

    // Insérer au niveau 3
    t_d_cellagenda** teteNiveau3 = &(agenda->head[3]);
    while (*teteNiveau3 != NULL && (nouvelleEntree->contact.nom[0] != (*teteNiveau3)->contact.nom[0])) {
        teteNiveau3 = &((*teteNiveau3)->next[3]);
    }
    nouvelleEntree->next[3] = *teteNiveau3;
    *teteNiveau3 = nouvelleEntree;

    // Insérer au niveau 2
    t_d_cellagenda** teteNiveau2 = &(agenda->head[2]);
    while (*teteNiveau2 != NULL && (nouvelleEntree->contact.nom[1] != (*teteNiveau2)->contact.nom[1])) {
        teteNiveau2 = &((*teteNiveau2)->next[2]);
    }
    nouvelleEntree->next[2] = *teteNiveau2;
    *teteNiveau2 = nouvelleEntree;

    // Insérer au niveau 1
    t_d_cellagenda** teteNiveau1 = &(agenda->head[1]);
    while (*teteNiveau1 != NULL && (nouvelleEntree->contact.nom[2] != (*teteNiveau1)->contact.nom[2])) {
        teteNiveau1 = &((*teteNiveau1)->next[1]);
    }
    nouvelleEntree->next[1] = *teteNiveau1;
    *teteNiveau1 = nouvelleEntree;

    // Insérer au niveau 0
    t_d_cellagenda** teteNiveau0 = &(agenda->head[0]);
    while (*teteNiveau0 != NULL && (nouvelleEntree->contact.nom[3] != (*teteNiveau0)->contact.nom[3])) {
        teteNiveau0 = &((*teteNiveau0)->next[0]);
    }
    nouvelleEntree->next[0] = *teteNiveau0;
    *teteNiveau0 = nouvelleEntree;
}
char *scanString(void) {
    char buffer[100];
    scanf("%99s", buffer);

    // Allouer dynamiquement de la mémoire pour la nouvelle chaîne
    char *result = (char *)malloc(strlen(buffer) + 1);

    // Copier le contenu du buffer dans la nouvelle chaîne
    strcpy(result, buffer);

    return result;
}
g