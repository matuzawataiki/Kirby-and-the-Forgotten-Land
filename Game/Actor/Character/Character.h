#pragma once
namespace nsApp {
	namespace nsActor {
		class Character:public IGameObject
		{
		public:
			Character()
				: m_Position(Vector3::Zero)
				, m_MoveSpeed(Vector3::Zero)
				, m_Rotation(Quaternion::Identity)
				, m_IsDraw(false)
				, m_JumpPower(0.0f)
			{
			};

			virtual ~Character(){}

			virtual bool Start();

			virtual void Init();

			virtual void Update();

			virtual void Render(RenderContext& rc);

			void Jump(const float jumpPower) { m_MoveSpeed.y = jumpPower; };

			/*セッター***********************************************************************/
			void SetPosition(const Vector3& position) { m_Position = position; }

			void SetMoveSpeed(const Vector3& moveSpeed) { m_MoveSpeed = moveSpeed; }

			void SetRotation(const Quaternion& rotation) { m_Rotation = rotation; }
			
			/*ゲッター***********************************************************************/
			const Vector3& GetPosition() { return m_Position; }

			const Vector3& GetMoveSpeed() { return m_MoveSpeed; }

			const Quaternion& GetRotation() { return m_Rotation; }

		protected:
			float		m_JumpPower;
			Vector3		m_Position;
			Vector3		m_MoveSpeed;

			Quaternion	m_Rotation;

			ModelRender			m_Model;
			CharacterController m_CharacterController;

			bool m_IsDraw;
		};
	}
}


