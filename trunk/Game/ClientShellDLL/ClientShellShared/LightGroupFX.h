//////////////////////////////////////////////////////////////////////////////
// LightGroup FX manager header file

#ifndef __LIGHTGROUPFX_H__
#define __LIGHTGROUPFX_H__

#pragma warning (disable : 4786)
#include <map>
#include <slist>

class CLightGroupFXMgr 
{
public:
	CLightGroupFXMgr();
	~CLightGroupFXMgr();

	void HandleSFXMsg(ILTMessage_Read *pMsg);
	void Update();
	void Clear();
private:
	bool ChangeLGColor(uint32 nID, const LTVector &vAdj);

	typedef std::map<uint32, LTVector> TLGColorMap;
	TLGColorMap m_cColorMap;

	struct SWaitingAdj
	{
		SWaitingAdj() {}
		SWaitingAdj(uint32 nID, const LTVector &vAdj) : m_nID(nID), m_vAdj(vAdj) {}
		SWaitingAdj(const SWaitingAdj &cOther) : m_nID(cOther.m_nID), m_vAdj(cOther.m_vAdj) {}
		SWaitingAdj &operator=(const SWaitingAdj &cOther) {
			m_nID = cOther.m_nID;
			m_vAdj = cOther.m_vAdj;
			return *this;
		}
		uint32 m_nID;
		LTVector m_vAdj;
	};

	typedef std::slist<SWaitingAdj> TWaitingAdjList;
	TWaitingAdjList m_aWaitingAdjList;
};

#endif //__LIGHTGROUPFX_H__