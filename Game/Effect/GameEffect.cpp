#include "stdafx.h"
#include "GameEffect.h"
#include "graphics/effect/EffectEmitter.h"

namespace nsApp {

	nsApp::GameEffect::GameEffect()
	{
	}

	nsApp::GameEffect::~GameEffect()
	{
	}

	bool nsApp::GameEffect::Start()
	{
		EffectEngine::GetInstance()->ResistEffect(0, u"Assets/effect/block/blood.efk");
		return true;
	}
}