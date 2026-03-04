#ifndef IMGUI_CACHETESTER_H
#define IMGUI_CACHETESTER_H
#include <array>
#include <vector>

namespace dae
{
	class imgui_CacheTester final
	{
	public:
		struct Transform
		{
			float matrix[16] = {
				1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1
			};
		};

		class GameObject3D
		{
		public:
			Transform transform{};
			int ID{};
		};


		// Cache-friendly version
		class GameObject3DAlt
		{
		public:
			int ID{};
		};


		void RenderCacheTestWindow();

		imgui_CacheTester();

	private:


		int sampleCount{ 10 };

		static size_t constexpr m_stepCount{11};
		std::array<float, m_stepCount> const m_stepSizes
		{
			1,2,4,8,16,32,64,128,256,512,1024
		};

		bool m_showGameObject;
		bool m_showGameObjectAlt;


		std::vector<float> m_resultsGameObject;
		std::vector<float> m_resultsGameObjectAlt;

		void ThrashTheCacheWithGameObject3DAlt();
		void ThrashTheCacheWithGameObject3D();
	};
}
#endif // !IMGUI_CACHETESTER_H
