#include "StatDisplayControls.h"

StatDisplayControls::StatDisplayControls(BasketballGame* game) :
    homeStats(true, game), awayStats(false, game) {
    addTab(&awayStats, game->getAwayName() + " Stats");
    addTab(&homeStats, game->getHomeName() + " Stats");


}
