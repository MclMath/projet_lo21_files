#include <iostream>
#include <sqlite3.h>
#include <sstream>

using namespace std;

static int callback(void *data, int argc, char **argv, char **nomCol){
   int i;
   for(i=0; i<argc; i++){
      cout<<nomCol[i]<<" = "<<argv[i] <<"\n";
   }
   cout<<"\n";
   return 0;
}

int main(int argc, char const *argv[]) {
  sqlite3 *db;
  string query;
  char* erreur=0;
  int rc;

  string table;
  cout<<"Quelle table ? ";
  cin>>table;


  sqlite3_open("/home/cedric/Documents/UTC/GI01/LO21/Projet//BDD/LO21.db", &db);
  query="CREATE TABLE "+table+" (int age)";
  rc=sqlite3_exec(db, query.c_str(), NULL, NULL, &erreur); // pas NULL partout idéalement
  if(rc!=SQLITE_OK)
    cout<<erreur<<"\n\n";

  int i;
  cout<<"Insertion ? ";
  cin>>i;
  query="INSERT INTO "+table+" VALUES(" + to_string(i) + ")";
  sqlite3_exec(db, query.c_str(), NULL, NULL, NULL);

  cout<<"contenu de "<<table<<" :\n\n";
  query="SELECT * FROM "+table;
  sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

  sqlite3_close(db);

  return 0;
}