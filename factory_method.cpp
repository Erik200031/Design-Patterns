#include <iostream>
#include <string>

struct Table {
    virtual void add() const = 0;
    virtual ~Table() = default;
};

struct Classroom_Table : Table {
    void add()  const override {
        std::cout << "Classroom Table\n";
    }
};

struct Home_Table : Table {
    void add() const override {
        std::cout << "Home Table\n";
    }
};

struct Factory {
    //factory method
    static Table* create_Table (const std::string & type_table ) {
        if (type_table == "Classroom") {
            return new Classroom_Table;
        }
        else if (type_table == "Home") {
            return new Home_Table;
        }
        return nullptr;
    }
};

int main() {
    
    Table* table { Factory::create_Table("Classroom") };
    table->add();
    delete table;
    table = Factory::create_Table("Home");
    table->add();
    delete table;
}