#include <iostream>

#include "Framework.hpp"
#include "ResourceManager.hpp"

int main()
{
    Framework frmwrk;
    frmwrk.ChangeState(Framework::gameStates::MAINMENU);

    frmwrk.run();

    return 0;
}
