#ifndef NOTE_H
#define NOTE_H


#include "timing.h"
#include <QString>
#include <QFile>
using namespace TIME;


enum Statut{attente,cours,terminee};


//////////////////////////////////////////////////////
///Déclaration des classes, utile pour éviter
/// les problèmes du genre "Manager n'est pas un nom"
/// de classe etc....
///
///
///
class Manager;
class IteratorNote;
class IteratorRel;

//////////////////////////////////////////////////////
/// \brief The Note class
///
///
///
///


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
    QString getTitre()const {return titre;}
    int getId()const {return id;}
    Date getCreat()const {return d_creat;}
    Date getDModif()const {return d_modif;}
    void setTitle(const QString& t) {titre = t;}
};


//////////////////////////////////////////////////////
/// \brief The Tache class
///
///
///

class Tache : public Note{
  private:
    QString action;
    int priorite;
    Date echeance;
    Statut statut;
  public:
    Tache(const int& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& act, int p, const Date& d_end, Statut st):
      Note(id,titre,date_cr,date_l),action(act),priorite(p),echeance(d_end),statut(st){}
    QString getAction() const{return action;}
    int getPriority() const{return priorite;}
    Date getDate_echeance() const{return echeance;}
    Statut getStatut() const{return statut;}
    void setAction(const QString& a){ action = a;}
    void setPriorite(const int p){priorite = p;}
    void setDate(const Date& d){echeance = d;}
    void setStatut(Statut s){statut = s;}
};


//////////////////////////////////////////////////////
/// \brief The Article class
///
///
///
///
///


class Article : public Note{
  private:
    QString texte;
  public:
    Article(const int& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& txt):
      Note(id,titre,date_cr,date_l),texte(txt){}
    QString getTexte()const{return texte;}
    void setText(const QString& txt) {texte = txt;}
};


//////////////////////////////////////////////////////
/// \brief The Multimedia class
///
///
///
///


class Multimedia : public Note{
  private:
    QString desc;
    QFile fichier;
  public:
    QString getDesc()const{return desc;}
};


//////////////////////////////////////////////////////
/// \brief The Relation class
///
///
///
///

class Relation{
  private:
    std::string titre;
    std::string description;
    Note* couple[2]; // Pour ça Note doit ne pas être abstraite
  public:
    Relation(const std::string& s, const std::string& d, Note* n1, Note* n2):
      titre(s),description(d){couple[0] = n1; couple[1]=n2;}
    ~Relation(){delete couple[0];delete couple[1];}
    //creation et tout le bazar
    // (très) probablement implémenter un iterator
};
// placeholder (pour introduire la partie Singleton de Note)


///////////////////////////////////////////////////////
/// \brief The Manager class
///
///
///
///
///

class Manager{
  private:
    Note* tabNotes; //tableau de Notes. Mais Note** ou Note* ?
    Relation* tabRel; //tableau de Relations. //idem.
    unsigned int nbNotes;
    unsigned int nbMaxNotes;
    unsigned int nbRel;
    unsigned int nbMaxRel;
    struct Handler{ //singleton pour le Manager de notes.
      Manager * instance; //pour ce pointeur j'en suis sur c'est bon!
      Handler():instance(nullptr){}
      ~Handler(){delete instance; instance = nullptr;}

    };
  static Handler handlerManager;
  public:
    Manager& getManager();
    void freeManager();
    IteratorNote getItNote();
    IteratorRel getItRel();
};

///////////////////////////////////////
/// \brief The IteratorNote class
///
///
///
///

class IteratorNote //itérateur de notes.
{
public:
  void next();
  void previous();
  Note& currentNote() const;
  bool isDone() const;
private:
  Note* tab; //Note* ou Note** ?
  int nb;
  int i;

  IteratorNote(Note* t,int n):tab(t),nb(n),i(0){}

  friend class Manager; //le manager pourra utiliser l'Itérateur pour notes.
};

////////////////////////////////////
/// \brief The IteratorRel class
///
///
///

class IteratorRel //itérateur de relations.
{
public:
  void next();
  void previous();
  Relation& currentRel() const;
  bool isDone() const;
private:
  Relation* tab; //j'ai un doute sur si c'est Relation* ou Relation**
  int nb;
  int i;

  IteratorRel(Relation* t,int n):tab(t),nb(n),i(0){}

  friend class Manager; //le manager pourra utiliser l'Itérateur pour relations.
};

#endif
