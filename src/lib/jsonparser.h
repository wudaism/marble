//
// C++ Interface: jsonparser
//
// Description:
//
//
// Author:  <Shashank Singh>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QtScript/QtScript>
#include <QList>
#include <QObject>
#include <QDebug>
#include <QtScript/QScriptValue>
#include <QtScript/QScriptEngine>
/**
This is a generic class built up for parsing Json that is JavaScript Object Notification
FIXME: the class presently has no sanity checking mechanism,, it just can't check wether the input given to it is only JSON or Javascript ; a point of potential breach for the software.
sanity checking would include :
(1)regex matching for following characters "" {} , [a-zA-Z] everything else should be discarded (but some unicode names could pose problem)
(2)checking for javascript constructs and eliminating them.
(3)some other plan that i have yet not thought upon :)
    @author Shashank Singh
*/
struct panoramioDataStructure
{
    long int count;//total number of photographs will be stored in this int
    long int photo_id ; //id of each photograph
    QString photo_title; //title of each photograph
    QString photo_url; //url of each photograph
    long int longitude;
    long int latitude;
    int width;
    int height;
    QString upload_date;
    long int owner_id;
    QString owner_name;
    QString owner_url; //Url of the User Uplaoded
};

class jsonParser :public QObject
{
 public:
   jsonParser();

   ~jsonParser();

   panoramioDataStructure parseObjectOnPosition ( const QString &content ,int requiredObjectPosition );//for parsing single object

   QList<panoramioDataStructure> parseAllObjects ( const QString &content,int numberOfObjects );//for parsing a list objects
    
 private:
    QList <panoramioDataStructure> parsedJsonOutput;

    panoramioDataStructure dataStorage;

    QScriptEngine myEngine;

};


#endif
