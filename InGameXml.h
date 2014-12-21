#ifndef INGAMEXML_H
#define INGAMEXML_H

#include <QXmlDefaultHandler>
#include "BasketballTeam.h"

class InGameXml : public QXmlDefaultHandler
{
public:
    InGameXml(BasketballTeam* pAway, BasketballTeam* pHome);

    bool startElement(const QString &namespaceURI, const QString &localName,
                      const QString &qName, const QXmlAttributes &atts);
    bool endElement(const QString &namespaceURI, const QString &localName,
                    const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);

private:
    BasketballTeam *awayTeam, *homeTeam;
    BasketballPlayer* currPlayer;
    bool visitingTeam, skipPlayer, teamStats;

};

#endif // INGAMEXML_H
