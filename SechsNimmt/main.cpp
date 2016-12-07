#include <iostream>

#include "Framework.hpp"
#include "ResourceManager.hpp"

int main()
{
    Framework frmwrk;
    frmwrk.ChangeState(Framework::gameStates::GAMESTART);

    frmwrk.run();

    return 0;
}
