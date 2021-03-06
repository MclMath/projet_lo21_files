#ifndef NOTES_H
#define NOTES_H
#include <QString>
#include <QFile>
#include "timing.h"


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
