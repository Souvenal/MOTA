# MOTA

Unity-like 2D game engine built with c++ and Qt.

Along with a mini game MOTA as demo.

## 输入处理

## 物理模拟 (FixedUpdate)

对于一个自定义的 **`PhysicsSystem`**，一次 **`FixedUpdate`** 的更新流程主要分为以下几个阶段。这些阶段模拟 Unity 的物理系统运作顺序，同时根据实际需求进行调整和优化。

---

### **1. 预处理阶段**
在正式开始物理计算之前，需要准备所有相关数据，确保更新过程中有足够的信息：

1. **收集和初始化物理对象**：
   - 遍历场景中的物理相关物体（通常是带有 `Rigidbody` 或 `Collider` 组件的 `GameObject`）。
   - 将物理对象的当前状态（位置、速度等）存储为初始状态，供后续计算使用。

2. **缓存输入和外力**：
   - 收集并存储外力（如重力、风力）或玩家施加的力（如跳跃、推动等）。

---

### **2. 应用外力阶段**
在每个物体上应用外部作用力（如重力、用户输入的力、环境作用力等）以更新物体的运动状态。

#### 具体处理：
1. **计算合力**：
   - 将所有作用在刚体上的外力（如重力、风力、弹簧力）叠加，计算合力。

2. **更新速度**：
   - 根据牛顿第二定律 \( F = ma \)，计算加速度并更新物体的速度：
     $$\text{velocity} += \frac{\text{force}}{\text{mass}} \times \Delta t$$
   
3. **记录力的来源**：
   - 如果需要调试或分析，可以记录施加了哪些力。

#### 示例：
```cpp
void ApplyForces(Rigidbody& rb) {
    // 叠加外力
    Vector3 gravity = Vector3(0, -9.8f, 0) * rb.mass;
    rb.force += gravity + rb.externalForces;

    // 更新速度
    Vector3 acceleration = rb.force / rb.mass;
    rb.velocity += acceleration * fixedDeltaTime;

    // 清空外力
    rb.force = Vector3(0, 0, 0);
}
```

---

### **3. 碰撞检测阶段**
在所有刚体之间进行碰撞检测，确定是否发生碰撞以及碰撞点的位置和法向量。

#### 碰撞检测的常见方法：
1. **宽相位（Broad Phase）**：
   - 粗略筛选可能碰撞的物体对（如使用四叉树或包围盒进行快速检测）。
   - 减少需要精确检测的物体对数量。

2. **窄相位（Narrow Phase）**：
   - 对宽相位筛选出的物体对进行精确检测（如检测包围盒、凸多边形或点的接触情况）。
   - 计算碰撞点、法向量和碰撞深度。

#### 示例：
```cpp
void DetectCollisions() {
    for (auto& obj1 : sceneObjects) {
        for (auto& obj2 : sceneObjects) {
            if (obj1 != obj2 && CheckCollision(obj1.collider, obj2.collider)) {
                // 碰撞发生，存储碰撞信息
                CollisionInfo collision = ComputeCollisionInfo(obj1, obj2);
                collisionQueue.push(collision);
            }
        }
    }
}
```

---

### **4. 碰撞响应阶段**
处理碰撞检测的结果，调整刚体的速度和位置以确保物体不会穿透并正确响应碰撞。

#### 具体步骤：
1. **计算碰撞响应**：
   - 根据碰撞法向量和碰撞深度调整物体的位置，确保物体不重叠（位置修正）。
   - 使用动量守恒公式或弹性系数更新物体的速度：
     \[
     v_1' = v_1 - (1 + e) \cdot (v_1 \cdot n) \cdot n
     \]

2. **触发事件**：
   - 如果某些碰撞需要触发特定逻辑（如游戏事件），可以在此阶段通知相关系统。

#### 示例：
```cpp
void ResolveCollisions() {
    while (!collisionQueue.empty()) {
        CollisionInfo collision = collisionQueue.front();
        collisionQueue.pop();

        // 根据碰撞法向量调整速度和位置
        ApplyCollisionResponse(collision.obj1, collision.obj2, collision.normal, collision.depth);
    }
}
```

---

### **5. 更新位置阶段**
根据更新后的速度，计算物体在当前时间步的最终位置。

#### 示例：
```cpp
void UpdatePositions(Rigidbody& rb) {
    // 更新位置
    rb.position += rb.velocity * fixedDeltaTime;

    // 将位置同步到场景物体的 Transform
    rb.gameObject.transform.position = rb.position;
}
```

---

### **6. 后处理阶段**
在物理计算完成后执行的额外处理：

1. **触发回调事件**：
   - 触发 `OnCollisionEnter`、`OnCollisionStay`、`OnCollisionExit` 等物理事件。
   - 通知其他系统（如音效、粒子系统）进行额外的处理。

2. **清理和准备下一帧**：
   - 清空力缓存、碰撞队列等临时数据。
   - 准备好数据供下一帧使用。

---

### **完整的更新流程顺序**

1. **预处理阶段**：收集场景中的物理对象并初始化状态。
2. **应用外力**：根据外力和玩家输入更新物体的速度。
3. **碰撞检测**：检查并记录可能发生的碰撞。
4. **碰撞响应**：调整物体的速度和位置以响应碰撞。
5. **更新位置**：根据更新后的速度计算物体的新位置。
6. **后处理阶段**：触发物理相关事件并清理缓存。

---

### 示例代码概览

```cpp
void PhysicsSystem::FixedUpdate() {
    // 1. 预处理：收集物理对象
    CollectPhysicsObjects();

    // 2. 应用外力
    for (auto& rb : rigidbodies) {
        ApplyForces(rb);
    }

    // 3. 碰撞检测
    DetectCollisions();

    // 4. 碰撞响应
    ResolveCollisions();

    // 5. 更新位置
    for (auto& rb : rigidbodies) {
        UpdatePositions(rb);
    }

    // 6. 后处理
    TriggerPhysicsEvents();
    ClearTemporaryData();
}
```

---

### 总结
**`PhysicsSystem` 的核心更新流程**以物理规律为基础，包括预处理、外力应用、碰撞检测与响应、位置更新等阶段。它确保物理效果在每次 **`FixedUpdate`** 调用中都是准确和稳定的，同时与其他游戏逻辑（如输入处理、动画）无缝集成。

## Update 阶段

└─> 所有 GameObject 的 Update 方法

## LateUpdate 阶段

## 渲染阶段

├─> 渲染物体
├─> 计算光照和阴影

└─> 后处理效果

Reference[^1]

[^1]: Unity Documentation https://docs.unity.cn/cn/2021.3/ScriptReference/index.html