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
    };

private:
};

int main(int argc, char *argv[]) {
    RunBot(argc, argv, new ExampleBot(), sc2::Race::Terran);
}