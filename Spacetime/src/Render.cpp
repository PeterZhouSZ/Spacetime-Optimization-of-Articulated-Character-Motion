//======================================================================================================================//
// SpacetimeOptimization.cpp																							//
// (c) Ricky Arietta 2014																								//
// CIS 599 Masters Independent Study																					//
// University of Pennsylvania																							//
// Computer Graphics and Gaming Technology Program																		//
//																														//
// This code...																											//
//======================================================================================================================//

#include "Render.h"

Spacetime *render_system;
RenderUtil::Camera*	sCamera;

void motionCallback(int x, int y)
{
	sCamera->handleMotion(x, y);
}

void keyPress(const char key)
{
	switch(toupper(key)) {
		case 'P': render_system->switchPause(); break;
		default: break;
	}
}

void keyboardCallback(unsigned char key, int x, int y)
{
	if(key==27)
		exit(0);

	if(!sCamera->handleKey(key, x, y))
		keyPress(key);
}

void mouseCallback(int button, int state, int x, int y)
{
	sCamera->handleMouse(button, state, x, y);
}

void idleCallback()
{
	glutPostRedisplay();
}

//==================================================================================================//
// Main render function																				//
//	Includes logic for making initial guess and optimizing input torque solution					//
//	Renders sequence after each iteration of the solver												//
//==================================================================================================//

void renderCallback()
{
	static int iteration = 0;

	//----------------------------------------------------------------------------------------------//
	// compute and render initial guess of torque input sequence									//
	// via PD controller defined in Spacetime::makeInitialGuess()									//
	//----------------------------------------------------------------------------------------------//

	render_system->uSequence.clear();
	render_system->setState(render_system->state_0);
	for (int t = 0; t < render_system->numTimeSteps; t++)
	{
		// compute next torque vector of initial guess
		render_system->makeInitialGuess();
		RenderUtil::startRender(sCamera->getEye(), sCamera->getDir());
	
		// render timestep using computed input torque vector
		PxScene* scene;
		PxGetPhysics().getScenes(&scene,1);
		PxU32 nbActors = scene->getNbActors(PxActorTypeSelectionFlag::eRIGID_DYNAMIC);
		if(nbActors) {
			std::vector<PxRigidActor*> actors(nbActors);
			scene->getActors(PxActorTypeSelectionFlag::eRIGID_DYNAMIC, 
							 (PxActor**)&actors[0], nbActors);
			for (PxU32 i = 0; i < nbActors; i++)
				RenderUtil::renderActors(&actors[i], 1, true, PxVec3(0.3,0.3,0.3));
		}
		
		// label iteration
		char* result = "Initial Guess";
		glRasterPos2i(20,-25);
		for(int i = 0; i < strlen(result); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, result[i]);

		// finish rendering
		RenderUtil::finishRender();
	}
	
	//----------------------------------------------------------------------------------------------//
	// Compute and render next iteration of optimized solution via numerical iterative				//
	// solver method involving state vector X and costate vector lambda								//
	//----------------------------------------------------------------------------------------------//

	double uDiff = std::numeric_limits<double>::infinity();
	do {
		iteration++;
		render_system->setState(render_system->state_0);
		uDiff = render_system->IterateOptimization();
		for (int t = 0; t < render_system->numTimeSteps; t++)
		{
			render_system->applyTorqueVector(render_system->uSequence[t]);
			render_system->stepPhysics();

			RenderUtil::startRender(sCamera->getEye(), sCamera->getDir());
	
			PxScene* scene;
			PxGetPhysics().getScenes(&scene,1);
			PxU32 nbActors = scene->getNbActors(PxActorTypeSelectionFlag::eRIGID_DYNAMIC);
			if(nbActors) {
				std::vector<PxRigidActor*> actors(nbActors);
				scene->getActors(PxActorTypeSelectionFlag::eRIGID_DYNAMIC, 
								 (PxActor**)&actors[0], nbActors);
				for (PxU32 i = 0; i < nbActors; i++)
					RenderUtil::renderActors(&actors[i], 1, true, PxVec3(0.3,0.3,0.3));
			}
		
			char* label = "Iteration #";
			char buffer[10]; itoa(iteration, buffer, 10);
			char* result = new char[strlen(label)+strlen(buffer)];
			sprintf(result,"%s%s",label,buffer);
			glRasterPos2i(20,-25);
			for(int i = 0; i < strlen(result); i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, result[i]);

			RenderUtil::finishRender();
		}
	} while (uDiff >= render_system->uThreshold);
}

void exitCallback(void)
{
	delete sCamera;
	render_system->cleanupPhysics();
}

void renderLoop(Spacetime *sys)
{
	render_system = sys;
	sCamera = new RenderUtil::Camera(PxVec3(35.0f, 50.0f, 35.0f), PxVec3(-35.0f,-35.0f,-35.0f));

	RenderUtil::setupDefaultWindow("Spacetime Optimization Example");
	RenderUtil::setupDefaultRenderState();

	glutIdleFunc(idleCallback);
	glutDisplayFunc(renderCallback);
	glutKeyboardFunc(keyboardCallback);
	glutMouseFunc(mouseCallback);
	glutMotionFunc(motionCallback);
	motionCallback(0,0);

	atexit(exitCallback);

	//render_system->initPhysics();
	glutMainLoop();
}
