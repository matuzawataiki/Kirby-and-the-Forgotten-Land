#pragma once
namespace nsApp {
	namespace nsActor {
		namespace nsItem {
			/**
			 * @brief ブロックの種類
			 */
			enum BlockType {
				Soft,	//簡単に壊せるブロック
				Hard,	//かたいブロック
			};

			/**
			 * @brief 干渉できるブロックのクラス
			 */
			class Block:public IGameObject
			{
			public:
				Block()
					: m_Position(Vector3::Zero)
					, m_Rotation(Quaternion::Identity)
					, m_IsDraw(false)
					, m_pCollisionObject(nullptr)
					, m_BlockType()
					, m_Model()
				{};

				~Block();

				bool Start();

				/**
				 * @brief 初期化関数
				 * @details ブロックのモデルの設定やコリジョンの作成
				 * @param blockType 種類
				 * @param position 位置
				 * @param rotation 向き
				 */
				void Init(const int blockType, const Vector3& position, const Quaternion& rotation);
				
				/**
				 * @brief ブロックの破壊
				 * @details ブロックを破壊し、エフェクトを再生させる
				 */
				void Break();

				bool IsHit(CollisionObject* collition) {
					if (m_pCollisionObject->IsHit(collition)) {
						return true;
					}
					return false;
				}

				void Update();
				void Render(RenderContext& rc);

			private:
				//! ブロックの種類
				BlockType m_BlockType;

				ModelRender m_Model;
				CollisionObject* m_pCollisionObject;

				Vector3 m_Position;
				Quaternion m_Rotation;

				bool m_IsDraw;
			};
		}
	}
}
