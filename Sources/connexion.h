#ifndef Connexion
#define Connexion
#include <sqlite3.h>

sqlite3* connexion();
void deconnexion(sqlite3* db);

#endif
