#include "./BunnyScene.h"

#include "../base_scene/BaseScene.h"
#include "../../application/Application.h"
#include "../../file_system/FileSystem.h"

BunnyScene::BunnyScene(OpenGL& gl)
  : 
  BaseScene(gl, "BunnyScene"),
  cameraInstance(
    gl,
    cameraInitialMaximumFov,
    0,
    0,
    cameraInitialZLocation,
    0,
    0,
    0,
    (int)Application::getInstance()->getAppScreenWidth(),
    (int)Application::getInstance()->getAppScreenHeight(),
    "Main camera"
  ),
  light(
    float(Application::getInstance()->getAppScreenWidth()) / 2.0f,
    float(Application::getInstance()->getAppScreenHeight()),
    cameraInitialZLocation - 1.0f
  )
{
  {//Creating shape
    auto scaleFactor = float(Application::getInstance()->getAppScreenWidth()) / 4.0f;
    shape = FileSystem::loadObjectWithColor(
      Path::generateAssetPath("bunny", ".obj"),
      Vec3DFloat(1.0f, 1.0f, 1.0f),
      true
    );
    shape->transformX(float(Application::getInstance()->getAppScreenWidth()) / 2.0f);
    shape->transformY(float(Application::getInstance()->getAppScreenHeight()) / 2.0f);
    shape->transformZ(cameraInitialZLocation - 100.0f);
    shape->scale(scaleFactor);
  }
  {//Creating light source
    lightSources.emplace_back(
      &light
    );
  }
}

void BunnyScene::update(double deltaTime) {
  {//We rotate light by keyboard
    if (useKeyEvent(Constants::Buttons::keyA)) {
      light.transformX(
        float(deltaTime * lightTransformSpeed * -1.0f)
      );
    }
    if (useKeyEvent(Constants::Buttons::keyD)) {
      light.transformX(
        float(deltaTime * lightTransformSpeed)
      );
    }
    if (useKeyEvent(Constants::Buttons::keyW)) {
      light.transformY(
        float(deltaTime * lightTransformSpeed)
      );
    }
    if (useKeyEvent(Constants::Buttons::keyS)) {
      light.transformY(
        float(deltaTime * lightTransformSpeed * -1.0)
      );
    }
    if (useKeyEvent(Constants::Buttons::keyC)) {
      light.transformZ(
        float(deltaTime * lightTransformSpeed * -1.0 * 0.5)
      );
    }
    if (useKeyEvent(Constants::Buttons::keyV)) {
      light.transformZ(
        float(deltaTime * lightTransformSpeed * 1.0 * 0.5)
      );
    }
  }
  {//Rotating shape by keyboard
    if (useKeyEvent(Constants::Buttons::keyU)) {
      shape->rotateZ(float(1.0 * shapeRotationSpeed * deltaTime));
    }
    if (useKeyEvent(Constants::Buttons::keyJ)) {
      shape->rotateZ(float(-1.0 * shapeRotationSpeed * deltaTime));
    }
    if (useKeyEvent(Constants::Buttons::keyK)) {
      shape->rotateY(float(1.0 * shapeRotationSpeed * deltaTime));
    }
    if (useKeyEvent(Constants::Buttons::keyH)) {
      shape->rotateY(float(-1.0 * shapeRotationSpeed * deltaTime));
    }
    if (useKeyEvent(Constants::Buttons::keyI)) {
      shape->rotateX(float(1.0 * shapeRotationSpeed * deltaTime));
    }
    if (useKeyEvent(Constants::Buttons::keyY)) {
      shape->rotateX(float(-1.0 * shapeRotationSpeed * deltaTime));
    }
  }
  {//Temporary code for auto rotation
    shape->rotateY(float(-1.0f * shapeRotationSpeed * deltaTime * 0.1f));
    shape->rotateX(float(-1.0f * shapeRotationSpeed * deltaTime * 0.1f));
    shape->rotateZ(float(-1.0f * shapeRotationSpeed * deltaTime * 0.1f));
  }
  {//Updating light
    for (unsigned int i = 0; i < lightSources.size(); i++) {
      lightSources.at(i)->update(deltaTime, cameraInstance);
    }
  }
  shape->update(deltaTime, cameraInstance,lightSources);
  cameraInstance.update(deltaTime);
}

void BunnyScene::render(double deltaTime) {
  {//Updating light
    for (unsigned int i = 0; i < lightSources.size(); i++) {
      lightSources.at(0)->render(deltaTime, cameraInstance);
    }
  }
  shape->render(deltaTime, cameraInstance);
  cameraInstance.render(deltaTime);
}