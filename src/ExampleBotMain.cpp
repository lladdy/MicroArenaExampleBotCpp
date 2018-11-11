#include <iostream>
#include "sc2api/sc2_api.h"
#include "sc2api/sc2_args.h"
#include "sc2lib/sc2_lib.h"
#include "sc2utils/sc2_manage_process.h"
#include "sc2utils/sc2_arg_parser.h"

#include "LadderInterface.h"

class ExampleBot : public sc2::Agent {
public:
    virtual void OnGameStart() final {
        // do setup here...
    };

    virtual void OnStep() final {
        // play game here...

        attack();
    };

private:

    void attack() {
        const sc2::ObservationInterface *observation = Observation();
        sc2::Point2D playableArea = getPlayableArea(observation);
        const sc2::Units units = observation->GetUnits(sc2::Unit::Alliance::Self);
        sc2::Point2D target_pos;
        for (const auto &unit : units) {
            if (unit->orders.size() == 0) { // if they have no current orders, attack across map
                Actions()->UnitCommand(
                        unit,
                        sc2::ABILITY_ID::ATTACK,
                        getAcrossMapAttackPoint(unit, playableArea)
                );
            }
        }
    }

    sc2::Point2D getPlayableArea(const sc2::ObservationInterface *observation) {
        auto game_info_ = observation->GetGameInfo();
        return game_info_.playable_max - game_info_.playable_min;
    }

    sc2::Point2D getAcrossMapAttackPoint(const sc2::Unit *unit, const sc2::Point2D playableArea) {
        return playableArea - unit->pos;
    }
};

int main(int argc, char *argv[]) {
    RunBot(argc, argv, new ExampleBot(), sc2::Race::Terran);
}