//////////////////////////////////////////////////////////////////////////////
// Texture FX manager header file

#ifndef __TEXTUREFXMGR_H__
#define __TEXTUREFXMGR_H__

#include <map>
#include <slist>

class CTextureFXMgr 
{
public:

	enum {	NUM_STAGES	= 2,
			NUM_VARS	= 6
		};

	CTextureFXMgr();
	~CTextureFXMgr();

	void HandleSFXMsg(ILTMessage_Read *pMsg);
	void Update();

private:
	bool ChangeEffectVar(uint32 nID, uint32 nVar, float fVal);

	struct SWaitingVar
	{
		SWaitingVar() {}
		SWaitingVar(uint32 nID, uint32 nVar, float fVal) : m_nID(nID), m_nVar(nVar), m_fVal(fVal) {}
		SWaitingVar(const SWaitingVar &cOther) : m_nID(cOther.m_nID), m_nVar(cOther.m_nVar), m_fVal(cOther.m_fVal) {}
		SWaitingVar &operator=(const SWaitingVar &cOther) {
			m_nID = cOther.m_nID;
			m_nVar = cOther.m_nVar;
			m_fVal = cOther.m_fVal;
			return *this;
		}
		uint32 m_nID;
		uint32 m_nVar;
		float  m_fVal;
	};

	typedef std::slist<SWaitingVar> TWaitingVarList;
	TWaitingVarList m_aWaitingVarList;
};

#endif //__LIGHTGROUPFX_H__