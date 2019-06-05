#ifndef _H3LOD_H_
#define _H3LOD_H_

#pragma once

#include "H3Base.h"

struct H3LodItem
{
	// * +0
	CHAR name[12];
	h3unk _f_0C[4];
	// * +10
	PUINT8 buffer;
	// * +14
	UINT32 size;
	// * +18
	INT32 type;
	h3unk _f_1C[4];
};

// * size 190h
struct H3Lod
{
	// * +0
	PCHAR name;
	// * +4
	PUINT8 filePosition;
	// * +8
	CHAR path[256]; // possibly less, not important
	h3unk _f_108[112];
	// * +178
	INT32 filesCount;
	h3unk _f_17C[4];
	// * +180
	PUINT8 fileHeaders;
	h3unk _f_184[12];

	H3Lod* Create(PCHAR fileName) { return THISCALL_2(H3Lod*, 0x559420, this, fileName); }
	H3Lod* Destroy() { THISCALL_1(H3Lod*, 0x559460, this); }

	// * 1 means READ_ONLY
	BOOL Load(PCHAR fileName) { return THISCALL_3(BOOL, 0x4FAF30, &filePosition, fileName, 1); }
	BOOL8 FindFileInLod(PCHAR file) { return THISCALL_2(BOOL8, 0x4FB100, &filePosition, file); }
	H3LodItem* LoadFileFromLod(PCHAR file) { return THISCALL_2(H3LodItem*, 0x4FACA0, &filePosition, file); }
};

#endif /* #define _H3LOD_H_ */