#ifndef MonkeyScene_Class
#define MonkeyScene_Class

#include "../base_scene/BaseScene.h"
#include "../../open_gl/OpenGl.h"
#include "../../camera/Camera.h"
#include "../../texture/ColorTexture/ColorTexture.h"
#include "../../shaders/point_light/PointLight.h"
#include "../../pipeline/Pipeline.h"

class MonkeyScene : public BaseScene {

private:

  static constexpr float shapeTransformSpeed = 1.0f;

  static constexpr float shapeRotationSpeed = 0.01f;

  static constexpr float shapeScaleSpeed = 0.1f;

  static constexpr float lightTransformSpeed = 0.1f;

  static constexpr float cameraTransformSpeed = 0.2f;

  static constexpr float cameraRotationSpeed = 0.002f;

public:
  
  MonkeyScene(OpenGL& gl);

  void update(double deltaTime) override;

  void render(double deltaTime) override;

private:

  Camera camera;

  std::unique_ptr<Shape3d> monkey;

  std::unique_ptr<PointLight> pointLight;

  std::unique_ptr<AmbientLight> ambientLight;

  std::unique_ptr<ColorTexture> metalColor;

  float cameraTransformX = 0.0f;

  float cameraTransformY = 0.0f;

  float cameraTransformZ = 0.0f;

  float cameraRotationX = 0.0f;

  float cameraRotationY = 0.0f;

  float cameraRotationZ = 0.0f;

  PipeLine pip;

};

#endif // !MonkeyScene_Class