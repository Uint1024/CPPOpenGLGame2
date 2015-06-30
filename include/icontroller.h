#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController
{
  private:
    
  public:
    virtual ~IController();
    virtual void update() =  0;
};


class IControllerBonus : public IController {
  public:
    IControllerBonus();
    virtual void update();
};
#endif
