#include <iostream>
#include <string>

struct Furniture
{
    virtual void add() const = 0;
    virtual ~Furniture() = default;
};

struct Table : Furniture {
    virtual void add() const = 0;
    virtual ~Table() {}
};

struct Chair : Furniture {
    virtual void add() const = 0;
    virtual ~Chair() = default;
};

struct Cheap_Chair : Chair {
    void add() const override {
        std::cout << "Cheap Chair\n";
    }
};

struct Expensive_Chair : Chair {
    void add() const override {
        std::cout << "Expensive Chair\n";
    }
};

struct Cheap_Table : Table {
    void add() const override {
        std::cout << "Cheap Table\n";
    }
};

struct Expensive_Table : Table {
    void add()  const override {
        std::cout << "Expensive Table\n";
    }
};

//abstract factory
struct Factory {
    virtual Furniture* create_furniture (const std::string & type_furniture) const = 0;
    virtual ~Factory() = default;
};

struct Cheap_Factory : Factory {
    Furniture* create_furniture (const std::string & type_furniture) const override {
        if (type_furniture == "Table") {
            return new Cheap_Table;
        }
        else if (type_furniture == "Chair") {
            return new Cheap_Chair;
        }
        return nullptr;
    }
};

struct Expensive_Factory : Factory {
    Furniture* create_furniture (const std::string & type_furniture) const override {
        if (type_furniture == "Table") {
            return new Expensive_Table;
        }
        else if (type_furniture == "Chair") {
            return new Expensive_Chair;
        }
        return nullptr;
    }
};

int main() {
    
    Factory* factory { new Expensive_Factory };
    Furniture* furniture { factory->create_furniture("Table") };
    furniture->add();
    delete furniture;
    furniture = factory->create_furniture("Chair");
    furniture->add();
    delete furniture;
    delete factory;
}