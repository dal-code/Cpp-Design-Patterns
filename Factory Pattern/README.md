## 简单工厂模式

+ 通过一个单独的工厂类来创建对象，而不是直接在客户端代码中实例化对象。在简单工厂模式中，工厂类根据客户端的请求创建相应的对象，并将其返回给客户端
  （返回的是一个对象指针）。

## 优点

+ 用工厂对象创建具体的对象，使对象的使用与对象的创建分离开
+ 工厂类包含必要的判断逻辑，可以决定在什么时候创建哪一个产品类的实例，客户端可以免除直接创建产品对象的责任，而仅仅“消费”
+ 产品类实现基本接口，客户针对抽象类进行编程，当需要扩展新产品类时，只要扩展一个具体产品类即可，无须修改任何客户端代码。

## 缺点

+ 由于工厂类集中了所有产品创建逻辑，一旦不能正常工作，整个系统都要受到影响。当增加新产品的时候，需要修改工厂类的判断逻辑，这违背了“开闭原则”。