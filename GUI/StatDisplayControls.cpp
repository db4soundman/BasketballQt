#include "StatDisplayControls.h"

StatDisplayControls::StatDisplayControls(BasketballGame* game) :
    homeStats(game), awayStats(game) {
    addTab(&awayStats, game->getAwayName() + " Stats");
    addTab(&homeStats, game->getHomeName() + " Stats");


}
