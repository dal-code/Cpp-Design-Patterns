#include <iostream>
#include <vector>

// 命令接口
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// 接收者类
class Receiver {
public:
    void action() {
        std::cout << "Receiver: 执行操作" << std::endl;
    }

    void undoAction() {
        std::cout << "Receiver: 撤销操作" << std::endl;
    }
};

// 具体命令类
class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* rec) : receiver(rec) {}

    void execute() override {
        receiver->action();
    }

    void undo() override {
        receiver->undoAction();
    }
};

// 调用者类
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* cmd) {
        commands.push_back(cmd);
    }

    void executeCommands() {
        for (Command* cmd : commands) {
            cmd->execute();
        }
    }

    void undoCommands() {
        for (auto it = commands.rbegin(); it != commands.rend(); ++it) {
            (*it)->undo();
        }
    }
};

int main() {
    // 创建接收者对象
    Receiver* receiver = new Receiver();

    // 创建具体命令对象
    Command* command1 = new ConcreteCommand(receiver);
    Command* command2 = new ConcreteCommand(receiver);
    Command* command3 = new ConcreteCommand(receiver);

    // 创建调用者对象
    Invoker invoker;

    // 添加命令到调用者
    invoker.addCommand(command1);
    invoker.addCommand(command2);
    invoker.addCommand(command3);

    // 执行命令
    invoker.executeCommands();

    // 撤销命令
    invoker.undoCommands();

    // 释放内存
    delete command1;
    delete command2;
    delete command3;
    delete receiver;

    return 0;
}