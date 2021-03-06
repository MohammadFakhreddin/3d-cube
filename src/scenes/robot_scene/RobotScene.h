#ifndef RobotScene_Class
#define RobotScene_Class

#include <memory>

#include "../base_scene/BaseScene.h"
#include "../../open_gl/OpenGl.h"
#include "../../camera/Camera.h"
#include "../../texture/ColorTexture/ColorTexture.h"
#include "../../shaders/directional_light/DirectionalLight.h"
#include "../../pipeline/Pipeline.h"

#define ROBOT_SCENE_SPEED_FACTOR 1000

class RobotScene : public BaseScene {

private:

  static constexpr float shapeTransformSpeed = 1.0f * ROBOT_SCENE_SPEED_FACTOR;

  static constexpr float shapeRotationSpeed = 0.01f * ROBOT_SCENE_SPEED_FACTOR;

  static constexpr float shapeScaleSpeed = 0.1f * ROBOT_SCENE_SPEED_FACTOR;

  static constexpr float lightRotationSpeed = 0.01f * ROBOT_SCENE_SPEED_FACTOR;

public:

  RobotScene(OpenGL& gl);

  void update(double deltaTime) override;

  void render(double deltaTime) override;

private:

  std::unique_ptr<AmbientLight> ambientLight;

  std::unique_ptr<DirectionalLight> directionalLight;

  Camera cameraInstance;

  std::unique_ptr<Shape3d> shape;

  std::unique_ptr<ColorTexture> colorTexture;

  PipeLine pip;

  float shapeRotationX = 0.0f;

  float shapeRotationY = 0.0f;

  float shapeRotationZ = 0.0f;

  float lightRotationX = 0.0f;

  float lightRotationY = 0.0f;

  float lightRotationZ = 0.0f;

};

#endif // !RobotScene_Class
