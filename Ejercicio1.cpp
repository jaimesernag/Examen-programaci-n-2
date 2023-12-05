#include <iostream>
#include <map>
#include <stdexcept>

class Variant {
    // Implementación de la clase Variant (se asume que ya existe)
};

class Environment {
private:
    std::map<std::string, Variant> symbolTable;

public:
    // Constructor por defecto
    Environment() = default;

    // Destructor (puede no ser necesario en este caso)
    ~Environment() = default;


    // ...
    Variant lookup(const char *string) {
        return Variant();
    }

    void insert(const char *string, Variant variant) {

    }
};
int symbolTable;
public:
// Método para insertar un nuevo símbolo en el entorno
void insert(const std::string& name, const Variant& value) {
    auto result = symbolTable.insert({name, value});
    if (!result.second) {
        throw std::runtime_error("Error: Symbol already exists in the environment.");
    }
}
// Método para buscar un símbolo en el entorno
Variant lookup(const std::string& name) const {
    auto it = symbolTable.find(name);
    if (it != symbolTable.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Error: Symbol not found in the environment.");
    }
}
public:
// Método para eliminar un símbolo del entorno
void remove(const std::string& name) {
    symbolTable.erase(name);
}

// Método para verificar si un símbolo existe en el entorno
bool exists(const std::string& name) const {
    return symbolTable.find(name) != symbolTable.end();
}
int main() {
    try {
        Environment env;

        // Insertar símbolos
        env.insert("player_health", Variant(100));
        env.insert("player_name", Variant("John Doe"));

        // Buscar y mostrar valores de símbolos
        std::cout << "Player Health: " << env.lookup("player_health").toString() << std::endl;

        // Intentar buscar un símbolo que no existe (debería lanzar una excepción)
        Variant weapon = env.lookup("weapon");  // Esto lanzará una excepción

        // Eliminar un símbolo
        env.remove("player_name");

        // Verificar si un símbolo existe
        if (env.exists("player_name")) {
            std::cout << "Player Name exists." << std::endl;
        } else {
            std::cout << "Player Name does not exist." << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
