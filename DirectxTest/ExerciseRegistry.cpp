#include "stdafx.h"
#include <stddef.h>
#include "ExerciseRegistry.h"

ExerciseRegistry* ExerciseRegistry::instance = new ExerciseRegistry();
const char* ExerciseRegistry::name = "Exercise Registry";

void ExerciseRegistry::setDevices(LPDIRECT3D9 d3d, LPDIRECT3DDEVICE9 d3ddev) {
	this->d3d = d3d;
	this->d3ddev = d3ddev;
}

void ExerciseRegistry::setupPipeline() {
	if (current != NULL)
		current->setupPipeline();
}

void ExerciseRegistry::renderFrame() {
	if (current != NULL)
		current->renderFrame();
}

void ExerciseRegistry::closePipeline() {
	if (current != NULL)
		current->closePipeline();
}

void ExerciseRegistry::addExercise(Exercise* exercise) {
	if (totalRegistered == maxExercises) {
		maxExercises += 10;
		Exercise **new_exercises = new Exercise*[maxExercises + 1];
		memcpy(new_exercises, exercises, totalRegistered);
		delete [] exercises;
		exercises = new_exercises;
	}

	exercises[totalRegistered++] = exercise;
}

Exercise* ExerciseRegistry::getExercise(int index) {
	if (0 <= index && index < totalRegistered)
		return exercises[index];
	else
		return NULL;
}

void ExerciseRegistry::selectExercise(int index) {
	Exercise* new_exercise = getExercise(index);
	if (new_exercise != NULL) {
		if (current != NULL)
			current->closePipeline();
		current = new_exercise;
		current->setupPipeline();
	}
}

void ExerciseRegistry::handle(MSG &msg) {
	int number = msg.message - 0x30; // 0x30 is the keycode for '0'

	if (number < 10)
		selectExercise(number);
	else if (current)
		current->handle(msg);
}