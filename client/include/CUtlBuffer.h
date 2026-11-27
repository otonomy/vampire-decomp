// CUtlBuffer: growable byte buffer with a read cursor (not in the game's RTTI; layout read off the string getters).
#pragma once

extern "C" __declspec(dllimport) void Plat_Free(void *);

class CUtlBuffer
{
public:
	char *m_pBuffer;	// 0x00
	int m_nSize;	// 0x04: end of the readable data
	int m_nGrow;	// 0x08
	int m_nGet;	// 0x0c: read cursor
	int m_nPut;	// 0x10
	unsigned char m_nError;	// 0x14: nonzero when the buffer is unusable; bit 1 set when a read ran past the end
	unsigned char m_nFlags;	// 0x15: bit 0 = text buffer

	CUtlBuffer(int nGrow, int nInitSize, int bText);	// out of line (stub 0x1000faa1 = 0x1006bd20)
	~CUtlBuffer()
	{
		if (m_nGrow != -1 && m_pBuffer)
			Plat_Free(m_pBuffer);
	}

	CUtlBuffer() {}
	void sub_1013c8e0(char *pBuffer, int nSize, bool bText);	// frees an owned buffer, then wraps the external one (grow -1), cursors cleared, text flag set from bText
	void sub_1013c9f0();	// skips the white space at the read cursor of a text buffer (stub 0x1000c35b)
	void sub_1013ca40(char *pString);	// reads one string: to the terminating null of a binary buffer, or to the next white space of a text buffer
	bool sub_1013cbb0(int nAdd);
	int sub_1013cc20(const char *pFmt, char *list);	// \"CUtlBuffer::VaScanf\": text buffers only; matches pFmt (space = skip white space, %c %d %i %x %u %f %s) against the data and stores through the va_list, returns the number of conversions
		// CheckPut (stub 0x10005583)	// makes room for nSize more bytes at the write cursor (stub 0x10005583), false when the buffer cannot take them
	void sub_1013ce90(const char *pFmt, char *list);
	bool sub_1013cf00(int nSize);	// CheckPut
	void sub_1013ce20(const void *pMem, int nSize);	// copies nSize bytes to the write cursor and moves the cursor past them, when sub_10005583(nSize) holds
};
