// Copyright (C) 2022 sfan5
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in Irrlicht.h

#include "CSDLManager.h"

#if defined(_IRR_COMPILE_WITH_SDL_DEVICE_) && defined(_IRR_COMPILE_WITH_OPENGL_)

#include "CIrrDeviceSDL.h"
#include "COpenGLCommon.h"

namespace irr
{
namespace video
{

CSDLManager::CSDLManager(CIrrDeviceSDL* device) : IContextManager(), SDLDevice(device)
{
	#ifdef _DEBUG
	setDebugName("CSDLManager");
	#endif
}

bool CSDLManager::initialize(const SIrrlichtCreationParameters& params, const SExposedVideoData& data)
{
	Data = data;
	return true;
}

const SExposedVideoData& CSDLManager::getContext() const
{
	return Data;
}

bool CSDLManager::activateContext(const SExposedVideoData& videoData, bool restorePrimaryOnZero)
{
	// unclear if this is still needed:
	glFrontFace(GL_CW);
	return true;
}

void* CSDLManager::getProcAddress(const std::string &procName)
{
	return SDL_GL_GetProcAddress(procName.c_str());
}

bool CSDLManager::swapBuffers()
{
	SDLDevice->SwapWindow();
	return true;
}

}
}

#endif
