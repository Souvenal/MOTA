#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP

#include <unordered_map>
#include <typeindex>
#include <functional>
#include <any>

#include <QString>

// forward declaration
class Component;
class GameObject_Interface;

class ComponentFactory {
    using Creator = std::function<Component*(GameObject_Interface*, std::vector<std::any>&)>;

    // 用于存储类型索引到创建函数的映射
    std::unordered_map<std::type_index, Creator> creators;

public:
    // singleton
    static ComponentFactory& GetComponentFactory() {
        static ComponentFactory factory;
        return factory;
    }

    // 注册组件类型的创建函数，支持任意参数
    template <typename T, typename... Args>
    void RegisterComponent();

    // 创建组件实例，支持完美参数转发
    template <typename T, typename... Args>
    T* Create(GameObject_Interface* owner, Args&&... args);

private:
    // 从 void* 参数列表中提取真实参数，并调用组件构造函数
    template <typename T, typename... Args, size_t... Is>
    static T* InvokeConstructor(GameObject_Interface* owner, std::vector<std::any>& args, std::index_sequence<Is...>
    );

    // 工厂内部通用创建函数，支持从参数列表调用组件构造函数
    template <typename T, typename... Args>
    static T* CreateFromArgs(GameObject_Interface* owner, std::vector<std::any>& args);
};

template <typename T, typename... Args>
void ComponentFactory::RegisterComponent()
{
    std::type_index type = std::type_index(typeid(T));
    creators[type] = [](GameObject_Interface* owner, std::vector<std::any> &args) -> Component*
    {
        return CreateFromArgs<T, Args...>(owner, args);
    };
}

template <typename T, typename... Args>
T* ComponentFactory::Create(GameObject_Interface* owner, Args&&... args)
{
    std::type_index type = std::type_index(typeid(T));
    auto it = creators.find(type);
    if (it != creators.end()) {
        std::vector<std::any> argList = {std::any(std::forward<Args>(args))...};
        // return dynamic_cast<T *>(it->second(owner, std::forward<Args>(args)...));
        return dynamic_cast<T*>(it->second(owner, argList));
    }
    return nullptr;
}

#include <QDebug>

// 从 void* 参数列表中提取真实参数，并调用组件构造函数
template <typename T, typename... Args, size_t... Is>
T* ComponentFactory::InvokeConstructor(GameObject_Interface *owner, std::vector<std::any> &args, std::index_sequence<Is...>)
{
    return new T(owner, std::any_cast<Args>(args[Is])...);
    // qDebug() << "Argument size: " << args.size();
    // return nullptr;
}

// 工厂内部通用创建函数，支持从参数列表调用组件构造函数
template <typename T, typename... Args>
T* ComponentFactory::CreateFromArgs(GameObject_Interface* owner, std::vector<std::any>& args)
{
    return InvokeConstructor<T, Args...>(
        owner, args, std::index_sequence_for<Args...>{});
}



#endif // COMPONENTFACTORY_HPP
