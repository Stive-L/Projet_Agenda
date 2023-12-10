//
// Created by Yeto.wrld on 12/3/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef PROJET_AGENDA_CONTACT_H
#define PROJET_AGENDA_CONTACT_H

char *scanString(void);

typedef struct Contact {
    char* nom;
    char* prenom;
} Contact;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour l'heure
typedef struct {
    int heure;
    int minute;
} Temps;

// Structure pour un rendez-vous
typedef struct RendezVous {
    Date date;
    Temps heure_debut;
    Temps duree;
    char* objet;
    struct RendezVous* suivant;
} RendezVous;


typedef struct rdv_list {
    RendezVous *tete;
}rdv_list;


typedef struct EntreeAgenda {
    Contact contact;
    rdv_list  listeRendezVous;  // Liste simplement chaînée de rendez-vous
    struct s_d_cell **next;
} Agenda_cell, *p_agenda_cell;



typedef struct s_d_listagenda {  // List à niveaux qui stock les entrees d'agenda
    int max_levels;             // Nombre maximum de niveaux dans la liste
    Agenda_cell ** head;      // Tableau de pointeurs vers la tête de chaque niveau
} s_d_listagenda;
int comparerNiveau(const char* , const char* , int );
void insererCellule(s_d_listagenda*, p_agenda_cell );
void creerEtInsererContact(s_d_listagenda* , const char* , const char* );
#endif //PROJET_AGENDA_CONTACT_H
