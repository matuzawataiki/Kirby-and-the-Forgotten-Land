#pragma once
#include "Block.h"

namespace nsApp {
	namespace nsActor {

		/**
		 * @brief アイテムの管理をする
		 * @details アイテムの追加や削除、ヒット確認などをする
		 */
		class ItemManager :public IGameObject
		{
		public:
			ItemManager()
				:m_pBlocks()
			{
			};
			~ItemManager() {
				m_pBlocks.clear();
			}

			bool Start();
			void Update();

			/**
			 * @brief ブロックの作成
			 * @param blockType ブロックの種類、0でやわらかいブロック、1で硬いブロック
			 * @param position 位置
			 * @param rotation 回転
			 */
			void CreateBlock(const int blockType, const Vector3& position, const Quaternion& rotation) {
				Block* block = NewGO<Block>(0, "Block");
				block->Init(blockType, position, rotation);
				m_pBlocks.push_back(block);
			}

		private:
			/**
			 * @brief ブロックをアイテムマネージャーから削除
			 * @param block
			 */
			void Remove(Block* block);

			/**
			 * @brief Break状態のアイテムを削除
			 */
			void DeleteItem();

			/**
			 * @brief プレイヤーの攻撃が当たっているかどうか
			 */
			void IsHit();
		private:
			std::vector<Block*> m_pBlocks;
		};
	}
}