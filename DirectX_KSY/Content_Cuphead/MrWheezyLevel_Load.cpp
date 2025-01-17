#include "PreCompile.h"
#include "MrWheezyLevel.h"

void MrWheezyLevel::LevelStartTextureLoad()
{
	// Background
	if (nullptr == GameEngineSprite::Find("kd_cigar_bg_smokers_loop.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\StageObject\\Background");

		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_smokers_loop.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_smokers_loop.png");

		// Pixel Background
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_pixel.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_pixel.png");
	}


	// Frontground
	if (nullptr == GameEngineSprite::Find("kd_cigar_bg_smoke_fg.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\StageObject");

		// Right Bottom
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_smoke_fg.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_smoke_fg.png");

		// Right Top
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_mg_smoke_top_right.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_mg_smoke_top_right.png");

		// Left Top
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_mg_smoke_top_left.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_mg_smoke_top_left.png");

		// Bottom
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_mg_smoke_btm.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_mg_smoke_btm.png");
	}

	// Ash Tray
	if (nullptr == GameEngineSprite::Find("kd_cigar_bg_ashtray_left_bk.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\StageObject");

		// Left Back
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_ashtray_left_bk.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_ashtray_left_bk.png");

		// Left Front
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_ashtray_left_fr.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_ashtray_left_fr.png");

		// Right Back
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_ashtray_right_bk.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_ashtray_right_bk.png");

		// Right Front
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_cigar_bg_ashtray_right_fr.png");
		GameEngineSprite::CreateSingle("kd_cigar_bg_ashtray_right_fr.png");
	}

	// Ash
	if (nullptr == GameEngineSprite::Find("kd_top_cigar_ash_main_0001.png"))
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources\\Texture\\Stage\\MrWheezy\\StageObject");

		// Main
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_top_cigar_ash_main_0001.png");
		GameEngineSprite::CreateSingle("kd_top_cigar_ash_main_0001.png");

		// 1
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_top_cigar_ash_0001.png");
		GameEngineSprite::CreateSingle("kd_top_cigar_ash_0001.png");

		// 2
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_top_cigar_ash_0002.png");
		GameEngineSprite::CreateSingle("kd_top_cigar_ash_0002.png");

		// 3
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_top_cigar_ash_0003.png");
		GameEngineSprite::CreateSingle("kd_top_cigar_ash_0003.png");

		// 4
		GameEngineTexture::Load(Dir.GetStringPath() + "\\kd_top_cigar_ash_0004.png");
		GameEngineSprite::CreateSingle("kd_top_cigar_ash_0004.png");
	}


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////// Set ////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MrWheezyLevel::LevelStartTextureSet()
{
	// Frontground
	std::shared_ptr<ContentActor> FG_RightBottom = CreateActor<ContentActor>();
	FG_RightBottom->SpriteInit("kd_cigar_bg_smoke_fg.png", { 1150 , -650 }, RenderOrder::FrontgroundObject4);

	std::shared_ptr<ContentActor> FG_RightTop = CreateActor<ContentActor>();
	FG_RightTop->SpriteInit("kd_cigar_bg_mg_smoke_top_right.png", { 1100 , -80 }, RenderOrder::BackgroundObject4);

	std::shared_ptr<ContentActor> FG_LeftTop = CreateActor<ContentActor>();
	FG_LeftTop->SpriteInit("kd_cigar_bg_mg_smoke_top_left.png", { 130 , -50 }, RenderOrder::BackgroundObject4);

	std::shared_ptr<ContentActor> FG_Bottom = CreateActor<ContentActor>();
	FG_Bottom->SpriteInit("kd_cigar_bg_mg_smoke_btm.png", { 650 , -450 }, RenderOrder::BackgroundObject);


	// Ash Tray
	std::shared_ptr<ContentActor> AshTray_LeftBack = CreateActor<ContentActor>();
	AshTray_LeftBack->SpriteInit("kd_cigar_bg_ashtray_left_bk.png", { 180 , -600 }, RenderOrder::BackgroundObject2);

	std::shared_ptr<ContentActor> AshTray_LeftFront = CreateActor<ContentActor>();
	AshTray_LeftFront->SpriteInit("kd_cigar_bg_ashtray_left_fr.png", { 180 , -640 }, RenderOrder::FrontgroundObject2);

	std::shared_ptr<ContentActor> AshTray_RightBack = CreateActor<ContentActor>();
	AshTray_RightBack->SpriteInit("kd_cigar_bg_ashtray_right_bk.png", { 1050 , -600 }, RenderOrder::BackgroundObject2);

	std::shared_ptr<ContentActor> AshTray_RightFront = CreateActor<ContentActor>();
	AshTray_RightFront->SpriteInit("kd_cigar_bg_ashtray_right_fr.png", { 1050 , -600 }, RenderOrder::FrontgroundObject2);


	// Ash
	std::shared_ptr<ContentActor> Ash_LeftBack = CreateActor<ContentActor>();
	Ash_LeftBack->SpriteInit("kd_top_cigar_ash_0004.png", { 150 , -480 }, RenderOrder::BackgroundObject2);

	std::shared_ptr<ContentActor> Ash_LeftMiddle = CreateActor<ContentActor>();
	Ash_LeftMiddle->SpriteInit("kd_top_cigar_ash_0003.png", { 200 , -490 }, RenderOrder::BackgroundObject2);

	std::shared_ptr<ContentActor> Ash_LeftMain = CreateActor<ContentActor>();
	Ash_LeftMain->SpriteInit("kd_top_cigar_ash_main_0001.png", { 200 , -520 }, RenderOrder::FrontgroundObject);

	std::shared_ptr<ContentActor> Ash_RightBack = CreateActor<ContentActor>();
	Ash_RightBack->SpriteInit("kd_top_cigar_ash_0004.png", { 1020 , -480 }, RenderOrder::BackgroundObject2);

	std::shared_ptr<ContentActor> Ash_RightMiddle = CreateActor<ContentActor>();
	Ash_RightMiddle->SpriteInit("kd_top_cigar_ash_0002.png", { 1070 , -490 }, RenderOrder::BackgroundObject2);

	std::shared_ptr<ContentActor> Ash_RightMain = CreateActor<ContentActor>();
	Ash_RightMain->SpriteInit("kd_top_cigar_ash_main_0001.png", { 1050 , -520 }, RenderOrder::FrontgroundObject);

}