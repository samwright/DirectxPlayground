#ifndef _EXERCISE_
#define _EXERCISE_

#include <d3d9.h>

class Exercise {
public:
	virtual void setupPipeline() = 0;
	virtual void renderFrame() = 0;
	virtual void closePipeline() = 0;
	virtual const char* getName() = 0;
	virtual void handle(MSG &msg) = 0;
};

#endif