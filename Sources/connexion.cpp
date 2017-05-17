#include "connexion.h"

sqlite3* connexion(){
  sqlite3* db;
  sqlite3_open("/home/cedric/Documents/UTC/GI01/LO21/Projet//BDD/LO21.db", &db);
  return db;
}

void deconnexion(sqlite3* db){
  sqlite3_close(db);
}
