// CUtlRBTree20: Source's CUtlRBTree with 20-byte nodes (8-byte links, 12-byte element), a less-func pointer first.
#pragma once

class CUtlRBTree20
{
public:
	struct Links_t
	{
		unsigned short m_Left;
		unsigned short m_Right;
		unsigned short m_Parent;
		unsigned short m_Tag;
	};
	struct Node_t
	{
		Links_t m_Links;
		char m_Data[12];
	};

	bool (*m_LessFunc)(const void *, const void *);
	Node_t *m_pElements;
	int m_unk8;
	int m_unkC;
	unsigned short m_Root;
	unsigned short m_NumElements;
	unsigned short m_FirstFree;
	unsigned short m_TotalElements;

	static unsigned short InvalidIndex() { return 0xffff; }

	const Links_t &sub_10112840(unsigned short i) const;	// "CUtlRBTree::Links" out of line (with the sentinel static)
	unsigned short sub_10110fb0(unsigned short i);
	void sub_10113a20(unsigned short elem);
};

// the instance's sentinel is the function-local static of Links(), placed at the game's address
template <unsigned long Sentinel>
class CUtlRBTree20At : public CUtlRBTree20
{
public:
	const Links_t &Links(unsigned short i) const
	{
		static Links_t s_Sentinel = { InvalidIndex(), InvalidIndex(), InvalidIndex(), 1 };
		return i != InvalidIndex() ? m_pElements[i].m_Links : s_Sentinel;
	}
};
