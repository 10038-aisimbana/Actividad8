#include <emscripten.h>
#include <stdio.h>

// Función para imprimir en la página web usando JavaScript
EM_JS(void, print_to_html, (const char* str), {
    var output = document.getElementById('output');
    output.innerHTML += UTF8ToString(str) + '<br>';
});

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // Llama a la función de JavaScript para inicializar la salida en la página
    print_to_html("Secuencia de Fibonacci:");

    for (int i = 0; i < 10; ++i) {
        // Llama a la función de JavaScript para imprimir cada número en la página
        char buffer[50];
        sprintf(buffer, "%d", fibonacci(i));
        print_to_html(buffer);
    }

    return 0;
}
