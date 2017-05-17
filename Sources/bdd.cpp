#include "bdd.h"
#include "path.h"

sqlite3* connexion(){
  sqlite3* db;
  if(SQLITE_OK!=sqlite3_open(DB_PATH, &db))
    std::cout<<"Erreur à la connexion\n";
  return db;
}

void deconnexion(sqlite3* db){
  if(SQLITE_OK!=sqlite3_close(db))
    std::cout<<"Erreur à la déconnexion\n";
}

int afficher(void *inutile, int argc, char **argv, char **nomCol){
   int i;
   for(i=0; i<argc; i++){
      std::cout<<nomCol[i]<<" = "<<argv[i] <<"\n";
   }
   std::cout<<"\n";
   return 0;
}

void affichetable(sqlite3* db, std::string table){
  std::string query="SELECT * FROM "+table;
  std::cout<<"contenu de "<<table<<" :\n\n";
  if(SQLITE_OK!=sqlite3_exec(db, query.c_str(), afficher, NULL, NULL))
    std::cout<<"Erreur à l'affichage de :\n"<<table<<"\n";
  // NULL en premier argument d'afficher et erreur écrite dans NULL (osef)
}

// virgules entre les valeurs
void insertion(sqlite3* db, std::string table, std::string valeurs){
  std::string query="INSERT INTO "+table+" VALUES(" + valeurs + ")";
  if(SQLITE_OK!=sqlite3_exec(db, query.c_str(), NULL, NULL, NULL))
    std::cout<<"Erreur à l'insertion des valeurs :\n"<<valeurs<<"\n";
}

// virgules entre les champs
void creer_t(sqlite3* db, std::string table, std::string champs){
  std::string query="CREATE TABLE "+table+" (" + champs + ")";
  if(SQLITE_OK!=sqlite3_exec(db, query.c_str(), NULL, NULL, NULL))
    std::cout<<"Erreur à la création de la table :\n"<<table<<"\n"<<query<<"\n";
}
