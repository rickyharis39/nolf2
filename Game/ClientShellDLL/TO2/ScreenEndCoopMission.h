// ----------------------------------------------------------------------- //
//
// MODULE  : ScreenEndCoopMission.h
//
// PURPOSE : Interface screen for handling end of mission in a co-op game
//
// (c) 2002 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#if !defined(_SCREEN_END_COOP_MISSION_H_)
#define _SCREEN_END_COOP_MISSION_H_

#include "BaseScreen.h"

class CScreenEndCoopMission : public CBaseScreen
{
public:
	CScreenEndCoopMission();
	virtual ~CScreenEndCoopMission();

	// Build the screen
    virtual LTBOOL	Build();
    virtual void	OnFocus(LTBOOL bFocus);
	virtual void	Escape();

    virtual LTBOOL	HandleKeyDown(int key, int rep);
    virtual LTBOOL	OnLButtonDown(int x, int y);
    virtual LTBOOL	OnRButtonDown(int x, int y);

    virtual LTBOOL	Render(HSURFACE hDestSurf);


protected:

	CLTGUITextCtrl		*m_pMission;
	CLTGUIListCtrl		*m_pList;

	CLTGUITextCtrl		*m_pContinue;
};

#endif // !defined(_SCREEN_END_COOP_MISSION_H_)