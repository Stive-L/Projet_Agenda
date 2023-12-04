//
// Created by Yeto.wrld on 12/3/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef PROJET_AGENDA_CONTACT_H
#define PROJET_AGENDA_CONTACT_H


typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour l'heure
typedef struct {
    int heure;
    int minute;
} Heure;

// Structure pour un rendez-vous
typedef struct {
    Date date;
    Heure heure_debut;
    Heure duree;
    char* objet;
    struct RendezVous* suivant;
} RendezVous;
typedef struct Contact {
    char* nom;
    char* prenom;
} Contact;
typedef struct EntreeAgenda {
    Contact contact;
    RendezVous* listeRendezVous;  // Liste simplement chaînée de rendez-vous
    struct EntreeAgenda* suivant;
} EntreeAgenda;

typedef struct s_d_cellagenda {
    Contact contact;
    RendezVous* listeRendezVous;  // Liste simplement chaînée de rendez-vous
    struct s_d_cellagenda** next;  // Tableau de pointeurs vers la cellule suivante pour chaque niveau
} t_d_cellagenda;

// Structure pour la liste à plusieurs niveaux
typedef struct s_d_listagenda {
    int max_levels;             // Nombre maximum de niveaux dans la liste
    t_d_cellagenda** head;      // Tableau de pointeurs vers la tête de chaque niveau
} t_d_listagenda;
#endif //PROJET_AGENDA_CONTACT_H
