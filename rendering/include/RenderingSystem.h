#ifndef RENDERING_SYSTEM_H_
#define RENDERING_SYSTEM_H_

#ifdef RENDERING_EXPORTS
#define CPH_RENDERING_DLL _declspec(dllexport)
#else
#define CPH_RENDERING_DLL _declspec(dllimport)
#endif

#include "ObjectSystem.h"
#include "RenderingComponent.h"
#include "ObjectManager.h"


namespace cph {

struct RenderingSystem : public ObjectSystem {

	virtual void execute(ObjectManager* objectManager, long delta) = 0;

	virtual RenderingComponent* createComponent() = 0;

	virtual ~RenderingSystem() = 0;

};

extern "C" {
	CPH_RENDERING_DLL RenderingSystem* createRenderingSystem();
	CPH_RENDERING_DLL void deleteRenderingSystem(RenderingSystem* renderingSystem);
}

}

#endif