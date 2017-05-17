#ifndef NOTE_H
#define NOTE_H


#include "timing.h"
#include <QString>
#include <QFile>

enum Statut{attente,cours,terminee};

class Note{
  protected:
    int id;
    QString titre;
    Date d_creat;
    Date d_modif;

    // seul le Manager peut créer des Notes :
    friend class Manager;
    // constructeurs et destructeurs ici pour que le Manager gère

  public:
    Note(const int& id,const QString& titre, const Date& date_cr, const Date& date_end):
      id(id),titre(titre),d_creat(date_cr),d_modif(date_end){}
    QString getTitre()const{return titre;}
    int getId()const{return id;}
    Date getCreat()const{return d_creat;}
    Date getDModif()const{return d_modif;}
    void setTitle(const QString& t);
};

class Tache : public Note{
  private:
    QString action;
    int priorite;
    Date echeance;
    Statut statut;
  public:
    Tache(const int& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& act, int p, const Date& d_end, Statut st):
      Note(id,titre,date_cr,date_l),action(act),priorite(p),echeance(d_end),statut(st){};
    QString getAction() const{return action;};
    int getPriority() const{return priorite;};
    Date getDate_echeance() const{return echeance;};
    Statut getStatut() const{return statut;};
};

class Article : public Note{
  private:
    QString texte;
  public:
    Article(const int& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& txt):
      Note(id,titre,date_cr,date_l),texte(txt){};
    QString getTexte()const{return texte;};
    void setText(const QString& txt);
};

class Multimedia : public Note{
  private:
    QString desc;
    QFile fichier;
  public:
    QString getDesc()const{return desc;};
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
