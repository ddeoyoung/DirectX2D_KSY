#include "PreCompile.h"
#include "ChipsBettigan.h"

ChipsBettigan::ChipsBettigan()
{
}

ChipsBettigan::~ChipsBettigan()
{
}

void ChipsBettigan::Start()
{
	// Create Sprite Folder
	if (nullptr == GameEngineSprite::Find("Chips_Idle"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\ChipsBettigan\\Boss");

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}
	}

	// Create Animation
	MainRenderer = CreateComponent<GameEngineSpriteRenderer>();

	MainRenderer->CreateAnimation("Chips_Intro", "Chips_Intro");
	MainRenderer->CreateAnimation("Chips_Idle", "Chips_Idle", 0.05f);
	MainRenderer->CreateAnimation("Chips_Spin_Head", "Chips_Spin_Head");
	MainRenderer->CreateAnimation("Chips_Spin_Middle", "Chips_Spin_Middle");
	MainRenderer->CreateAnimation("Chips_Spin_Bottom", "Chips_Spin_Bottom");
	MainRenderer->CreateAnimation("Chips_Death_Fall", "Chips_Death_Fall");
	MainRenderer->SetEndEvent("Chips_Death_Fall", [](GameEngineSpriteRenderer* _Renderer)
		{
			_Renderer->ChangeAnimation("Chips_Death_HeadCrash");
		});
	MainRenderer->CreateAnimation("Chips_Death_HeadCrash", "Chips_Death_HeadCrash");
	MainRenderer->ChangeAnimation("Chips_Idle");

	MainRenderer->AutoSpriteSizeOn();
	MainRenderer->SetPivotType(PivotType::Bottom);

	Transform.SetLocalPosition({ 1000 , -650 });
}

void ChipsBettigan::Update(float _Delta)
{
	StateUpdate(_Delta);
}

void ChipsBettigan::ChangeState(ChipsState _State)
{
	if (_State != State)
	{
		switch (State)
		{
		case ChipsState::None:
			break;
		case ChipsState::Intro:
			IntroStart();
			break;
		case ChipsState::Idle:
			IdleStart();
			break;
		case ChipsState::Spin:
			SpinStart();
			break;
		case ChipsState::Death:
			DeathStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}

void ChipsBettigan::StateUpdate(float _Delta)
{
	switch (State)
	{
	case ChipsState::None:
		break;
	case ChipsState::Intro:
		return IntroUpdate(_Delta);
	case ChipsState::Idle:
		return IdleUpdate(_Delta);
	case ChipsState::Spin:
		return SpinUpdate(_Delta);
	case ChipsState::Death:
		return DeathUpdate(_Delta);
	default:
		break;
	}
}

void ChipsBettigan::ChangeAnimationState(const std::string& _StateName)
{
	std::string AnimationName = "Chips_";
	AnimationName += _StateName;

	CurState = _StateName;
	MainRenderer->ChangeAnimation(AnimationName);
}