#pragma once
class IRenderLoop
{
public:
	IRenderLoop();
	virtual ~IRenderLoop() = 0;
	virtual void render() = 0;
};

