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

    // seul le Manager peut créer des Notes :
    friend class Manager;
    // constructeurs et destructeurs ici pour que le Manager gère

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

class Relation{
  private:
    std::string titre;
    std::string description;
    Note* couple[2]; // Pour ça Note doit ne pas être abstraite
  public:
    //creation et tout le bazar
    // (très) probablement implémenter un iterator
};

// placeholder (pour introduire la partie Singleton de Note)
class Manager{
  private:
  public:
};
