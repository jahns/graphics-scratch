#pragma once
#include "stdafx.h"
class IRenderLoop
{
public:
	IRenderLoop() {}
	virtual ~IRenderLoop() {}
	virtual void render() = 0;
};

