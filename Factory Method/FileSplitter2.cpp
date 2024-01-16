//基类，产品
class ISplitter{
public:
    virtual void split() = 0;
    virtual ~ISplitter(){}
};

//工厂基类
class SplitterFactory{
public:
    virtual ISplitter* CreateSplitter()=0;
    virtual ~SplitterFactory(){}
};

//具体类，继承基类,重载虚函数
class BinarySplitter : public ISplitter{
public:
    void split() override {

    }
    
};

class TxtSplitter: public ISplitter{
public:
    void split() override {

    }
    
};

class PictureSplitter: public ISplitter{
public:
    void split() override {

    }

};

class VideoSplitter: public ISplitter{
public:
    void split() override {

    }
};

//具体工厂
class BinarySplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new BinarySplitter();
    }
};

class TxtSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new TxtSplitter();
    }
};

class PictureSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new PictureSplitter();
    }
};

class VideoSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new VideoSplitter();
    }
};

