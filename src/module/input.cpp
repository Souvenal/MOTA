#include "module/input.h"

std::unordered_map<Qt::Key, Input::State> Input::keyState;
std::vector<Qt::Key> Input::occupied;
std::vector<Qt::Key> Input::toRemove;

void Input::Update()
{
    for (auto &key : toRemove) {
        occupied.erase(std::remove(occupied.begin(), occupied.end(), key), occupied.end());
        // qDebug() << "occupied remove " << key;
    }
    toRemove.clear();
}

bool Input::GetKey(Qt::Key key)
{
    auto it = keyState.find(key);
    return it != keyState.end() && it->second == Held;
}

bool Input::GetKeyDown(Qt::Key key)
{for (const auto& occupiedKey : occupied) {
        if (occupiedKey == key) {
            toRemove.emplace_back(key);
            return true;
        }
    }
    return false;
}

bool Input::GetKeyUp(Qt::Key key)
{
    auto it = keyState.find(key);
    return it != keyState.end() && it->second == Up;
}

bool Input::GetKeyIdle(Qt::Key key)
{
    auto it = keyState.find(key);
    return it == keyState.end() || it->second == Idle;
}

void Input::SetKey(Qt::Key key)
{
    keyState[key] = Held;
}

void Input::SetKeyDown(Qt::Key key)
{
    keyState[key] = Down;
    if (find(occupied.begin(), occupied.end(), key) == occupied.end()) {
        occupied.emplace_back(key);
        // qDebug() << "occupied append " << key;
    }
}

void Input::SetKeyUp(Qt::Key key)
{
    keyState[key] = Up;
    occupied.erase(std::remove(occupied.begin(), occupied.end(), key), occupied.end());
}

void Input::SetKeyIdle()
{
    for (auto &pair : keyState) {
        Qt::Key key = pair.first;
        if (find(occupied.begin(), occupied.end(), key) == occupied.end()) {
            pair.second = Idle;
        }
    }
}
