#include "stdafx.h"
#include "ItemManager.h"
namespace nsApp {
	namespace nsActor {
		bool ItemManager::Start()
		{

			return true;
		}

		void ItemManager::Update()
		{
			IsHit();
			DeleteItem();
		}

		void ItemManager::Remove(Block* block)
		{
			auto it = std::find(m_pBlocks.begin(), m_pBlocks.end(), block);
			if (it != m_pBlocks.end()) {
				DeleteGO(*it);
				m_pBlocks.erase(it);
			}
		}

		void ItemManager::DeleteItem()
		{
			for (auto block : m_pBlocks) {
				if (block->IsBreak()) {
					Remove(block);
				}
			}
		}

		void ItemManager::IsHit()
		{
			int blockSize = m_pBlocks.size();
			if (blockSize == 0) {
				return;
			}

			//プレイヤーが出した攻撃用コリジョンを取得
			std::vector<CollisionObject*> collisionObjects = g_collisionObjectManager->FindCollisionObjects("PlayerAttack");

			for (auto collisions : collisionObjects) {
				for (int i = 0;i < blockSize;i++) {
					m_pBlocks[i]->IsHit(collisions);
				}
			}


		}
	}
}
