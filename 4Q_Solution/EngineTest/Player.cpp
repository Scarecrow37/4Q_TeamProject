#include "pch.h"
#include "Player.h"

#include "GameApplication.h"
#include "NetworkTemp.h"

Player::Player(std::filesystem::path&& meshPath, std::filesystem::path&& fontPath) :
	_meshPath(std::forward<std::filesystem::path>(meshPath)),
	_fontPath(std::forward<std::filesystem::path>(fontPath)),
	_camera(nullptr)
	//_staticMesh(nullptr), 
	//_textRenderer(nullptr),
	//_skeltalMesh(L"../Resources/Player/Player.X", &_worldMatrix),
	//_animator(&_skeltalMesh)
{
}

void Player::Prepare(Engine::Content::Factory::Component* componentFactory)
{
	_camera = componentFactory->Clone<Engine::Component::Camera>(this);
	_staticMesh = componentFactory->Clone<Engine::Component::StaticMesh>(this);
	//_skeltalMesh = componentFactory->Clone<Engine::Component::SkeletalMesh>(this);
	//_animator = componentFactory->Clone<Engine::Component::Animator>(this);
	_textRenderer = componentFactory->Clone<Engine::Component::TextRenderer>(this);
    _sync = componentFactory->Clone<Engine::Component::Synchronize>(this);
	_remote = componentFactory->Clone<RemoteMoveComponent>(this);
	_chractorController = componentFactory->Clone<Engine::Component::ChractorController>(this);
}

int Player::GetSerialNumber()
{
	return _sync->GetSerialNumber();
}

void Player::SetSerialNumber(int num)
{
	_sync->SetSerialNumber(num);
}

void Player::DisposeComponents()
{
    _textRenderer->Dispose();
    _staticMesh->Dispose();
	//_skeltalMesh->Dispose();
	//_animator->Dispose();
    _camera->Dispose();
	_sync->Dispose();
	_remote->Dispose();
	_chractorController->Dispose();
}

void Player::PreInitialize(const Engine::Modules& modules)
{
	Object::PreInitialize(modules);

	_remote->SetTarget(&_transform);	
	_remote->BindOnMove([this]() {
		//_animator->ChangeAnimation("Run");
		});
	_remote->BindOnStop([this]() {
		//_animator->ChangeAnimation("Wait");
		});


    _camera->SetName(L"MainCamera");
    _staticMesh->SetFilePath(_meshPath);
    _staticMesh->SetMatrix(&_worldMatrix);
	//_skeltalMesh->SetFilePath(_meshPath);
	//_skeltalMesh->SetMatrix(&_worldMatrix);
	//_animator->SetSkeletalMesh(_skeltalMesh);
    _textRenderer->SetFontPath(_fontPath);

	_sync->AddCallback((short)PacketID::EnterAccept, &Player::EnterSuccess, this);
	_sync->AddCallback((short)PacketID::MoveSync, &Player::SyncMove, this);
	_sync->AddCallback((short)PacketID::DataRemote, &Player::SetLocation, this);

	//_sync.SetSerialNumber(1);

	const auto inputManager = Engine::Application::GetInputManager();
	Engine::Input::IMappingContext* mappingContext = nullptr;
	inputManager->GetMappingContext(L"Default", &mappingContext);

	Engine::Input::IAction* moveAction = nullptr;
	mappingContext->GetAction(L"Move", &moveAction);
	moveAction->AddListener(Engine::Input::Trigger::Event::Triggered, [this](auto value)
	{
		//if (direction != moveDirection) {
			_sync->_move.set_x(value.x);
			_sync->_move.set_y(value.y);
			_sync->_move.set_z(value.z);
			_sync->_move.set_speed(_remote->GetSpeed());

			_sync->_move.SerializeToString(&_sync->_msgBuffer);

			Engine::Application::GetNetworkManager()->SaveSendData(
				(short)PacketID::Move,
				_sync->_msgBuffer,
				_sync->_move.ByteSizeLong(),
				_sync->GetSerialNumber()
			);

			Engine::Math::Vector3 moveDirection = value;
			_remote->SetDirection(moveDirection);
		
	});
	moveAction->AddListener(Engine::Input::Trigger::Event::Started, [this](auto value) {
		GameApplication::GetLoggerManager()->Log(Engine::Logger::LogLevel::Debug, std::format(L"x:{0}, y:{1}", value.x, value.y));

		//_animator->ChangeAnimation("Run"); 

		_sync->_stateChange.set_stateinfo(1);
		_sync->_stateChange.SerializeToString(&_sync->_msgBuffer);

		Engine::Application::GetNetworkManager()->SaveSendData(
			(short)PacketID::StateChange,
			_sync->_msgBuffer,
			_sync->_stateChange.ByteSizeLong(),
			_sync->GetSerialNumber()
		);
		});
	moveAction->AddListener(Engine::Input::Trigger::Event::Completed, [this](auto value)
		{ 
			_sync->_move.set_x(0);
			_sync->_move.set_y(0);
			_sync->_move.set_z(0);
			_sync->_move.set_speed(0);

			_sync->_move.SerializeToString(&_sync->_msgBuffer);

			Engine::Application::GetNetworkManager()->SaveSendData(
				(short)PacketID::Move,
				_sync->_msgBuffer,
				_sync->_move.ByteSizeLong(),
				_sync->GetSerialNumber()
			);

			_sync->_stateChange.set_stateinfo(0);
			_sync->_stateChange.SerializeToString(&_sync->_msgBuffer);

			Engine::Application::GetNetworkManager()->SaveSendData(
				(short)PacketID::StateChange,
				_sync->_msgBuffer,
				_sync->_stateChange.ByteSizeLong(),
				_sync->GetSerialNumber()
			);
			_remote->SetDirection(Engine::Math::Vector3::Zero);
		});

	Engine::Input::IAction* jumpAction = nullptr;
	mappingContext->GetAction(L"Jump", &jumpAction);
	jumpAction->AddListener(Engine::Input::Trigger::Event::Started, [this](auto value) 
		{
			_sync->_jump.set_power(30.f);
			_sync->_jump.SerializeToString(&_sync->_msgBuffer);

			Engine::Application::GetNetworkManager()->SaveSendData(
				(short)PacketID::Jump,
				_sync->_msgBuffer,
				_sync->_jump.ByteSizeLong(),
				_sync->GetSerialNumber()
			);
		});

	Engine::Input::IAction* cameraAction = nullptr;
	mappingContext->GetAction(L"Camera", &cameraAction);
	cameraAction->AddListener(Engine::Input::Trigger::Event::Triggered, [this](Engine::Math::Vector3 value)
	{
		_cameraRotation += value;
	});

	Engine::Physics::ControllerDesc desc;
	desc.stepOffset = 10;
	desc.height = 10.f;
	desc.radius = 2.f;
	desc.climbinMode = Engine::Physics::CapsuleClimbingMode::Easy;
	auto PhysicsManager = Engine::Application::GetPhysicsManager();
	PhysicsManager->CreatePlayerController(&_chractorController->_controller, PhysicsManager->GetScene(0), desc);
}

