#ifndef INPUT_H
#define INPUT_H

#include <QKeyEvent>
#include <unordered_map>

class Input: QObject
{
    Q_OBJECT

    enum State {Down, Held, Up, Idle};

    static std::unordered_map<Qt::Key, State> keyState;
    static std::vector<Qt::Key> occupied;
    static std::vector<Qt::Key> toRemove;

public slots:
    void Update();

public:

    static bool GetKey(Qt::Key key);
    static bool GetKeyDown(Qt::Key key);
    static bool GetKeyUp(Qt::Key key);
    static bool GetKeyIdle(Qt::Key key);

    void SetKey(Qt::Key key);
    void SetKeyDown(Qt::Key key);
    void SetKeyUp(Qt::Key key);
    void SetKeyIdle(); // reset
};


#endif // INPUT_H
