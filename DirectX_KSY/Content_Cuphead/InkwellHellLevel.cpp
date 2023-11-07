#include "PreCompile.h"
#include "InkwellHellLevel.h"

#include "OverWorldLevel.h"
#include "Portal.h"
#include "OverWorldCharacter.h"

InkwellHellLevel::InkwellHellLevel()
{
}

InkwellHellLevel::~InkwellHellLevel()
{
}

void InkwellHellLevel::Start()
{
	ContentLevel::Start();

	// Sprite Load
	if (nullptr == GameEngineSprite::Find("InkwellHell.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\OverWorld\\OverWorldMap\\Inkwell_Hell");

		// Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\InkwellHell.png");
		GameEngineSprite::CreateSingle("InkwellHell.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\InkwellHell_pixel.png");
		GameEngineSprite::CreateSingle("InkwellHell_pixel.png");

		// Background Upper
		GameEngineTexture::Load(Dir.GetStringPath() + "\\InkwellHell_Upper.png");
		GameEngineSprite::CreateSingle("InkwellHell_Upper.png");
	}
}


void InkwellHellLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	ContentLevel::LevelStart(_PrevLevel);

	// Background
	CurLevelBackground = CreateActor<ContentBackground>();
	CurLevelBackground->BackgroundInit("InkwellHell.png");

	CurLevelPixelBackground = CreateActor<ContentBackground>();
	CurLevelPixelBackground->PixelBackgroundInit("InkwellHell_pixel.png");
	//CurLevelPixelBackground->GetRenderer()->On();

	// Background Upper
	CurLevelUpperBackground = CreateActor<ContentBackground>();
	CurLevelUpperBackground->UpperBackgroundInit("InkwellHell_Upper.png");

	// Entrance To Inkwell Isle
	PortalToInkwell = CreateActor<Portal>();
	PortalToInkwell->Transform.SetLocalPosition({ 900, -1750 });
	PortalToInkwell->SetPortalValue(PortalValue::Inkwell_Isle);
	PortalToInkwell->GetRenderer()->Off();

	// Entrance To Boss Stage
	PortalToBossStage = CreateActor<Portal>();
	PortalToBossStage->Transform.SetLocalPosition({ 1600, -1027 });
	PortalToBossStage->SetPortalValue(PortalValue::BossStage);
	PortalToBossStage->GetRenderer()->Off();

	// Player
	OverWorldPlayer = CreateActor<OverWorldCharacter>();
	OverWorldPlayer->Transform.SetLocalPosition({ 900, -1750 });

	float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
	GetMainCamera()->Transform.SetLocalPosition(PlayerPos);
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();
	float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY() };

	// Fade In
	FadeIn->Transform.SetLocalPosition(FadePos);

	// Fade Out
	FadeOut = CreateActor<FadeAnimation>();
	FadeOut->SetFade("Out");
	FadeOut->Off();
}

void InkwellHellLevel::Update(float _Delta)
{
	ContentLevel::Update(_Delta);

	if (true == PortalToBossStage->GetIsPortalOn())
	{
		FadeOut->On();
		float4 PlayerPos = OverWorldPlayer->Transform.GetLocalPosition();
		float4 WindowScale = GameEngineCore::MainWindow.GetScale();
		float4 FadePos = { PlayerPos.X - WindowScale.ihX(), PlayerPos.Y + WindowScale.ihY() };
		FadeOut->Transform.SetLocalPosition(FadePos);
	}

	if (true == FadeOut->IsCurAnimationEnd())
	{
		PortalToBossStage->LevelChange();
	}
}

void InkwellHellLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	ContentLevel::LevelEnd(_NextLevel);
}