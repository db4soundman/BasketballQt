#ifndef SEASONXMLHANDLER_H
#define SEASONXMLHANDLER_H

#include <QXmlDefaultHandler>
#include "BasketballTeam.h"

class SeasonXMLHandler : public QXmlDefaultHandler {
public:
    SeasonXMLHandler(BasketballTeam* t);

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);

private:
    BasketballTeam* team;
    bool inPlayer, inTotals, inOpponent, foundGoalie;
    BasketballPlayer* currPlayer;

    QString correctName(QString name);
};

#endif // SEASONXMLHANDLER_H
