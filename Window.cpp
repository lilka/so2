#include "Window.h"
#include <ncurses.h>

Window::Window() {
    initWindow();
}

Window::~Window() {
    endwin();    // zakończenie trybu curses
}

void Window::initWindow() {
    initscr();  // rozpoczęcie trybu curses
    noecho();   //wyłącz efekt echa
    curs_set(FALSE);    //wyłącz kursor
    clear();     //wyczysczenie ekranu
    refresh();  // wypisanie na rzeczywistym ekranie
    getmaxyx(stdscr, height, width);    //pobranie wielkosci okna
}

float Window::getHeight() {
    return height;
}

float Window::getWidth() {
    return width;
}
