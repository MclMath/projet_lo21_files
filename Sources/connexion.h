#ifndef Connexion
#define Connexion
//#include <sqlite3.h>
#include "sqlite3.h" //semble marcher comme ça.

sqlite3* connexion();
void deconnexion(sqlite3* db);

#endif
