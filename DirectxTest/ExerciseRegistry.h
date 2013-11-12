#ifndef _EXERCISE_REGISTRY_
#define _EXERCISE_REGISTRY_

#include "Exercise.h"

class ExerciseRegistry : public Exercise {

public:
	static ExerciseRegistry* getInstance() { return instance; }

	virtual ~ExerciseRegistry() { delete exercises; }

	void setDevices(LPDIRECT3D9 d3d, LPDIRECT3DDEVICE9 d3ddev);
	LPDIRECT3D9 getD3d();
	LPDIRECT3DDEVICE9 getD3ddev();

	void addExercise(Exercise* exercise);
	Exercise* getExercise(int index);
	int getTotalRegistered() { return totalRegistered; }
	void selectExercise(int index);

	void setupPipeline();
	void renderFrame();
	void closePipeline();
	const char* getName() { return name; };
	void handle(MSG &msg);

private:
	ExerciseRegistry() { current = NULL; };
	ExerciseRegistry(ExerciseRegistry const&) {};
	ExerciseRegistry& operator=(ExerciseRegistry const&) {};
	
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;
	
	int totalRegistered = 0;
	int maxExercises = 0;
	Exercise **exercises;
	Exercise *current;
	
	static ExerciseRegistry* instance;
	static const char* name;

};

#endif