void Player::PostInitialize(const Engine::Modules& modules)
{
	Object::PostInitialize(modules);
	_remote->SetSpeed(100.f);
	_textRenderer->SetPosition(100, 100.f);
	_textRenderer->SetText(L"Hello World!");
	_textRenderer->SetFontColor(1.f, 0.f, 0.f, 1.f);
	//_animator->ChangeAnimation("Wait");
	//_skeltalMesh.SetRenderLayer(0);
	/*_animator.SetUpSplitBone(2);
	_animator.SplitBone(0, "Dummy_root");
	_animator.SplitBone(1, "Bip01-Spine1");
	_animator.ChangeAnimation("Wait");*/
	_camera->SetParent(&_cameraParentMatrix);
}

void Player::PostAttach()
{
	Object::PostAttach();
	_camera->Activate();	
}

void Player::PostUpdate(const float deltaTime)
{
	Object::PostUpdate(deltaTime);
	_worldMatrix = Engine::Math::Matrix::CreateScale(1.f)
		* Engine::Math::Matrix::CreateFromQuaternion(_transform.rotation)
		* Engine::Math::Matrix::CreateTranslation(_transform.position.x, _transform.position.y, _transform.position.z);
	//printf("Position : %f, %f, %f\n", _transform.position.x, _transform.position.y, _transform.position.z);
	// Temp Shoulder View Camera;
	auto rotation = Engine::Math::Quaternion::CreateFromYawPitchRoll(_cameraRotation);
	_cameraParentMatrix = Engine::Math::Matrix::CreateFromQuaternion(rotation);

	Engine::Math::Vector3 tempPostion = _transform.position;
	tempPostion.y += 50.f;
	tempPostion += _cameraParentMatrix.Backward() * -60.f;
	tempPostion += _cameraParentMatrix.Right() * 10.f;

	_cameraParentMatrix *= Engine::Math::Matrix::CreateTranslation(tempPostion);

	// auto speed = _movement->GetSpeed();
	// auto dir = _movement->GetDirection();
	// auto translate = speed * dir / 1000.f;
	// if (!(gravityFlag & static_cast<unsigned short>(Engine::Physics::ControllerCollisionFlag::Down)))
	// 	translate += {0, -0.098f, 0};
	// gravityFlag = _chractorController->_controller->Move(translate, 0.001, 0.02);

}

void Player::PostFixedUpdate()
{

}

void Player::EnterSuccess(const ConnectMsg::EnterAccept* msg)
{
	_sync->SetSerialNumber(msg->grantnumber());
}

void Player::SyncMove(const MoveMsg::MoveSync* msg)
{
	float x = msg->x();
	float y = msg->y();
	float z = msg->z();
	Engine::Math::Vector3 nextLocation(x, y, z);
	_remote->SetNextLocation(nextLocation);
}

void Player::SetLocation(const MoveMsg::MoveSync* msg)
{
	float x = msg->x();
	float y = msg->y();
	float z = msg->z();
	_transform.position = Engine::Math::Vector3(x, y, z);
}
