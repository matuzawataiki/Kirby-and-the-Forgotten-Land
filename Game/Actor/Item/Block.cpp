#include "stdafx.h"
#include "Block.h"
namespace nsApp {
	namespace nsActor {
		namespace {
			static const Vector3 BOXCOLLISION_SIZE = { 140.0f,140.0f,140.0f };
		}

		bool Block::Start()
		{
			return true;
		}

		void Block::Init(const int blockType, const Vector3& position, const Quaternion& rotation)
		{
			if (blockType == BlockType::Soft) {
				m_Model.Init("Assets/modelData/Block/Block.tkm");
			}
			else {
				m_Model.Init("Assets/modelData/Block/Block.tkm");
			}
			m_Position = position;
			m_Rotation = rotation;
			m_Model.SetPosition(m_Position);
			m_Model.SetRotation(m_Rotation);
			m_Model.SetScale(Vector3( 0.3f,0.3f,0.3f ));
			m_Model.Update();

			m_pCollisionObject = NewGO<CollisionObject>(0,"BlockCollision");
			m_pCollisionObject->CreateBox(m_Position, m_Rotation, BOXCOLLISION_SIZE);
			m_pCollisionObject->SetIsEnableAutoDelete(false);

			m_IsDraw = true;
		}

		void Block::Break()
		{
			m_IsDraw = false;
			m_IsBreak = true;
		}

		bool Block::IsHit(CollisionObject* collition)
		{
			if (m_pCollisionObject->IsHit(collition)) {
				EffectEmitter* effectEmitter = NewGO<EffectEmitter>(0);
				effectEmitter->Init(0);
				effectEmitter->SetScale({ 5.0f,5.0f,5.0f });
				effectEmitter->Play();
				Break();
				return true;
			}
			return false;
		}

		void Block::Update()
		{
			std::cout << m_IsDraw;
		}

		void Block::Render(RenderContext& rc)
		{
			if (!m_IsDraw) {
				return;
			}
			m_Model.Draw(rc);
		}


	}
}