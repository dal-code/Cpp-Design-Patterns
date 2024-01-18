## 工厂方法模式

![](https://img-blog.csdnimg.cn/20190623171420456.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlc3Ricm9va2xpdQ==,size_16,color_FFFFFF,t_70)

+ 具体工厂类 和 具体产品类之间的关系是依赖，具体工厂类需要依赖 具体产品类 来创建对象。

+ 工厂方法模式是一种创建型设计模式，它定义了一个用于创建对象的接口，但将具体的创建逻辑延迟到子类中。每个子类都可以实现工厂方法来创建特定类型的对象。