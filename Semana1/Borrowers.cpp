#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

// Estructura para representar un libro
struct Book {
    string title;
    string author;
    string sort_key; // Clave para ordenar: autor + " " + título

    // IMPORTANTE: NO necesitamos Book() si usamos insert/emplace.
    
    // Constructor que inicializa las propiedades y calcula la clave de ordenación
    Book(const string& t, const string& a) : title(t), author(a) {
        // La clave de ordenación es Autor, luego Título (como requiere el problema)
        sort_key = author + " " + title;
    }

    // Sobrecarga del operador < para usar en std::sort y std::upper_bound
    bool operator<(const Book& other) const {
        return sort_key < other.sort_key;
    }
};

// Mapa global para acceder rápidamente a todos los libros por su título
map<string, Book> library_stock;

// Vector de libros actualmente en el estante (debe estar ordenado)
vector<Book> on_shelf;

// Vector de libros devueltos que esperan ser colocados
vector<Book> returned_books;

// Función para parsear la línea de entrada del stock: "title" by author
void parse_stock_line(const string& line) {
    // ... (código de parsing, sin cambios)
    size_t start_title = line.find('"');
    size_t end_title = line.find('"', start_title + 1);

    if (start_title == string::npos || end_title == string::npos) return;

    string title = line.substr(start_title + 1, end_title - start_title - 1);

    size_t by_pos = line.find(" by ", end_title + 1);
    if (by_pos == string::npos) return;

    string author = line.substr(by_pos + 4);

    // 4. Crear el objeto Book
    Book new_book(title, author);
    
    // SOLUCIÓN AL ERROR: Usar insert para evitar llamar al constructor por defecto.
    // Esto es equivalente a library_stock.emplace(title, new_book);
    library_stock.insert({title, new_book}); 
    
    on_shelf.push_back(new_book);
}

void process_commands() {
    string line;
    while (getline(cin, line) && line != "END") {
        if (line.empty()) continue;

        stringstream ss(line);
        string command, title_with_quotes;
        ss >> command;

        // Extraer el título (todo lo que queda en la línea, incluyendo comillas)
        // Se asegura que sólo el título (sin comillas) sea extraído
        size_t title_start = line.find('"');
        size_t title_end = line.find('"', title_start + 1);
        if (title_start != string::npos && title_end != string::npos) {
            title_with_quotes = line.substr(title_start + 1, title_end - title_start - 1);
        }

        if (command == "BORROW") {
            // Eliminar el libro del estante
            auto it = remove_if(on_shelf.begin(), on_shelf.end(),
                                [&](const Book& b) { return b.title == title_with_quotes; });
            on_shelf.erase(it, on_shelf.end());
        } else if (command == "RETURN") {
            // Mover el libro al área de devueltos
            // Usar .at() o .find() es más seguro/eficiente que count() + [] si ya existe
            auto it_book = library_stock.find(title_with_quotes);
            if (it_book != library_stock.end()) {
                // it_book->second es el objeto Book
                returned_books.push_back(it_book->second);
            }
        } else if (command == "SHELVE") {
            // 1. Ordenar los libros devueltos por autor/título
            sort(returned_books.begin(), returned_books.end());

            // 2. Colocar los libros uno por uno en la posición correcta
            for (const auto& book_to_shelve : returned_books) {
                // std::upper_bound encuentra la posición correcta de inserción
                auto it_insert = upper_bound(on_shelf.begin(), on_shelf.end(), book_to_shelve);

                string instruction;
                if (it_insert == on_shelf.begin()) {
                    // El libro va al inicio
                    instruction = "Put \"" + book_to_shelve.title + "\" first";
                } else {
                    // El libro va después del que está en la posición anterior (it_insert - 1)
                    auto it_before = it_insert - 1;
                    instruction = "Put \"" + book_to_shelve.title + "\" after \"" + it_before->title + "\"";
                }

                // 3. Insertar el libro en el estante y mantener el orden
                on_shelf.insert(it_insert, book_to_shelve);

                // 4. Imprimir la instrucción
                cout << instruction << endl;
            }

            // 5. Limpiar la lista de devueltos
            returned_books.clear();

            // 6. Imprimir el terminador del bloque de salida
            cout << "END" << endl;
        }
    }
}

int main() {
    // Optimización de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    // Primera fase: Leer el stock de la biblioteca
    while (getline(cin, line) && line != "END") {
        if (!line.empty()) {
            parse_stock_line(line);
        }
    }

    // Asegurarse de que el estante inicial esté ordenado
    sort(on_shelf.begin(), on_shelf.end());

    // Segunda fase: Procesar comandos de BORROW, RETURN, y SHELVE
    process_commands();

    return 0;
}