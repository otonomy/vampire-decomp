#pragma once
struct tdesc_t { int a; const char *fieldName; int m_8; int m_c; short m_10; unsigned short m_Flags; };
class CPredictionCopy {
public:
	union
	{
		char m_u0[0x14];
		struct
		{
			int m_nType;	// 0x00: 1 non-networked only, 2 networked only
			void *m_pDest;	// 0x04
			void const *m_pSrc;	// 0x08
			int m_nDestOffsetIndex;	// 0x0c
			int m_nSrcOffsetIndex;	// 0x10
		};
	};
	bool m_bErrorCheck;
	bool m_bDescribeFields;
	char m_u16[2];
	tdesc_t *m_pCurrentField;
	const char *m_pCurrentClassName;
	union { char m_u20[4]; struct datamap_t *m_pCurrentMap; };	// 0x20
	bool m_bShouldReport;
	bool m_bReport;
	char m_u26[2];
	int m_nErrorCount;
	union { char m_u2c[4]; bool m_bPerformCopy; };	// 0x2c
	void *m_FieldCompareFunc;
	void ReportFieldsDiffer(const char *fmt, ...);
	char sub_10123470();
	int sub_10123bd0(const float *outvalue, const float *invalue, int count);
	int sub_10123cd0(const char *, const char *);
	void sub_10123760(int dt, struct Vector &outValue, const struct Vector &inValue);
	void sub_10123630(int dt, bool *outvalue, const bool *invalue, int count);
	void sub_101233b0(int dt, const char *fmt, ...);
	void sub_10123550(int dt, int *outvalue, const int *invalue, int count);
	void sub_10123800(int dt, struct Vector *outValue, const struct Vector *inValue, int count);
	int sub_10123480(int size, const void *outdata, const void *indata);	// CompareData
	void sub_101234c0(int dt, int size, void *outdata, const void *indata);	// DescribeData
	void sub_10123a60(int dt, int *outvalue, const int *invalue, int count);	// CopyInt
	int sub_10123a90(int *outvalue, const int *invalue, int count);	// CompareInt
	void sub_10123b20(int dt, bool *outvalue, const bool *invalue, unsigned int count);	// CopyBool
	int sub_10123b50(bool *outvalue, const bool *invalue, int count);	// CompareBool
	void sub_10123ba0(int dt, float *outvalue, const float *invalue, int count);	// CopyFloat
	void sub_101236b0(int dt, float *outvalue, const float *invalue, int count);	// DescribeFloat
	void sub_10123c90(int dt, char *outstring, const char *instring);	// CopyString
	void sub_10123710(int dt, char *outstring, const char *instring);	// DescribeString
	void sub_10123e30(int dt, struct Vector *outValue, const struct Vector *inValue, int count);	// CopyVector
	int sub_10123e70(struct Vector *outValue, const struct Vector *inValue, int count);	// CompareVector
	int sub_10123a10(short *outvalue, const short *invalue, int count);	// CompareShort
	void sub_101239d0(int dt, short *outvalue, const short *invalue, int count);	// CopyShort
	void sub_10123500(int dt, short *outvalue, const short *invalue, int count);	// DescribeShort
	int sub_10123fc0(int *outvalue, const int *invalue, int count);
	void sub_10123f90(int dt, int *outvalue, const int *invalue, int count);
	void sub_101238a0(int dt, int *outvalue, const int *invalue, int count);
	int sub_10124070(int nChainCount, struct datamap_t *dmap, struct typedescription_t *pFields, int fieldCount);	// "TransferData"
};
