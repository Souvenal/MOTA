#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

class Behaviour
{
public:
    Behaviour();

    virtual void Start() = 0;

    virtual void Update() = 0;
};

#endif // BEHAVIOUR_H
