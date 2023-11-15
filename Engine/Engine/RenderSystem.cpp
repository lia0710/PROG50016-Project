#include "EngineCore.h"
#include "RenderSystem.h"
#include "IRenderable.h"

RenderSystem* RenderSystem::instance = nullptr;

void RenderSystem::AddRenderable(IRenderable* renderable)
{
	renderables.push_back(renderable);
}

void RenderSystem::RemoveRenderable(IRenderable* renderable)
{
	renderables.remove(renderable);
}

void RenderSystem::Initialize()
{
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderSystem::Destroy()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void RenderSystem::Update()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// Render Objects here
	for (auto& renderable : renderables)
	{
		renderable->Render();
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Load()
{
}
