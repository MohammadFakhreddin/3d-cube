﻿#include "./ColoredCubeScene.h"

#include "../../data_access_point/DataAccessPoint.h"
#include "../../shaders/ambient_light/AmbientLight.h"

ColoredCubeScene::ColoredCubeScene(
  OpenGL& gl
) 
  :
  BaseScene(gl,"ColoredCubeScene"),
  cameraInstance(
    gl,
    Matrix3X1Float(),
    Matrix3X1Float(),
    DataAccessPoint::getInstance()->getAppScreenWidth(),
    DataAccessPoint::getInstance()->getAppScreenHeight(),
    "Color main camera"
  ),
  ambientLight(std::make_unique<AmbientLight>(0.2f, 0.2f, 0.2f)),
  directionalLight(std::make_unique<DirectionalLight>(1.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f)),
  pip(cameraInstance)
{
  {//Creating shape
    auto appScreenWidth = DataAccessPoint::getInstance()->getAppScreenWidth();
    auto appScreenHeight = DataAccessPoint::getInstance()->getAppScreenHeight();
    float width = DataAccessPoint::getInstance()->getAppScreenWidth() / 30.0f;
    Logger::log("Creating shape object");
    //TODO Remove transfrom and scale
    cube = colorCube.generateCube(
      Constants::LightPrecision::perSurface,
      width,
      width,
      width,
      float(appScreenWidth) / 2.0f,
      float(appScreenHeight) / 2.0f,
      100.0f,
      0,
      0,
      0,
      1
    );
  }

  pip.assignAmbientLight(ambientLight.get());
  pip.assignDirectionalLight(directionalLight.get());
  pip.assignShapes(cube.get());

}

void ColoredCubeScene::update(double deltaTime) {
#ifdef __DESKTOP__
  {//We rotate light by keyboard
    lightRotationX = 0.0f;
    lightRotationY = 0.0f;
    lightRotationZ = 0.0f;
    if (useKeyEvent(Constants::Buttons::keyA)) {
      lightRotationX += float(deltaTime * lightTransformSpeed * -1.0f);
    }
    if (useKeyEvent(Constants::Buttons::keyD)) {
      lightRotationX += float(deltaTime * lightTransformSpeed);
    }
    if (useKeyEvent(Constants::Buttons::keyW)) {
      lightRotationY += float(deltaTime * lightTransformSpeed);
    }
    if (useKeyEvent(Constants::Buttons::keyS)) {
      lightRotationY += float(deltaTime * lightTransformSpeed * -1.0);
    }
    if (useKeyEvent(Constants::Buttons::keyC)) {
      lightRotationZ += float(deltaTime * lightTransformSpeed * -1.0 * 0.5);
    }
    if (useKeyEvent(Constants::Buttons::keyV)) {
      lightRotationZ += float(deltaTime * lightTransformSpeed * 1.0 * 0.5);
    }
    if (lightRotationX != 0 || lightRotationY != 0 || lightRotationZ != 0) {
      directionalLight->rotateXYZ(lightRotationX, lightRotationY, lightRotationZ);
    }
  }
  float rotation = float(shapeRotationSpeed * deltaTime);
  cube->rotateXYZ(rotation, rotation, rotation);
#endif // __DESKTOP__
  pip.update(deltaTime);
}

void ColoredCubeScene::render(double deltaTime) {
  cameraInstance.render(deltaTime);
}