#pragma once

#ifndef _IRENDERABLE_H_
#define _IRENDERABLE_H_

class IRenderable
{
protected:
	IRenderable();
	~IRenderable();

private:
	virtual void Render() = 0;

	friend class RenderSystem;
};

#endif

