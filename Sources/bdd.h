#ifndef Connexion
#define Connexion
#include "sqlite3.h" //semble marcher comme ça.
#include <iostream>

sqlite3* connexion();
void deconnexion(sqlite3* db);
int afficher(void *inutile, int argc, char **argv, char **nomCol);
void affichetable(sqlite3* db, std::string table);
void insertion(sqlite3* db, std::string table, std::string valeurs);
void creer_t(sqlite3* db, std::string table, std::string champs);

#endif
