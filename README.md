# Projet de Gestion d'Agenda

## Description

Ce projet est une application en mode console permettant de gérer un agenda de manière simple et efficace, en s'appuyant notamment sur les listes chaînées. Il permet d'ajouter, consulter et organiser des contacts et des rendez-vous facilement.

## Fonctionnalités

- **Gestion des contacts et rendez-vous** :
  - Ajouter, afficher et supprimer des contacts
  - Ajouter, consulter et supprimer des rendez-vous
  - Recherche intuitive avec complétion automatique
- **Optimisation des recherches** pour un accès rapide aux données
- **Sauvegarde et chargement** des données pour conserver l'agenda

## Structure du Projet

### 1. Modules principaux

- **Gestion des contacts et des listes**
  - `cell.h` / `cell.c` : Gestion des éléments de la liste
  - `list.h` / `list.c` : Organisation et tri des contacts
- **Gestion de l'agenda**
  - `contact.h` / `contact.c` : Ajout et suppression des contacts et rendez-vous
  - `timer.h` / `timer.c` : Outils de mesure des performances

### 2. Fichiers source

- **`main.c`** : Point d'entrée du programme
- **`contact.c`** : Gestion des contacts et des rendez-vous
- **`list.c`** : Gestion de la liste des contacts
- **`timer.c`** : Analyse des performances

## Commandes disponibles

| Commande | Action |
| -------- | -------------------------------- |
| `1`      | Rechercher un contact |
| `2`      | Ajouter un contact |
| `3`      | Ajouter un rendez-vous |
| `4`      | Supprimer un rendez-vous |
| `5`      | Quitter le programme |
| `6`      | Afficher les commandes disponibles |

## Comparaison des performances

L’application permet d’évaluer la rapidité d’accès aux contacts et rendez-vous en comparant différentes méthodes de recherche. Des tests sont effectués sur de grandes quantités de données pour mesurer l’efficacité.
