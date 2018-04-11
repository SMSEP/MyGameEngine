#pragma once

namespace My
{
	typedef enum IndexSize
	{
		kIndexSize16 = 0x00000010,
		kIndexSize32 = 0x00000020,
		kIndexSizePlatformDependent = 0x10000000,   //start point of platform specific value
	} IndexSize;

	typedef enum PrimitiveType
	{
		kPrimitiveTypeNone = 0x00000000,
		kPrimitiveTypePointList = 0x00000001,
		kPrimitiveTypeLineList = 0x00000002,
		kPrimitiveTypeLineStrip = 0x00000003,
		kPrimitiveTypeTriList = 0x00000004,
		kPrimitiveTypeTriFan = 0x00000005,
		kPrimitiveTypeTriStrip = 0x00000006,
		kPrimitiveTypePatch = 0x00000009,             //Used for tessellation
		kPrimitiveTypeLineListAdjacency = 0x0000000a, ///< For N>=0, vertices [N*4..N*4+3] render a line from [1, 2]. Lines [0, 1] and [2, 3] are adjacent to the rendered line.
        kPrimitiveTypeLineStripAdjacency = 0x0000000b, ///< For N>=0, vertices [N+1, N+2] render a line. Lines [N, N+1] and [N+2, N+3] are adjacent to the rendered line.
        kPrimitiveTypeTriListAdjacency = 0x0000000c, ///< For N>=0, vertices [N*6..N*6+5] render a triangle from [0, 2, 4]. Triangles [0, 1, 2] [4, 2, 3] and [5, 0, 4] are adjacent to the rendered triangle.
        kPrimitiveTypeTriStripAdjacency = 0x0000000d, ///< For N>=0, vertices [N*4..N*4+6] render a triangle from [0, 2, 4] and [4, 2, 6]. Odd vertices Nodd form adjacent triangles with indices min(Nodd+1,Nlast) and max(Nodd-3,Nfirst). To prevent a GPU hang in NEO mode, you must call <c>setVgtControlForNeo(255, Gnm::kWdSwitchOnlyOnEopEnable, Gnm::kVgtPartialVsWaveDisable)</c> before using this mode.
		kPrimitiveTypeRectList = 0x00000011,
		kPrimitiveTypeLineLoop = 0x00000012,
		kPrimitiveTypeQuadList = 0x00000013,
		kPrimitiveTypeQuadStrip = 0x00000014,
		kPrimitiveTypePolygon = 0x00000015,
	} PrimitiveType;
	
	class Mesh
	{
	public:
		Mesh()
		: m_vertexBuffer(0)
		, m_vertexBufferSize(0)
		, m_vertexCount(0)
		, m_vertexAttributeCount(0)
		, m_indexBuffer(0)
		, m_indexBufferSize(0)
		, m_indexCount(0)
		, m_indexType(IndexSize::kIndexSize16)
		, m_primitiveType(PrimitiveType::kPrimitiveTypeTriList)
		{};
		
	public:
		enum { kMaxiumVertexBufferElements = 16};
		
		void* m_vertexBuffer;
		uint32_t m_vertexBufferSize;
		uint32_t m_vertexCount;
		uint32_t m_vertexAttributeCount;
		uint8_t m_reserved0[4];
		
		void* m_indexBuffer;
		uint32_t m_indexBufferSize;
		uint32_t m_indexCount;
		
		IndexSize m_indexType;
		PrimitiveType m_primitiveType;
	};

	class SimpleMesh : public Mesh
	{
	public:
		uint32_t m_vertexStride;
		uint32_t m_reserved[3];
	};
};



