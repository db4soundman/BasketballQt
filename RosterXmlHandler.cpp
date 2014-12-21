#include "RosterXmlHandler.h"

RosterXmlHandler::RosterXmlHandler(BasketballGame* g) {
    game = g;
    skipPlayer = false;
    currPlayer = NULL;
}

bool RosterXmlHandler::startElement(const QString& namespaceURI,
                                    const QString& localName,
                                    const QString& qName,
                                    const QXmlAttributes& atts) {
    if (qName == "team") {
        visitingTeam = atts.value("vh") == "V";
    }
    if (qName == "player" && atts.value("uni") != "TM") {
        currPlayer = new BasketballPlayer();
        currPlayer->setName(atts.value("name"));
        currPlayer->setUni(atts.value("uni"));
        skipPlayer = false;
    }
    else if(qName == "player" && atts.value("uni") == "TM") {
        skipPlayer = true;
    }

    return true;
}

bool RosterXmlHandler::endElement(const QString& namespaceURI, const QString& localName, const QString& qName) {
    if (qName == "player" && !skipPlayer) {
        if (visitingTeam) {
            game->getAwayTeam()->addPlayer(currPlayer);
        }
        else {
            game->getHomeTeam()->addPlayer(currPlayer);
        }
    }

    else if (qName == "team") {
        if (visitingTeam) {
            BasketballPlayer* team = new BasketballPlayer();
            team->setName(game->getAwayName());
            game->getAwayTeam()->addPlayer(team);
            visitingTeam = false;
        }
        else {
            BasketballPlayer* team = new BasketballPlayer();
            team->setName(game->getHomeName());
            game->getHomeTeam()->addPlayer(team);
            visitingTeam = false;
        }

    }

    return true;
}

bool RosterXmlHandler::characters(const QString& str)
{
    return true;
}

bool RosterXmlHandler::fatalError(const QXmlParseException& exception)
{
    return false;
}
