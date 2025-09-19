#include "stdafx.h"
#include "Block.h"
namespace nsApp {
	namespace nsActor {
		namespace nsItem {
			namespace {
				static const Vector3 BOXCOLLISION_SIZE = { 140.0f,140.0f,140.0f };
			}

			Block::Block()
			{

			}
			Block::~Block()
			{
			}

			bool Block::Start()
			{
				return false;
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

				m_pCollisionObject = NewGO<CollisionObject>(0,"BlockCollision");
				m_pCollisionObject->CreateBox(m_Position, m_Rotation, BOXCOLLISION_SIZE);
				m_pCollisionObject->SetIsEnableAutoDelete(false);

				m_IsDraw = true;
			}

			void Block::Break()
			{
				m_IsDraw = false;
			}

			void Block::Update()
			{
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
}