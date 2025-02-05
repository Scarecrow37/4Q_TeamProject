#include "pch.h"
#include "Player.h"

Player::Player(std::filesystem::path&& meshPath, std::filesystem::path&& fontPath)
	: _meshPath(std::forward<std::filesystem::path>(meshPath))
	, _fontPath(std::forward<std::filesystem::path>(fontPath))
	, _movement(nullptr)
	, _camera(nullptr)
	, _skeletalMesh(nullptr)
	, _animator(nullptr)
	, _textRenderer(nullptr)
{
}

void Player::Prepare(Engine::Content::Factory::Component* componentFactory)
{
	_movement = componentFactory->Clone<Engine::Component::Movement>(this);
	_camera = componentFactory->Clone<Engine::Component::Camera>(this);
	_skeletalMesh = componentFactory->Clone<Engine::Component::SkeletalMesh>(this);
	_animator = componentFactory->Clone<Engine::Component::Animator>(this);
	_textRenderer = componentFactory->Clone<Engine::Component::TextRenderer>(this);
}

void Player::DisposeComponents()
{
	_camera->Dispose();
	_movement->Dispose();
	_animator->Dispose();
	_skeletalMesh->Dispose();
	_textRenderer->Dispose();
}

void Player::PreInitialize(const Engine::Modules& modules)
{
	Object::PreInitialize(modules);

	_camera->SetName(L"MainCamera");
	_movement->SetTarget(&_transform);

	_skeletalMesh->SetFilePath(_meshPath);
	_skeletalMesh->SetMatrix(&_worldMatrix);
	_animator->SetSkeletalMesh(_skeletalMesh);
	_textRenderer->SetFontPath(_fontPath);

	const auto inputManager = Engine::Application::GetInputManager();
	Engine::Input::IMappingContext* mappingContext = nullptr;
	inputManager->GetMappingContext(L"Default", &mappingContext);

	Engine::Input::IAction* moveAction = nullptr;
	mappingContext->GetAction(L"Move", &moveAction);
	moveAction->AddListener(Engine::Input::Trigger::Event::Triggered, [this](auto value)
		{
			Engine::Math::Vector3 direction = value;
			direction = Engine::Math::Vector3::TransformNormal(direction, _cameraParentMatrix);
			direction.y = 0.f;
			direction.Normalize();
			_transform.rotation = Engine::Math::Quaternion::CreateFromYawPitchRoll(Engine::Math::Vector3(0.f, _cameraRotation.y + 3.14f, 0.f));
			_movement->SetDirection(direction);
		});
	moveAction->AddListener(Engine::Input::Trigger::Event::Started, [this](auto value)
		{
			_animator->ChangeAnimation("rig|Anim_Walk");
		});
	moveAction->AddListener(Engine::Input::Trigger::Event::Completed, [this](auto value)
		{
			_animator->ChangeAnimation("rig|Anim_Idle");
			_movement->SetDirection(Engine::Math::Vector3::Zero);
		});

	Engine::Input::IAction* cameraAction = nullptr;
	mappingContext->GetAction(L"Camera", &cameraAction);
	cameraAction->AddListener(Engine::Input::Trigger::Event::Triggered, [this](Engine::Math::Vector3 value)
		{
			_cameraRotation += value;
		});
}

void Player::PostInitialize(const Engine::Modules& modules)
{
	Object::PostInitialize(modules);
	_movement->SetSpeed(100.f);
	_textRenderer->SetPosition(100, 100.f);
	_textRenderer->SetText(L"������ �ü�ü\nHello World!");
	_textRenderer->SetFontColor(1.f, 0.f, 0.f, 1.f);

	//_skeltalMesh.SetRenderLayer(0);
	/*_animator.SetUpSplitBone(2);
	_animator.SplitBone(0, "Dummy_root");
	_animator.SplitBone(1, "Bip01-Spine1");
	_animator.ChangeAnimation("Wait");*/

	//_skeletalMesh->SetActiveShadow(false);
	_skeletalMesh->SetPostEffectFlag(1);
	_camera->SetParent(&_cameraParentMatrix);
}

void Player::PostAttach()
{
	Object::PostAttach();
	_camera->Activate();
}

float elapsed = 0.f;
int frame = 0;

void Player::PostUpdate(const float deltaTime)
{
	Object::PostUpdate(deltaTime);
	
	_worldMatrix = Engine::Math::Matrix::CreateScale(0.4f)
			     * Engine::Math::Matrix::CreateFromQuaternion(_transform.rotation)
				 * Engine::Math::Matrix::CreateTranslation(_transform.position.x, _transform.position.y, _transform.position.z);

	auto rotation = Engine::Math::Quaternion::CreateFromYawPitchRoll(_cameraRotation);
	_cameraParentMatrix = Engine::Math::Matrix::CreateFromQuaternion(rotation);	

	Engine::Math::Vector3 tempPostion = _transform.position;
	tempPostion.y += 50.f;
	tempPostion += _cameraParentMatrix.Backward() * -60.f;
	tempPostion += _cameraParentMatrix.Right() * 10.f;

	_cameraParentMatrix *= Engine::Math::Matrix::CreateTranslation(tempPostion);
	

	elapsed += deltaTime;
	frame++;
	if (1.f < elapsed)
	{
		printf("%d\n", frame);
		frame = 0;
		elapsed = 0.f;
	}
}