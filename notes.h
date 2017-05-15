#ifndef NOTES_H
#define NOTES_H
#include <QString>
#include <QFile>
#include "timing.h"
class Date {
public:
    //! Constructeur à partir d'un jour, mois, année
    /*! \param j jour avec 1<=j<=31
                \param m mois avec 1<=m<=12
                \param a année avec a>=0
                */
    Date(unsigned int short j=1, unsigned int short m=1, unsigned int a=0):jour(1),mois(1),annee(0){ setDate(j,m,a); }
    // méthodes
    unsigned short int  getJour() const { return jour; } //<! Retourne le jour de la date
    unsigned short int  getMois() const { return mois; } //<! Retourne le mois de la date
    unsigned int getAnnee() const { return annee; } //<! Retourne l'année de la date
    void setDate(unsigned short int j, unsigned short int m, unsigned int a); //!< initialisation de la date
    void afficher(std::ostream& f=std::cout) const; //!< affiche le date sous le format JJ/MM/AAAA
    bool operator==(const Date& d) const; //<! d1==d2 retourne vrai si les deux dates sont égales
    bool operator<(const Date& d) const; //<! Compare deux dates dans le temps : d1<d2 retourne true si d1 est avant d2
    int operator-(const Date& d) const; //<! Retourne le nombre de jours séparant les deux dates
    Date demain() const; //<! Retourne la date du lendemain
    Date operator+(unsigned int nb) const; //<!Retourne la date de dans nb jours
private:
    // attributs
    unsigned short int jour; // jour entre 1 et 31
    unsigned short int mois; // mois entre 1 et 12
    unsigned int annee;
};

namespace CLASSPROJ {

class Note{
protected:
    QString identifier;
    QString title;
    Date date_creation;
    Date date_last_modif;
public:
    Note(const QString& id,const QString& titre, const Date& date_cr, const Date& date_end):identifier(id),title(titre),date_creation(date_cr),date_last_modif(date_l){}
    QString getTitre() const{return title;}
    QString getID() const{return identifier;}
    Date getDate_creation() const{return date_creation;}
    Date getDate_last_modif() const{return date_last_modif;}
    void setTitle(const QString& t);

};

class Article : public Note {

    QString text;
public:
    Article(const QString& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& txt):Note(id,titre,date_cr,date_l),text(txt){}
    QString getText() const { return text; }

    void setText(const QString& txt);
};
class Tache : public Note{
    QString action;
    int priority;
    Date date_echeance;
    QString status;
public:
    Tache(const QString& id,const QString& titre, const Date& date_cr, const Date& date_l, const QString& act, int prior, const Date& d_end, type_Status st):Note(id,titre,date_cr,date_l),action(act),priority(prior),date_echeance(d_end),status(st){}
    QString getAction() const{return action;}
    int getPriority() const{return priority;}
    Date getDate_echeance() const{return date_echeance;}
    QString getStatus() const{return status;}

};


class Multimedia : public Note
{
    QString description;
    QFile file;
public:

    QString getDescription();
    QFile getFile();
};
}
#endif // NOTES_H
