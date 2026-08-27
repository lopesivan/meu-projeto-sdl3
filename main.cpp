#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
int main(int argc, char* argv[]) {
    // 1. Inicializa os subsistemas da SDL3 (Vídeo e Eventos)
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Erro ao inicializar a SDL3: " << SDL_GetError() << std::endl;
        return 1;
    }
    // 2. Cria a janela do aplicativo
    SDL_Window* window = SDL_CreateWindow(
        "Exemplo SDL3 + Conan", // Título
        800,                    // Largura
        600,                    // Altura
        SDL_WINDOW_RESIZABLE    // Flags
    );
    if (!window) {
        std::cerr << "Erro ao criar a janela: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    // 3. Cria o renderizador gráfico (aceleração por hardware)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "Erro ao criar o renderizador: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    // 4. Define a cor do fundo (RGBA: Azul escuro) e limpa a tela
    SDL_SetRenderDrawColor(renderer, 20, 35, 60, 255);
    SDL_RenderClear(renderer);
    // 5. Apresenta o resultado na tela
    SDL_RenderPresent(renderer);
    std::cout << "Janela aberta com sucesso! Fechando em 3 segundos..." << std::endl;
    SDL_Delay(3000); // Pausa de 3000 ms (3s)
    // 6. Libera os recursos alocados
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
