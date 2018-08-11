#include "StdAfx.h"
#include "UIPanelsClassFactory.h"
#include "game_base.h"
#include "UITeamPanels.h"

UIPanelsClassFactory::UIPanelsClassFactory() {}
UIPanelsClassFactory::~UIPanelsClassFactory() {}
UITeamState* UIPanelsClassFactory::CreateTeamPanel(shared_str const& teamName, UITeamPanels* teamPanels)
{
    //под кейсы потом
    if (teamName == "greenteam")
    {
        return new UITeamState(etGreenTeam, teamPanels);
    }
    else if (teamName == "blueteam")
    {
        return new UITeamState(etBlueTeam, teamPanels);
    }
    else if (teamName == "spectatorsteam")
    {
        return new UITeamState(etSpectatorsTeam, teamPanels); 
    }
    //---------m4d 
    else if (teamName == "yellowteam")
    {
        return new UITeamState(etYellowTeam, teamPanels);
    }
    else if (teamName == "blackteam")
    {
        return new UITeamState(etBlackTeam, teamPanels);
    }
    else if (teamName == "lightblueteam")
    {
        return new UITeamState(etLightBlueTeam, teamPanels);
    }
    else if (teamName == "redteam")
    {
        return new UITeamState(etRedTeam, teamPanels);
    }
    else if (teamName == "brownteam")
    {
        return new UITeamState(etBrownTeam, teamPanels);
    }
    else if (teamName == "darkpinkteam")
    {
        return new UITeamState(etDarkPinkTeam, teamPanels);
    }
    else if (teamName == "darkgreenteam")
    {
        return new UITeamState(etDarkGreenTeam, teamPanels);
    }

    else if (teamName == "greenteam_pending")
    {
        return new UITeamState(etGreenTeam, teamPanels);
    }
    else if (teamName == "blueteam_pending")
    {
        return new UITeamState(etBlueTeam, teamPanels);
    }
    //---------------m4d
    else if (teamName == "yellowteam_pending")
    {
        return new UITeamState(etYellowTeam, teamPanels);
    }
    else if (teamName == "blackteam_pending")
    {
        return new UITeamState(etBlackTeam, teamPanels);
    }
    else if (teamName == "lightblueteam_pending")
    {
        return new UITeamState(etLightBlueTeam, teamPanels);
    }
    else if (teamName == "redteam_pending")
    {
        return new UITeamState(etRedTeam, teamPanels);
    }
    else if (teamName == "brownteam_pending")
    {
        return new UITeamState(etBrownTeam, teamPanels);
    }
    else if (teamName == "darkpinkteam_pending")
    {
        return new UITeamState(etDarkPinkTeam, teamPanels);
    }
    else if (teamName == "darkgreenteam_pending")
    {
        return new UITeamState(etDarkGreenTeam, teamPanels);
    }
    return NULL;
}
