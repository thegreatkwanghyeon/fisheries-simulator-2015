#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#include "stdafx.h"
#include "SceneBase.h"

class Director{
	private:

		static Director* pInstance;

		SceneBase* currentScene = NULL;

		Director(){

		}

		~Director(){

		}

	public:
		static Director* getInstance(){

			if (NULL == pInstance){

				pInstance = new Director();

			}

			return pInstance;

		}

		static void freeInstance(){

			if (NULL != pInstance){
				delete pInstance;
				pInstance = NULL;

			}

		}

		void changeScene(SceneBase* scene){
			if(currentScene != NULL){

				delete currentScene;
				currentScene = scene;

			}
		}		

		void runWithScene(SceneBase* scene){
			if(currentScene == NULL){

				currentScene = scene;

			}
		}

		void update(){
			if(currentScene != NULL)
				currentScene->update();
		}	

		void draw(sf::RenderWindow& window){
			if(currentScene != NULL)
				currentScene->draw(window);
		}					
};

Director* Director::pInstance = NULL;

#endif