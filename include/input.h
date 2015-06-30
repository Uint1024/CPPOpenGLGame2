enum class Key { Right, Down, Left, Up, Shoot, NumKeys };
enum class ControllerType { Keyboard, Mouse, Gamepad };
namespace Input{
  void init();
  void pollEvents(bool& runGame);
  bool isKeyDown(int scancode);

  bool playerIsKeyDown(int playerId, Key keyId);
}
