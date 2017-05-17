#include <iostream>
#include <sstream>
#include "bdd.h"
#include "Note.h"

using namespace std;
int main() {
  sqlite3* db;
  db=connexion();
  std::string valeurs, champs;

  champs="age integer";
  creer_t(db, "Entiers", champs);

  valeurs="77";
  insertion(db, "Entiers", valeurs);
  valeurs="88";
  insertion(db, "Entiers", valeurs);


  affichetable(db, "Entiers");


  deconnexion(db);
  return 0;
}
