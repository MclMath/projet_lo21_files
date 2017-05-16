#ifndef N
#define N


#include <timing.h>
#include <QString>
#include <QFile>

enum Statut{attente,cours,terminee};

class Note{
  protected:
    QString id;
    QString titre;
    Date d_creat;
    Date d_modif;

    // seul le Manager peut créer des Notes :
    friend class Manager;
    // constructeurs et destructeurs ici pour que le Manager gère

  public:
    Note(const QString& id,const QString& titre, const Date& date_cr, const Date& date_end):identifier(id),title(titre),date_creation(date_cr),date_last_modif(date_l){}
    QString getTitre()const{return title;}
    QString getId()const{return identifier;}
    Date getCreat()const{return date_creation;}
    Date getDModif()const{return date_last_modif;}
    void setTitle(const QString& t);
};

class Tache : public Note{
  private:
    QString action;
    int priorite;
    Date echeance;
    Statut statut;
  public:
    Tache(const QString& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& act, int prior, const Date& d_end, type_Status st):Note(id,titre,date_cr,date_l),action(act),priority(prior),date_echeance(d_end),status(st){};
    QString getAction() const{return action;};
    int getPriority() const{return priority;};
    Date getDate_echeance() const{return date_echeance;};
    QString getStatus() const{return status;};
};

class Article : public Note{
  private:
    QString texte;
  public:
    Article(const QString& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& txt):Note(id,titre,date_cr,date_l),text(txt){};
    QString getTexte()const{return texte;};
    void setText(const QString& txt);
};

class Multimedia : public Note{
  private:
    QString desc;
    QFile fichier;
  public:
    QString getDesc(){return desc;};
    QFile getFichier(){return fichier;};
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

#endif
