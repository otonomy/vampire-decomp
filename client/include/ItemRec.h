// ItemRec: the 0x58-byte item record of the items table (id at +0, name at +8); constructor 0x1014f6c0, destructor 0x1014f6f0.
#pragma once

class ItemRec
{
public:
	int m_id;
	int m_unk04;
	const char *m_name;
	char m_pad0c[0x58 - 0xc];
	ItemRec(int id);
	~ItemRec();
};
