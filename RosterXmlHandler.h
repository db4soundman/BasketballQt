#ifndef GAMEXMLHANDLER_H
#define GAMEXMLHANDLER_H

#include <QXmlDefaultHandler>
#include "BasketballGame.h"

class RosterXmlHandler : public QXmlDefaultHandler
{
public:
    RosterXmlHandler(BasketballGame* g);
    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);

private:
    BasketballGame* game;
    BasketballPlayer* currPlayer;
    bool visitingTeam, skipPlayer;
};


#endif // GAMEXMLHANDLER_H
