#include "stdafx.h"
#include "UIGameTDM.h"

#include "game_cl_base.h"

#include "game_cl_TeamDeathmatch.h"

#include "ui/TeamInfo.h"

#include "Common/object_broker.h"

#include "UITeamPanels.h"
#include "ui/UIMoneyIndicator.h"
#include "ui/UIRankIndicator.h"

#define MSGS_OFFS 510
//#define TEAM_PANELS_TDM_XML_NAME "ui_team_panels_tdm.xml"
#define TEAM_PANELS_DM_XML_NAME "ui_team_panels_dm.xml"

//--------------------------------------------------------------------m4d_!
CUIGameTDM::CUIGameTDM() : m_game(NULL) {}
void CUIGameTDM::SetClGame(game_cl_GameState* g)
{
    inherited::SetClGame(g);
    m_game = smart_cast<game_cl_TeamDeathmatch*>(g);
    R_ASSERT(m_game);
}

void CUIGameTDM::Init(int stage)
{
    if (stage == 0)
    { // shared
        m_pUITeamSelectWnd = new CUISpawnWnd();

        m_team1_icon = new CUIStatic();
        m_team2_icon = new CUIStatic();
        m_team3_icon = new CUIStatic();
        m_team4_icon = new CUIStatic();
        m_team5_icon = new CUIStatic();
        m_team6_icon = new CUIStatic();
        m_team7_icon = new CUIStatic();
        m_team8_icon = new CUIStatic();
        m_team9_icon = new CUIStatic();

        m_team1_score = new CUITextWnd();
        m_team1_score->SetAutoDelete(true);

        m_team2_score = new CUITextWnd();
        m_team2_score->SetAutoDelete(true);

        m_team3_score = new CUITextWnd();
        m_team3_score->SetAutoDelete(true);

        m_team4_score = new CUITextWnd();
        m_team4_score->SetAutoDelete(true);

        m_team5_score = new CUITextWnd();
        m_team5_score->SetAutoDelete(true);

        m_team6_score = new CUITextWnd();
        m_team6_score->SetAutoDelete(true);

        m_team7_score = new CUITextWnd();
        m_team7_score->SetAutoDelete(true);

        m_team8_score = new CUITextWnd();
        m_team8_score->SetAutoDelete(true);

        m_team9_score = new CUITextWnd();
        m_team9_score->SetAutoDelete(true);

        m_buy_msg_caption = new CUITextWnd();
        m_buy_msg_caption->SetAutoDelete(true);

        inherited::Init(stage);
        CUIXmlInit::InitTextWnd(*MsgConfig, "mp_tdm_buy", 0, m_buy_msg_caption);
    }
    if (stage == 1)
    { // unique
      // m_pTeamPanels->Init(TEAM_PANELS_TDM_XML_NAME, "team_panels_wnd");
        m_pTeamPanels->Init(TEAM_PANELS_DM_XML_NAME, "team_panels_wnd");

        CUIXml uiXml, xml2;
        uiXml.Load(CONFIG_PATH, UI_PATH, "ui_game_tdm.xml");

        CUIXmlInit::InitWindow(uiXml, "global", 0, Window);

        CUIXmlInit::InitStatic(uiXml, "team1_icon", 0, m_team1_icon);
        CUIXmlInit::InitStatic(uiXml, "team2_icon", 0, m_team2_icon);
        CUIXmlInit::InitStatic(uiXml, "team3_icon", 0, m_team3_icon);
        CUIXmlInit::InitStatic(uiXml, "team4_icon", 0, m_team4_icon);
        CUIXmlInit::InitStatic(uiXml, "team5_icon", 0, m_team5_icon);
        CUIXmlInit::InitStatic(uiXml, "team6_icon", 0, m_team6_icon);
        CUIXmlInit::InitStatic(uiXml, "team7_icon", 0, m_team7_icon);
        CUIXmlInit::InitStatic(uiXml, "team8_icon", 0, m_team8_icon);
        CUIXmlInit::InitStatic(uiXml, "team9_icon", 0, m_team9_icon);

        CUIXmlInit::InitTextWnd(uiXml, "team1_score", 0, m_team1_score);
        CUIXmlInit::InitTextWnd(uiXml, "team2_score", 0, m_team2_score);
        CUIXmlInit::InitTextWnd(uiXml, "team3_score", 0, m_team3_score);
        CUIXmlInit::InitTextWnd(uiXml, "team4_score", 0, m_team4_score);
        CUIXmlInit::InitTextWnd(uiXml, "team5_score", 0, m_team5_score);
        CUIXmlInit::InitTextWnd(uiXml, "team6_score", 0, m_team6_score);
        CUIXmlInit::InitTextWnd(uiXml, "team7_score", 0, m_team7_score);
        CUIXmlInit::InitTextWnd(uiXml, "team8_score", 0, m_team8_score);
        CUIXmlInit::InitTextWnd(uiXml, "team9_score", 0, m_team9_score);

        CUIXmlInit::InitTextWnd(uiXml, "fraglimit", 0, m_pFragLimitIndicator);

        m_pMoneyIndicator->InitFromXML(uiXml);
        m_pRankIndicator->InitFromXml(uiXml);
    }
    if (stage == 2)
    { // after
        inherited::Init(stage);
        Window->AttachChild(m_team1_score);
        Window->AttachChild(m_team2_score);
        Window->AttachChild(m_team3_score);
        Window->AttachChild(m_team4_score);
        Window->AttachChild(m_team5_score);
        Window->AttachChild(m_team6_score);
        Window->AttachChild(m_team7_score);
        Window->AttachChild(m_team8_score);
        Window->AttachChild(m_team9_score);

        Window->AttachChild(m_buy_msg_caption);
    }
}

