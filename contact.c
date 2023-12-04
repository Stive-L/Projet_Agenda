//
// Created by Yeto.wrld on 11/25/2023.
//

#include "contact.h"

char *scanString(void) {
    char nom_prenom[100];
    fgets(nom_prenom,100,stdin);
    nom_prenom[strcspn(nom_prenom, "\n")] = '\0'; // On enleve le caractère retour à la ligne lors de l'utilisation de fgets
    char *chaine = malloc(strlen(nom_prenom));
    strncpy(chaine, nom_prenom, strlen(nom_prenom) + 1); // Copie de nom_prenom à chaine
    return chaine;
}
