// ----------------------------------------------------------------------- //
//
// MODULE  : Trigger.h
//
// PURPOSE : Trigger - Definition
//
// CREATED : 10/6/97
//
// (c) 1997-2000 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef __TRIGGER_H__
#define __TRIGGER_H__

#include "GameBase.h"
#include "CommandMgr.h"
#include "KeyMgr.h"
#include "SharedFXStructs.h"
#include "TriggerTypeMgr.h"

#define MAX_NUM_COMMANDS 10

LINKTO_MODULE( Trigger );

class Trigger : public GameBase
{
	public :

		Trigger();
		~Trigger();

        void SetLocked(LTBOOL bLocked=LTTRUE)	{ m_bLocked = bLocked; }
        void SetTriggerDelay(LTFLOAT fDelay)	{ m_fTriggerDelay = fDelay; }
        void SetAITriggerable(LTBOOL bBool)		{ m_bAITriggerable = bBool; }
        void SetBodyTriggerable(LTBOOL bBool)	{ m_bBodyTriggerable = bBool; }

	protected :

        virtual uint32	EngineMessageFn(uint32 messageID, void *pData, LTFLOAT fData);

		virtual bool	OnTrigger(HOBJECT hSender, const CParsedMsg &cMsg);
		virtual void	UpdateDelayingActivate();

		virtual void	ObjectTouch(HOBJECT hObj);
		virtual void	Unlock();
        virtual LTBOOL  Activate();
		virtual void	RequestActivate();
        virtual void	DoTrigger(HOBJECT hObj, LTBOOL bTouchNotify);

		virtual	void	CreateSpecialFX( LTBOOL bUpdateClients = LTFALSE );
		virtual void	SendLockedMsg();

		LTBOOL		m_bActive;              // Are we currently 'live'?
        LTFLOAT		m_fTriggerDelay;        // How long to wait after being triggered

		HSTRING		m_hstrActivationSound;	// Name of our activation sound
        LTFLOAT		m_fSoundRadius;         // Radius of activation sound

		HSTRING		m_hstrCommand[MAX_NUM_COMMANDS]; // Commands to execute

        LTBOOL		m_bTriggerTouch;			// Use touch trigger
        LTBOOL		m_bTouchNotifyActivation;	// Activated by touch notify
		HSTRING		m_hstrCommandTouch;			// Command to execute when touched
		LTObjRef	m_hTouchObject;				// Object that touched me

        LTBOOL		m_bPlayerTriggerable;   // Can the Player trigger me?
		uint32		m_nPlayerKeyID;			// What key does the player have to have to trigger me?
        LTBOOL		m_bAITriggerable;       // Can AI's trigger me?
		HSTRING		m_hstrAIName;			// Name AI's that can trigger me
        LTBOOL		m_bBodyTriggerable;     // Can Body's trigger me?
		HSTRING		m_hstrBodyName;			// Name Body's that can trigger me

        LTBOOL		m_bLocked;              // Is this door locked?

        LTBOOL		m_bDelayingActivate;    // Are we currently delaying activate
        LTFLOAT		m_fStartDelayTime;      // When did we start the delay
        LTFLOAT		m_fSendDelay;           // How long do we wait
        LTFLOAT		m_fLastTouchTime;       // Last time we were touched (and triggered)

        uint32		m_nActivationCount;     // How many times we are triggered before msgs are sent
        uint32		m_nCurrentActivation;   // Current value of count

		int			m_nNumActivations;		// How many times the trigger can be activated (<= 0 is infinite)
		int			m_nNumTimesActivated;	// How many times has the trigger been activated

        LTBOOL		m_bWeightedTrigger;     // Is this a weighted trigger
        LTFLOAT		m_fMessage1Weight;      // % of time message 1 is sent over message 2

        LTBOOL		m_bTimedTrigger;        // Is this a timed trigger
        LTFLOAT		m_fMinTriggerTime;      // Min time to wait to trigger
        LTFLOAT		m_fMaxTriggerTime;      // Max time to wait to trigger
        LTFLOAT		m_fNextTriggerTime;     // Next time to trigger object

        LTBOOL		m_bAttached;            // Is the trigger attached to an object
		
		bool		m_bSendTriggerFXMsg;	// Should we send the message to create a trigger fx.

		TRIGGERCREATESTRUCT m_TCS;

	// NOTE:  The following data members do not need to be saved / loaded
	// when saving games.  Any data members that don't need to be saved
	// should be added here (to keep them together)...

        LTVector	m_vDims;				// Dims
		HSTRING		m_hstrAttachToObject;	// Name of object to attach to
        uint32		m_dwFlags;              // Our initial flags

	private :

        void    Save(ILTMessage_Write *pMsg, uint32 dwSaveFlags);
        void    Load(ILTMessage_Read *pMsg, uint32 dwLoadFlags);

		void	AttachToObject();

        LTBOOL	InitialUpdate();
        LTBOOL	Update();
        LTBOOL	ReadProp(ObjectCreateStruct *pData);
};

class CTriggerPlugin : public IObjectPlugin
{
	public :

		virtual LTRESULT	PreHook_EditStringList(
			const char* szRezPath,
			const char* szPropName,
			char** aszStrings,
            uint32* pcStrings,
            const uint32 cMaxStrings,
            const uint32 cMaxStringLength);

		virtual LTRESULT PreHook_PropChanged(
				const char *szObjName,
				const char *szPropName,
				const int nPropType,
				const GenericProp &gpPropValue,
				ILTPreInterface *pInterface,
				const char *szModifiers );

	protected :

		CKeyMgrPlugin m_KeyMgrPlugin;
		CCommandMgrPlugin m_CommandMgrPlugin;
		CTriggerTypeMgrPlugin m_TriggerTypeMgrPlugin;
};

#endif // __TRIGGER_H__