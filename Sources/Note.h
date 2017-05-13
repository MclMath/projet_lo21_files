#include <string>

enum Statut{attente,cours,terminee};
enum Fichier{audio, video};

class Date{
  private:
    int jour;
    int mois;
    int annee;
  public:
    int getJour(){return jour;};
    int getMois(){return mois;};
    int getAnnee(){return annee;};
};

class Note{
  private:
    std::string id;
    std::string titre;
    Date d_creat;
    Date d_modif;

    // classe abstraite :
    virtual void abstraite()=0;

    // seul le Manager peut créer des Notes :
    friend class Manager;
    // inutile de mettre les constructeurs/destructeurs car la classe est virtuelle
    // pure (pas instanciables de toute façon).
    // On les mettra dans les classes filles.
  public:
    std::string getTitre(){return titre;};
    std::string getId(){return id;};
    Date getCreat(){return d_creat;};
    Date getModif(){return d_modif;};
};

class Tache : public Note{
  private:
    std::string action;
    int priorite;
    Date echeance;
    Statut statut;
  public:
    std::string getAction(){return action;};
    int getPriorite(){return priorite;};
    Date getEcheance(){return echeance;};
    Statut getStatut(){return statut;};
};

class Article : public Note{
  private:
    std::string texte;
  public:
    std::string getTexte(){return texte;};
};

class Multimedia : public Note{
  private:
    std::string desc;
    Fichier fichier;
  public:
    std::string getDesc(){return desc;};
    Fichier getFichier(){return fichier;};
};

// placeholder (pour introduire la partie Singleton de Note)
class Manager{
  private:
  public:
};
