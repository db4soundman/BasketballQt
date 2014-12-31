#include "InGameXml.h"

InGameXml::InGameXml(BasketballTeam* pAway, BasketballTeam* pHome)
{
    awayTeam = pAway;
    homeTeam = pHome;
    currPlayer = NULL;
    teamStats = false;
    skipPlayer = false;
}

bool InGameXml::startElement(const QString& namespaceURI, const QString& localName,
                             const QString& qName, const QXmlAttributes& atts)
{
    if (qName == "team" && atts.value("vh") == "V") {
        visitingTeam = true;
    }
    else if (qName == "team" && atts.value("vh") == "H") {
        visitingTeam = false;
    }

    else if (qName == "totals") {
        teamStats = true;
    }

    else if (qName == "stats" && teamStats) {
        currPlayer = visitingTeam ? awayTeam->getTeamPlayer() : homeTeam->getTeamPlayer();
        currPlayer->setFgm(atts.value("fgm").toInt());
        currPlayer->setFga(atts.value("fga").toInt());
        currPlayer->setFgm3(atts.value("fgm3").toInt());
        currPlayer->setFga3(atts.value("fga3").toInt());
        currPlayer->setFtm(atts.value("ftm").toInt());
        currPlayer->setFta(atts.value("fta").toInt());
        currPlayer->setPts(atts.value("tp").toInt());
        currPlayer->setBlk(atts.value("blk").toInt());
        currPlayer->setStl(atts.value("stl").toInt());
        currPlayer->setAst(atts.value("ast").toInt());
        currPlayer->setOreb(atts.value("oreb").toInt());
        currPlayer->setDreb(atts.value("dreb").toInt());
        currPlayer->setTreb(atts.value("treb").toInt());
        //currPlayer->setFouls(atts.value("pf").toInt());
        currPlayer->setTo(atts.value("to").toInt());
    }
    else if (qName == "special" && teamStats) {
        if (visitingTeam) {
            awayTeam->setPtsTo(atts.value("pts_to").toInt());
            awayTeam->setPtsCh2(atts.value("pts_ch2").toInt());
            awayTeam->setPtsBench(atts.value("pts_bench").toInt());
            awayTeam->setTies(atts.value("ties").toInt());
            awayTeam->setLeads(atts.value("leads").toInt());
            awayTeam->setPtsFb(atts.value("pts_fastb").toInt());
            awayTeam->setPtsPaint(atts.value("pts_paint").toInt());
            //awayTeam->setLargestLead(atts.value("large_lead").toInt());
        }
        else {
            homeTeam->setPtsTo(atts.value("pts_to").toInt());
            homeTeam->setPtsCh2(atts.value("pts_ch2").toInt());
            homeTeam->setPtsBench(atts.value("pts_bench").toInt());
            homeTeam->setTies(atts.value("ties").toInt());
            homeTeam->setLeads(atts.value("leads").toInt());
            homeTeam->setPtsFb(atts.value("pts_fastb").toInt());
            homeTeam->setPtsPaint(atts.value("pts_paint").toInt());
            //homeTeam->setLargestLead(atts.value("large_lead").toInt());
        }
    }

    else if (qName == "player" && (atts.value("uni") != "TM" && atts.value("gp") == "1" )) {
        currPlayer = visitingTeam ? awayTeam->getPlayerByNumber(atts.value("uni")) :
                                    homeTeam->getPlayerByNumber(atts.value("uni"));

    }
    else if (qName == "player" && (atts.value("uni") == "TM" || atts.value("gp") == "0" )) {
        skipPlayer = true;
    }

    else if (qName == "stats" && !skipPlayer && !teamStats) {
        currPlayer->setFgm(atts.value("fgm").toInt());
        currPlayer->setFga(atts.value("fga").toInt());
        currPlayer->setFgm3(atts.value("fgm3").toInt());
        currPlayer->setFga3(atts.value("fga3").toInt());
        currPlayer->setFtm(atts.value("ftm").toInt());
        currPlayer->setFta(atts.value("fta").toInt());
        currPlayer->setPts(atts.value("tp").toInt());
        currPlayer->setBlk(atts.value("blk").toInt());
        currPlayer->setStl(atts.value("stl").toInt());
        currPlayer->setAst(atts.value("ast").toInt());
        currPlayer->setOreb(atts.value("oreb").toInt());
        currPlayer->setDreb(atts.value("dreb").toInt());
        currPlayer->setTreb(atts.value("treb").toInt());
        currPlayer->setFouls(atts.value("pf").toInt());
        currPlayer->setTo(atts.value("to").toInt());
    }

    return true;
}

bool InGameXml::endElement(const QString& namespaceURI, const QString& localName, const QString& qName)
{
    if (qName == "totals") {
        teamStats = false;
        currPlayer = NULL;
    }
    else if (qName == "team") {
        visitingTeam = false;
    }

    else if (qName == "player") {
        skipPlayer = false;
        currPlayer = NULL;
    }

    return true;
}

bool InGameXml::characters(const QString& str)
{
    return true;
}

bool InGameXml::fatalError(const QXmlParseException& exception)
{
    return false;
}
