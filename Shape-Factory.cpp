/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
class Shape {
public:
    virtual void draw() const=0;
protected:
    Shape() {
        m_width = 6;
        m_height = 3;
    }
    int m_width;
    int m_height;
};

class Rectangle: public Shape {
public:
    virtual void draw() const override {
        for(int i=0;i<m_height;++i)
        {
            for(int j=0;j<m_width;++j) {
                if(i==0 || i == m_height - 1) {
                    cout<<((j==0 || j==m_width - 1) ? " " : "-");
                } else {
                    cout<<((j==0 || j==m_width - 1) ? "|" : " ");
                }
            }
            cout<<endl;
        }
    }

};

class Square: public Rectangle {
public:
    Square() {
        m_height = 4;
    }
};

class Triangle: public Shape {
public:
    virtual void draw() const override {
        for(int i=0;i<m_height;++i)
        {
            for(int j=0;j<m_width;++j) {
                if(i == m_height - 1) {
                    if(j==0) cout<<"/";
                    else if(j==m_width-1) cout<<"\\";
                    else cout<<"_";
                } else {
                    if(j==m_height-i-1) cout<<"/";
                    else if(j==m_height+i) cout<<"\\";
                    else cout<<" ";
                }
            }
            cout<<endl;
        }
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        if(shapeType=="Rectangle") return new Rectangle();
        if(shapeType=="Square") return new Square();
        if(shapeType=="Triangle") return new Triangle();
        return nullptr;
    }
};




