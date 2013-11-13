#ifndef _TRIANGLE_EXERCISE_
#define _TRIANGLE_EXERCISE_

#include "Exercise.h"

class TriangleExercise : public Exercise {

public:
	virtual void setupPipeline() override;
	virtual void renderFrame() override;
	virtual void closePipeline() override;
	virtual const char* getName() override { return name; };
	virtual void handle(MSG &msg) override;

private:
	static const char* name;
};

#endif