void CUIGameTDM::UnLoad()
{
    inherited::UnLoad();

    xr_delete(m_team1_icon);
    xr_delete(m_team2_icon);
    xr_delete(m_team3_icon);
    xr_delete(m_team4_icon);
    xr_delete(m_team5_icon);
    xr_delete(m_team6_icon);
    xr_delete(m_team7_icon);
    xr_delete(m_team8_icon);
    xr_delete(m_team9_icon);

    delete_data(m_pUITeamSelectWnd);
}

CUIGameTDM::~CUIGameTDM() {}
bool CUIGameTDM::IR_UIOnKeyboardPress(int dik)
{
    switch (dik)
    {
    case SDL_SCANCODE_CAPSLOCK:
    {
        if (m_game)
        {
            if (m_game->Get_ShowPlayerNamesEnabled())
                m_game->Set_ShowPlayerNames(!m_game->Get_ShowPlayerNames());
            else
                m_game->Set_ShowPlayerNames(true);
            return true;
        };
    }
    break;
    }
    return inherited::IR_UIOnKeyboardPress(dik);
}

bool CUIGameTDM::IR_UIOnKeyboardRelease(int dik)
{
    switch (dik)
    {
    case SDL_SCANCODE_CAPSLOCK:
    {
        if (m_game)
        {
            if (!m_game->Get_ShowPlayerNamesEnabled())
                m_game->Set_ShowPlayerNames(false);
            return true;
        };
    }
    break;
    }

    return inherited::IR_UIOnKeyboardRelease(dik);
}

void CUIGameTDM::OnFrame()
{
    inherited::OnFrame();
    m_team1_icon->Update();
    m_team2_icon->Update();
    m_team3_icon->Update();
    m_team4_icon->Update();
    m_team5_icon->Update();
    m_team6_icon->Update();
    m_team7_icon->Update();
    m_team8_icon->Update();
    m_team9_icon->Update();
}

void CUIGameTDM::Render()
{
    m_team1_icon->Draw();
    m_team2_icon->Draw();
    m_team3_icon->Draw();
    m_team4_icon->Draw();
    m_team5_icon->Draw();
    m_team6_icon->Draw();
    m_team7_icon->Draw();
    m_team8_icon->Draw();
    m_team9_icon->Draw();

    inherited::Render();
}

void CUIGameTDM::SetScoreCaption(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8, int t9) //---m4d
{
    string32 str;
    xr_sprintf(str, "%d", t1);
    m_team1_score->SetText(str);

    xr_sprintf(str, "%d", t2);
    m_team2_score->SetText(str);

    xr_sprintf(str, "%d", t3);
    m_team3_score->SetText(str);

    xr_sprintf(str, "%d", t4);
    m_team4_score->SetText(str);

    xr_sprintf(str, "%d", t5);
    m_team5_score->SetText(str);

    xr_sprintf(str, "%d", t6);
    m_team6_score->SetText(str);

    xr_sprintf(str, "%d", t7);
    m_team7_score->SetText(str);

    xr_sprintf(str, "%d", t8);
    m_team8_score->SetText(str);

    xr_sprintf(str, "%d", t9);
    m_team9_score->SetText(str);

    //m_pTeamPanels->SetArtefactsCount(t1, t2);
}

void CUIGameTDM::SetFraglimit(int local_frags, int fraglimit)
{
    string64 str;
    if (fraglimit)
        xr_sprintf(str, "%d", fraglimit);
    else
        xr_sprintf(str, "%s", "--");

    m_pFragLimitIndicator->SetText(str);
}

void CUIGameTDM::SetBuyMsgCaption(LPCSTR str)
{
    if (!str)
        m_buy_msg_caption->SetText("");
    else
        m_buy_msg_caption->SetTextST(str);
}
